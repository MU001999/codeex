#include "SCA.h"


void Interpreter::run()
{
    while (!::std::cin.eof())
    {
        ::std::cout << ">> ";
        ::std::string line;
        ::std::getline(::std::cin, line);

        if (line.empty()) continue;
        else if (line == "pt")
        {
            top->print_table();
            continue;
        }
        else if (line == "pm")
        {
            top->print_memory();
            continue;
        }

        auto node = parser.getNode(line);
        auto obj = node ? node->run(top) : nullptr;
        if (obj)
        {
            obj->show();
            printf("\n");
        }
    }
}