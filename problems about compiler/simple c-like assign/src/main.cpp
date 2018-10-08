#include "SCA.h"


void eval(string line)
{
    Parser parser;
    auto decl_type = parser.parse(line);
    auto value = parser.value.val;

    if (parser.identifier.size())                           // 变量名作为左值出现
    {
        if (symtable.exist(parser.identifier))              // 符号表中存在该变量名，即赋值
        {
            if (decl_type.empty()) symtable.assign(parser.identifier, value);
            else cout << "Variable already exists" << endl;
        }
        else if (decl_type.size())                          // 符号表中不存在该变量名，即初始化
        {
            if (value.empty())                              // 不存在右值，只是声明
            {
                symtable.put(parser.identifier, decl_type, parser.value.size);
            }
            else if (symtable.exist(value))                 // 存在右值，且右值为变量名
            {
                symtable.put(parser.identifier, decl_type, Value{ symtable.get_size(value), symtable.get_value(value) });
            }
            else                                            // 存在右值，且右值为常量
            {
                symtable.put(parser.identifier, decl_type, parser.value);
            }
        }
        else                                                // 赋值时左值不存在
        {
            cout << "Variable does not exist" << endl;
        }
    }
    else if (parser.value.val.size())                       // 只检测到右值，则直接输出右值
    {
        if (symtable.exist(value))                          // 右值为变量名
        {
            cout << symtable.get_value(value) << endl;
        }
        else                                                // 右值为常量
        {
            cout << value << endl;
        }
    }
}


int main(int argc, char *argv[])
{
    while (!cin.eof())
    {
        cout << ">> ";
        string line;
        getline(cin, line);

        if (line.empty())
        {
            continue;
        }
        else if (line == "pt")
        {
            symtable.print();
            continue;
        }
        else if (line == "pm")
        {
            memory.print();
            continue;
        }

        eval(line);
    }
    return 0;
}
