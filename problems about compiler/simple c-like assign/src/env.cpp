#include "SCA.h"


int Memory::put(char *value, int size)
{
    int addr = end;
    for (int i = 0; i < size; ++i) mem[end++] = *value++;
    if (size % 4) for (int i = 0; i < 4 - size % 4; ++i) mem[end++] = 0;
    return addr;
}

char *Memory::read(int addr)
{
    return &mem[addr];
}

void Memory::write(int addr, char *value, int size)
{
    while (size--) mem[addr++] = *value++;
}

void Memory::print()
{
    for (int i = 0; i < end; i += 4)
    {
        printf("0x%08X  %02X %02X %02X %02X\n", i, mem[i], mem[i + 1], mem[i + 2], mem[i + 3]);
    }
}


static string _translate2string(char *src, string type)
{
    string res;
    switch (type[0])
    {
    case 'c':
        res += *src;
        break;
    case 's':
    {
        auto val = *(short*)src;
        res = to_string(val);
    }
        break;
    case 'P':
    case 'i':
    {
        auto val = *(int*)src;
        res = to_string(val);
    }
        break;
    case 'l':
    {
        auto val = *(long*)src;
        res = to_string(val);
    }
        break;
    case 'f':
    {
        auto val = *(float*)src;
        res = to_string(val);
    }
        break;
    case 'd':
    {
        auto val = *(double*)src;
        res = to_string(val);
    }
        break;
    case 'F':
        res = src;
        break;
    case 'A':
    {
        auto ypos = type.find("y"), _pos = type.find("_");
        auto n = stoi(type.substr(ypos + 1, _pos - ypos - 1));
        int *temp = (int*)src;
        res += "{";
        while (n--) res += to_string(*temp++) + ((n == 0) ? "" : ", ");
        res += "}";
    }
        break;
    default:
        break;
    }
    return res;
}

static void _translate2char(char *dist, string type, Value val)
{
    const char *_val;
    switch (type[0])
    {
    case 'c':
        *dist = val.val[0];
        break;
    case 's':
    {
        short _short = (short)stoi(val.val);
        _val = (char *)&_short;
        for (int i = 0; i < (int)sizeof(short); ++i) *dist++ = *_val++;
    }
        break;
    case 'P':
    case 'i':
    {
        int _int = stoi(val.val);
        _val = (char *)&_int;
        for (int i = 0; i < (int)sizeof(int); ++i) *dist++ = *_val++;
    }
        break;
    case 'l':
    {
        long _long = stol(val.val);
        _val = (char *)&_long;
        for (int i = 0; i < (int)sizeof(long); ++i) *dist++ = *_val++;
    }
        break;
    case 'f':
    {
        float _float = stof(val.val);
        _val = (char *)&_float;
        for (int i = 0; i < (int)sizeof(float); ++i) *dist++ = *_val++;
    }
        break;
    case 'd':
    {
        double _double = stod(val.val);
        _val = (char *)&_double;
        for (int i = 0; i < (int)sizeof(double); ++i) *dist++ = *_val++;
    }
        break;
    case 'F':
        _val = val.val.c_str();
        for (int i = 0; i < val.size + 1; ++i) *dist++ = *_val++;
        break;
    case 'A':
    {
        auto ypos = type.find("y"), _pos = type.find("_");
        auto _type = type.substr(_pos + 1, 1);
        auto n = stoi(type.substr(ypos + 1, _pos - ypos - 1));
        char temp[8];
        for (int _ = 0; _ < n; ++_)
        {
            auto pos = val.val.find(" ");
            _translate2char(temp, _type, Value{ 0, val.val.substr(0, pos) });
            for (char i = 0, *_temp = temp; i < val.size / n; ++i) *dist++ = *_temp++;
            val.val = val.val.substr(pos + 1);
        }
    }
        break;
    default:
        break;
    }
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


string SymbolTable::get_value(string name)
{
    auto i = _find(names, name);
    auto val = memory.read(addrs[i]);
    if (i == -1) return "";
    else return _translate2string(val, types[i]);
}

void SymbolTable::put(string name, string type, int size)   // 声明
{
    char value[100] = { 0 };
    names.push_back(name);
    addrs.push_back(memory.put(value, size));
    types.push_back(type);
    sizes.push_back(size);
}

void SymbolTable::put(string name, string type, Value val)  // 初始化
{
    char value[100];
    _translate2char(value, type, val);

    names.push_back(name);
    addrs.push_back(memory.put(value, val.size));
    types.push_back(type);
    sizes.push_back(val.size);
}

void SymbolTable::assign(string name, string val)           // 赋值
{
    auto i = _find(names, name);

    char value[100];
    _translate2char(value, types[i], Value{ sizes[i], symtable.exist(val) ? symtable.get_value(val) : val });

    memory.write(addrs[i], value, sizes[i]);
}


string SymbolTable::get_name(int addr)
{
    auto i = _find(addrs, addr);
    return (i == -1) ? "" : names[i];
}

int SymbolTable::get_addr(string name)
{
    auto i = _find(names, name);
    return (i == -1) ? -1 : addrs[i];
}

string SymbolTable::get_type(string name)
{
    auto i = _find(types, name);
    return (i == -1) ? "" : types[i];
}

int SymbolTable::get_size(string name)
{
    auto i = _find(names, name);
    return (i == -1) ? - 1 : sizes[i];
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
        printf("%-16s| 0x%08X%-6s| %-16d| %s\n", names[i].c_str(), addrs[i], "", sizes[i], types[i].c_str());
    }
}


// Global variable
Memory memory;
SymbolTable symtable;