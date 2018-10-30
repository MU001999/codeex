#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <string.h>
#include <string>
#include <unordered_set>
#include "sc.hpp"

#define PEXIT   {\
                    printf("error at line: %d\n", __LINE__);\
                    exit(0);\
                }


using namespace std;


void create_sources();
void create_content();
void copy_files_from_sources2content();
void delete_dir(const char *path);


int main(int argc, char *argv[])
{
    srand(time(NULL));

    create_sources();
    create_content();
    copy_files_from_sources2content();

    // for test

    printf("Operation 1:\n\n");
    findanel("./content", 'A', func1);

    printf("\nOperation 2:\n\n");
    findanel("./content", 'B', func2);

    // printf("\nOperation 3:\n\n");
    // findanel("./content", 'C', func3);

    delete_dir("./sources");

    return 0;
}


string _gen_random_string(char base, int scope, int len)
{
    string res;
    while (len--) res += base + (char)(rand() % scope);
    return res;
}


void create_sources()
{
    if (mkdir("./sources", 0755)) PEXIT;

    unordered_set<string> exits_names;
    while (exits_names.size() < 1000)
    {
        auto name = _gen_random_string('A', 26, 5);
        if (!exits_names.count(name))
        {
            exits_names.insert(name);
            auto fpath = "./sources/" + name;
            auto fd = open(fpath.c_str(), O_WRONLY | O_CREAT | O_TRUNC, 0755);
            if (fd == -1) PEXIT;

            auto content = _gen_random_string('a', 26, 100);
            if (write(fd, content.c_str(), content.size() + 1) == -1) PEXIT

            close(fd);
        }
    }
}


void create_content()
{
    if (mkdir("./content", 0755)) PEXIT;

    for (char n1 = 'A'; n1 <= 'Z'; ++n1)
    {
        auto path = string("./content/") + n1;
        if (mkdir(path.c_str(), 0755)) PEXIT;

        for (char n2 = 'a'; n2 <= 'z'; ++n2)
        {
            auto _path = path + string("/") + n2;
            if (mkdir(_path.c_str(), 0755)) PEXIT;
        }
    }
}


string _gen_dest(string src)
{
    string res = "./content/";

    auto fd = open(src.c_str(), O_RDONLY);
    if (fd == -1) PEXIT;

    char buf[1];
    if (read(fd, buf, 1) == -1) PEXIT;

    close(fd);

    res += src[src.size() - 5]; res += '/';
    res += buf[0]; res += '/';
    res += src.substr(src.size() - 5, 5);

    return res;
}


void _copy(string src, string dest)
{
    auto fd4src = open(src.c_str(), O_RDONLY), fd4dest = open(dest.c_str(), O_WRONLY | O_CREAT | O_TRUNC, 0755), len = 0;
    if (fd4src == -1 || fd4dest == -1) PEXIT;

    char buf[4096];
    while ((len = read(fd4src, buf, 4096)))
    {
        if (len == -1) PEXIT;
        write(fd4dest, buf, len);
    }

    close(fd4src);
    close(fd4dest);
}


void copy_files_from_sources2content()
{
    string path = "./sources/";

    auto dirptr = opendir(path.c_str());
    if (dirptr == NULL) PEXIT;

    struct dirent *entry = NULL;
    while ((entry = readdir(dirptr)))
    {
        if (entry->d_type == DT_REG)
        {
            auto src = path + entry->d_name;
            _copy(src, _gen_dest(src));
        }
    }

    closedir(dirptr);
}


void delete_dir(const char *path)
{
    auto dirptr = opendir(path);
    if (dirptr == NULL) PEXIT;

    struct dirent *entry = NULL;
    while ((entry = readdir(dirptr)))
    {
        if (entry->d_type == DT_REG)
        {
            auto src = string(path) + "/" + string(entry->d_name);
            if (remove(src.c_str())) PEXIT;
        }
        else if (entry->d_type == DT_DIR)
        {
            if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0)
            {
                auto _path = std::string(path) + '/' + std::string(entry->d_name);
                delete_dir(_path.c_str());
            }
        }
    }

    closedir(dirptr);
    rmdir(path);
}