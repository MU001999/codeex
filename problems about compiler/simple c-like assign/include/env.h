#ifndef ENV_H
#define ENV_H

struct Env
{
    ::std::vector<::std::shared_ptr<VarObject>> mem;

    void put(::std::shared_ptr<VarObject>);
    ::std::shared_ptr<VarObject> get(::std::string);

    Env() {}

    void print_table();
    void print_memory();
};

#endif // ENV_H
