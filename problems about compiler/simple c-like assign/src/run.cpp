#include "SCA.h"


using OBJECT = ::std::shared_ptr<Object>;
using ENV = ::std::shared_ptr<Env>;


void Env::put(::std::shared_ptr<VarObject> ob)
{
    mem.push_back(ob);
    if (ob->size > 4)
        mem.insert(mem.end(), ob->size / 4 - ((ob->size % 4) == 0), nullptr);
}

::std::shared_ptr<VarObject> Env::get(::std::string name)
{
    for (auto ob : mem)
    {
        if (ob->name == name) return ob;
    }
    printf("no var names %s\n", name.c_str());
    return nullptr;
}


void Env::print_table()
{
    printf("%-16s| %-16s| %-16s| %s\n", "name", "address", "size", "type");
    for (size_t i = 0; i < mem.size(); ++i)
    {
        auto ob = mem[i];
        if (ob)
        {
            printf("%-16s| %-16p| %-16u| ", ob->name.c_str(), (void*)256 + i*4, static_cast<unsigned int>(ob->size));
            ob->type->show();
            printf("\n");
        }
    }
}


OBJECT LongExpr::run(ENV &top)
{
    return ::std::make_shared<BaseObject>(value);
}


OBJECT FloatExpr::run(ENV &top)
{
    return ::std::make_shared<BaseObject>(value);
}


OBJECT StringExpr::run(ENV &top)
{
    return ::std::make_shared<BaseObject>(value);
}


OBJECT IdentifierExpr::run(ENV &top)
{
    return top->get(name);
}


OBJECT VarExpr::run(ENV &top)
{
    return ::std::make_shared<VarObject>(name->name, type->run(top));
}


OBJECT UnaryExpr::run(ENV &top)
{
    return expression->run(top);
}


OBJECT ListExpr::run(ENV &top)
{
    return nullptr;
}


OBJECT TypeExpr::run(ENV &top)
{
    return ::std::make_shared<TypeObject>(type);
}


OBJECT PointerExpr::run(ENV &top)
{
    return ::std::make_shared<PointerObject>(type->run(top));
}


OBJECT ReferenceExpr::run(ENV &top)
{
    return ::std::make_shared<ReferenceObject>(type->run(top));
}


OBJECT ArrayExpr::run(ENV &top)
{
    return ::std::make_shared<ArrayObject>(n, type->run(top));
}


OBJECT FunctionExpr::run(ENV &top)
{
    ::std::vector<::std::shared_ptr<Object>> types;
    auto type = return_type->run(top);
    for (auto p : param_types) types.push_back(p->run(top));
    auto ob = ::std::make_shared<FunctionObject>(type, types);
    ob->size = top->line.size();
    ob->decl = top->line;
    return ob;
}


OBJECT ExprStmt::run(ENV &top)
{
    auto ob = expression->run(top);
    return ob;
}


OBJECT DeclStmt::run(ENV &top)
{
    auto var = ::std::dynamic_pointer_cast<VarObject>(declarator->run(top));
    if (initializer) 
        var->assign(initializer->run(top));
    top->put(var);
    return nullptr;
}