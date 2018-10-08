#ifndef ENV_H
#define ENV_H


struct Value
{
    int size;
    string val;
};


struct Memory
{
    int end;
    char mem[1000];

    int put(char*, int);
    char *read(int);
    void write(int, char *, int);

    void print();
};


struct SymbolTable
{
    vector<string> names;
    vector<int>    addrs;
    vector<string> types;
    vector<int>    sizes;

    string get_value(string);
    void   put(string, string, int);
    void   put(string, string, Value);
    void   assign(string, string);

    string get_name(int);
    int    get_addr(string);
    string get_type(string);
    int    get_size(string);

    bool exist(string);

    void print();
};


extern Memory memory;
extern SymbolTable symtable;


#endif // ENV_H