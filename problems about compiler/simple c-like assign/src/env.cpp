#include "SCA.h"


int Memory::put(Value val)
{
    auto addr = mem.size();
    mem.push_back(val);
    if (val.size > 4)
    {
        mem.insert(mem.end(), val.size / 4 - ((val.size % 4) == 0), Value{});
    }
    return addr * 4;
}

Value Memory::get(int addr)
{
    return mem[addr / 4];
}

void Memory::write(int addr, Value val)
{
    mem[addr / 4] = val;
}


template <typename T>
static int _find(vector<T> &values, T &value)
{
    for (size_t i = 0; i < values.size(); ++i)
    {
        if (values[i] == value)
        {
            return i;
        }
    }
    return -1;
}

Value SymbolTable::get(string name)
{
    auto i = _find(names, name);
    return (i == -1) ? Value{} : memory.get(addrs[i]);
}

int SymbolTable::get_addr(string name)
{
    auto i = _find(names, name);
    return (i == -1) ? -1 : addrs[i];
}

string SymbolTable::get_name(int addr)
{
    auto i = _find(addrs, addr);
    return (i == -1) ? "" : names[i];
}

void SymbolTable::put(string name, string type, Value val)
{
    auto i = _find(names, name);
    if (i == -1)
    {
        names.push_back(name);
        addrs.push_back(memory.put(val));
        types.push_back(type);
    }
    else if (type.size())
    {
        cout << "Variable already exists" << endl;
    }
    else
    {
        memory.write(addrs[i], val);
    }
}

bool SymbolTable::exist(string name)
{
    return _find(names, name) != -1;
}

void SymbolTable::print()
{
    printf("%-16s| %-16s| %-16s| %s\n", "name", "address", "size", "type");
    
    for (size_t i = 0; i < names.size(); ++i)
    {
        printf("%-16s| 0x%08X%-6s| %-16d| %s\n", names[i].c_str(), addrs[i], "", memory.get(addrs[i]).size, types[i].c_str());
    }
}


Memory memory;
SymbolTable symtable;