#include "SCA.h"


void eval(string line)
{
    Parser parser;
    auto decl_type = parser.parse(line);

    if (parser.identifier.size())
    {
        symtable.put(parser.identifier, decl_type, parser.value);
    }
    else if (parser.value.val.size())
    {
        if (symtable.exist(parser.value.val))
        {
            cout << symtable.get(parser.value.val).val << endl;
        }
        else
        {
            cout << parser.value.val << endl;
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

        eval(line);
    }
    return 0;
}
