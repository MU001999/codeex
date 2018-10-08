#include "SCA.h"


void eval(string line)
{
    Parser parser;
    auto decl_type = parser.parse(line);
    auto value = parser.value.val;

    if (parser.identifier.size())                           // ��������Ϊ��ֵ����
    {
        if (symtable.exist(parser.identifier))              // ���ű��д��ڸñ�����������ֵ
        {
            if (decl_type.empty()) symtable.assign(parser.identifier, value);
            else cout << "Variable already exists" << endl;
        }
        else if (decl_type.size())                          // ���ű��в����ڸñ�����������ʼ��
        {
            if (value.empty())                              // ��������ֵ��ֻ������
            {
                symtable.put(parser.identifier, decl_type, parser.value.size);
            }
            else if (symtable.exist(value))                 // ������ֵ������ֵΪ������
            {
                symtable.put(parser.identifier, decl_type, Value{ symtable.get_size(value), symtable.get_value(value) });
            }
            else                                            // ������ֵ������ֵΪ����
            {
                symtable.put(parser.identifier, decl_type, parser.value);
            }
        }
        else                                                // ��ֵʱ��ֵ������
        {
            cout << "Variable does not exist" << endl;
        }
    }
    else if (parser.value.val.size())                       // ֻ��⵽��ֵ����ֱ�������ֵ
    {
        if (symtable.exist(value))                          // ��ֵΪ������
        {
            cout << symtable.get_value(value) << endl;
        }
        else                                                // ��ֵΪ����
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
