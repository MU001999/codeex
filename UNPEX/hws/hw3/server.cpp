#include <string>
#include <iostream>

#include <cstdio>
#include <cstring>

#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>


#define PERROR(message) { \
                            perror(message); \
                            return 1; \
                        }
#define BUFSIZE 4096


using namespace std;


int main()
{
    char buffer[BUFSIZE] = {0};

    sockaddr_in server_addr, client_addr;

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8000);

    auto listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_fd < 0) PERROR("socekt error");

    if (bind(listen_fd, (sockaddr*)&server_addr, sizeof(sockaddr)) < 0) PERROR("bind error");
    if (listen(listen_fd, 5) < 0) PERROR("listen error");

    socklen_t sin_size = sizeof(sockaddr_in);

    while (true)
    {
        auto conn_fd = accept(listen_fd, (sockaddr*)&client_addr, &sin_size), len = 0;
        if (conn_fd < 0) PERROR("accept error");

        if (fork() == 0)
        {
            close(listen_fd);

            read(conn_fd, buffer, BUFSIZE);
            if (strcmp("exit", buffer) == 0) return 0;

            printf("target filename: %s\n", buffer);

            int fd = open(buffer, O_RDONLY);
            if (fd < 0) PERROR("file open error");

            while (true)
            {
                len = read(fd, buffer, BUFSIZE);
                if (write(conn_fd, buffer, len) < 0) PERROR("send error"); 
                if (len < BUFSIZE) break;
            }

            close(fd);
            close(conn_fd);
            return 0;
        }

        close(conn_fd);
    }

    close(listen_fd);

    return 0;
}