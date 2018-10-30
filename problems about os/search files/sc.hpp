#ifndef SC_HPP
#define SC_HPP

#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <string>

#define PEXIT   {\
                    printf("error in sc.hpp at line: %d\n", __LINE__);\
                    exit(0);\
                }


void func1(const char *path)
{
    auto fd = open(path, O_RDWR);

    std::string _path = path;
    printf("path: %s\n", _path.substr(0, _path.rfind('/')).c_str());
    printf("filename: %s\n", _path.substr(_path.rfind('/') + 1).c_str());

    char buf[4096];
    if (read(fd, buf, 4096) == -1) PEXIT;
    printf("content: %s\n", buf);

    auto err = ftruncate(fd, 80);
    if (err) PEXIT;

    memset(buf, 0, sizeof(buf));
    err = lseek(fd, 0, SEEK_SET);
    if (err || read(fd, buf, 4096) == -1) PEXIT;
    printf("new content: %s\n", buf);

    std::string new_name;
    for (int i = 0; i < 8; ++i) new_name += '0' + (char)(rand() % 10);
    printf("new name: %s\n\n", new_name.c_str());

    close(fd);

    auto new_path = _path.substr(0, _path.rfind('/') + 1) + new_name;
    err = rename(path, new_path.c_str());
    if (err) PEXIT;
}


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
