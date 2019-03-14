#include <string>
#include <iostream>

#include <cstdio>
#include <cstring>

#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>


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
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_addr.sin_port = htons(8000);

    auto conn_fd = socket(AF_INET, SOCK_STREAM, 0), len = 0;
    if (conn_fd < 0) PERROR("socket error");

    if (connect(conn_fd, (sockaddr*)&server_addr, sizeof(sockaddr)) < 0) PERROR("connect error");

    printf("connected to server\n");

    while (true)
    {
        printf("\nplease input expr or exit:\n");

        string expr, res;
        getline(cin, expr);

        if (send(conn_fd, expr.c_str(), expr.size(), 0) < 0) PERROR("send error");

        if (expr == "exit") break;

        while ((len = recv(conn_fd, buffer, BUFSIZE, 0)) > 0)
        {
            res += buffer;
            memset(buffer, 0, BUFSIZE);
            if (len < BUFSIZE) break;
        }

        printf("result: %s\n", res.c_str());
    }

    close(conn_fd);

    return 0;
}