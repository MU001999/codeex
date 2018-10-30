#ifndef SC_HPP
#define SC_HPP

#include <dirent.h>
#include <string.h>
#include <string>

#define PEXIT   {\
                    printf("error in sc.hpp at line: %d\n", __LINE__);\
                    exit(0);\
                }


void func1(const char *path);


void func2(const char *path);


void func3(const char *path);


void findanel(const char *dirpath, char c, void(*func)(const char*))
{
    auto dirptr = opendir(dirpath);
    if (dirptr == NULL) PEXIT;

    struct dirent *entry = NULL;
    while ((entry = readdir(dirptr)))
    {
        if (entry->d_type == DT_REG)
        {
            std::string name = entry->d_name;
            if (name.find(c) != std::string::npos)
            {
                auto path = std::string(dirpath) + '/' + name;
                func(path.c_str());
            }
        }
        else if (entry->d_type == DT_DIR)
        {
            if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0)
            {
                auto path = std::string(dirpath) + '/' + std::string(entry->d_name);
                findanel(path.c_str(), c, func);
            }
        }
    }

    closedir(dirptr);
}


#undef PEXIT

#endif // !SC_HPP
