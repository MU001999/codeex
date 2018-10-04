#ifndef OBJECT_H
#define OBJECT_H

struct Object
{
    enum class TYPE
    {
        NORMAL,
        TYPE,
    } ob_type;

    virtual ~Object() {}
    virtual void show() = 0;
};


struct BaseObject : Object
{
    long long_val;
    double float_val;
    ::std::string str_val;
    int type;

    BaseObject(long val) : long_val(val), type(0) {}
    BaseObject(double val) : float_val(val), type(1) {}
    BaseObject(::std::string val) : str_val(val), type(2) {}

    virtual void show();
};


struct PointerObject : Object
{
    ::std::shared_ptr<Object> ob;

    PointerObject(::std::shared_ptr<Object> ob) : ob(ob) {}

    virtual void show();
};

struct ReferenceObject : Object
{
    ::std::shared_ptr<Object> ob;

    ReferenceObject(::std::shared_ptr<Object> ob) : ob(ob) {}

    virtual void show();
};

struct ArrayObject : Object
{
    int n;
    ::std::shared_ptr<Object> ob;

    ArrayObject(int n, ::std::shared_ptr<Object> ob) : n(n), ob(ob) {}

    virtual void show();
};

struct FunctionObject : Object
{
    ::std::shared_ptr<Object> return_type;
    ::std::vector<::std::shared_ptr<Object>> param_types;

    FunctionObject(::std::shared_ptr<Object> return_type, ::std::vector<::std::shared_ptr<Object>> param_types) : return_type(return_type), param_types(param_types) {}

    virtual void show();
};


struct VarObject : Object
{
    ::std::string name;
    ::std::shared_ptr<Object> type;
    ::std::shared_ptr<Object> val;

    VarObject(::std::string name, ::std::shared_ptr<Object> type) : name(name), type(type), val(nullptr) {}
    void assign(::std::shared_ptr<Object>);

    virtual void show();
};

struct TypeObject : Object
{
    TOKEN type;

    TypeObject(TOKEN type) : type(type) { ob_type = TYPE::TYPE; }

    virtual void show();
};

#endif // OBJECT_H