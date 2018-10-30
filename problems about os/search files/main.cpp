#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <string>
#include <unordered_set>
#include "sc.hpp"


using namespace std;


void create_source();


int main(int argc, char *argv[])
{
    srand(time(NULL));

    create_source();

    return 0;
}


static string _gen_random_string(char base, int scope, int len)
{
    string res;
    while (len--) res += base + (rand() % scope);
    return res;
}


void create_source()
{
    auto err = mkdir("./sources", 0744);
    if (err)
    {
        printf("error at creating sources/\n");
        exit(0);
    }

    unordered_set<string> exits_names;
    while (exits_names.size() < 1000)
    {
        auto name = _gen_random_string('A', 26, 5);
        if (!exits_names.count(name))
        {
            exits_names.insert(name);
            auto fpath = "./sources/" + name;
            auto fd = open(fpath.c_str(), O_WRONLY | O_CREAT | O_TRUNC, 0744);
            if (fd == -1)
            {
                printf("error at creating a file in sources/\n");
                exit(0);
            }
            auto content = _gen_random_string('a', 26, 100);
            if (write(fd, content.c_str(), content.size() + 1) == -1)
            {
                printf("error at writing to an open file in sources/\n");
                exit(0);
            }
            close(fd);
        }
    }
}