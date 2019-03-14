#include <string>
#include <iostream>

#include <cstdio>
#include <cstring>

#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <netinet/in.h>

#include "calculate.hpp"


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
    socklen_t sin_size = sizeof(sockaddr_in);

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8000);

    auto listen_fd = socket(AF_INET, SOCK_STREAM, 0), maxfd = 10;
    if (listen_fd < 0) PERROR("socekt error");

    if (bind(listen_fd, (sockaddr*)&server_addr, sizeof(sockaddr)) < 0) PERROR("bind error");
    if (listen(listen_fd, 5) < 0) PERROR("listen error");

    fd_set fds; 
    FD_ZERO(&fds);
    FD_SET(listen_fd, &fds);

    while (true)
    {
        auto tmp_fds = fds;
        auto cnt = select(maxfd, &tmp_fds, nullptr, nullptr, nullptr);

        for (int fd = 0, len; fd < maxfd; ++fd)
        {
            if (!FD_ISSET(fd, &tmp_fds)) continue;
            else if (cnt-- <= 0) break;

            if (fd == listen_fd) 
            {
                auto conn_fd = accept(listen_fd, (sockaddr*)&client_addr, &sin_size), len = 0;
                if (conn_fd < 0) PERROR("accept error");
                maxfd = max(maxfd, conn_fd) + 1;
                FD_SET(conn_fd, &fds);
            }
            else 
            {
                string expr;

                while ((len = recv(fd, buffer, BUFSIZE, 0)) > 0)
                {
                    expr += buffer;
                    memset(buffer, 0, BUFSIZE);
                    if (len < BUFSIZE) break;
                }

                if (expr == "exit" || len <= 0)
                {
                    close(fd);
                    FD_CLR(fd, &fds);
                    continue;
                }

                auto res = calculate(expr);
                if (send(fd, res.c_str(), res.size(), 0) < 0) PERROR("send error");

                printf("received expression : %s\n"
                       "    from     client : %s\n"
                       "     and     return : %s\n\n", expr.c_str(), inet_ntoa(client_addr.sin_addr), res.c_str());
            }
        }
    }

    close(listen_fd);

    return 0;
}