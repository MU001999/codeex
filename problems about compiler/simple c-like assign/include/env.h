#ifndef ENV_H
#define ENV_H


struct Value
{
    int size;
    string val;
};


struct Memory
{
    vector<Value> mem;

    int put(Value);
    Value get(int);
    void write(int, Value);
};


struct SymbolTable
{
    vector<string> names;
    vector<int>    addrs;
    vector<string> types;

    Value get(string);
    int get_addr(string);
    string get_name(int);
    void put(string, string, Value);
    bool exist(string);

    void print();
};


extern Memory memory;
extern SymbolTable symtable;


#endif // ENV_H