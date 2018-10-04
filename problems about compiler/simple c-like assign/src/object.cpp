#include "SCA.h"


void BaseObject::show() 
{
    switch (type)
    {
    case 0:
        printf("%ld", long_val);
        break;
    case 1:
        printf("%lf", float_val);
        break;
    case 2:
        ::std::cout << str_val;
        break;
    default:
        break;
    }
}

void PointerObject::show()
{
    ob->show();
    printf(" *");
}

void ReferenceObject::show()
{
    ob->show();
    printf(" &");
}

void ArrayObject::show()
{
    if (n > 0) printf("Array(%d, ", n);
    else printf("Array(, ");
    ob->show();
    printf(")");
}

void FunctionObject::show()
{
    printf("Function(");
    if (param_types.size())
    {
        printf("(");
        for (size_t i = 0; i < param_types.size(); ++i)
        {
            if (i) printf(", ");
            param_types[i]->show();
        }
        printf(")");
    }
    printf(", (");
    return_type->show();
    printf("))");

    //printf("%s", decl.c_str());
}

void VarObject::assign(::std::shared_ptr<Object> ob)
{
    val = ob;
}

void VarObject::show()
{
    if (val)
    {
        if (type->ob_type == TYPE::TYPE)
        {
            auto _val = ::std::dynamic_pointer_cast<BaseObject>(val);
            switch (::std::dynamic_pointer_cast<TypeObject>(type)->type)
            {
            case TOKEN::TCHAR:
                printf("%c", static_cast<int>(_val->long_val));
                break;
            case TOKEN::TSHORT:
            case TOKEN::TINT:
            case TOKEN::TLONG:
                printf("%ld", _val->long_val);
                break;
            case TOKEN::TFLOAT:
            case TOKEN::TDOUBLE:
                printf("%lf", _val->float_val);
            default:
                break;
            }
        }
        else val->show();
    }
    else type->show();
}

void TypeObject::show()
{
    switch (type)
    {
    case TOKEN::TVOID:
        printf("void");
        break;
    case TOKEN::TCHAR:
        printf("char");
        break;
    case TOKEN::TSHORT:
        printf("short");
        break;
    case TOKEN::TINT:
        printf("int");
        break;
    case TOKEN::TLONG:
        printf("long");
        break;
    case TOKEN::TFLOAT:
        printf("float");
        break;
    case TOKEN::TDOUBLE:
        printf("double");
        break;
    default:
        break;
    }
}