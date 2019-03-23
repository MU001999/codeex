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
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_addr.sin_port = htons(8000);

    auto conn_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (conn_fd < 0) PERROR("socket error");

    if (connect(conn_fd, (sockaddr*)&server_addr, sizeof(sockaddr)) < 0) PERROR("connect error");

    printf("connected to server\n");
    printf("please input target filename or exit:\n");

    string filename;
    getline(cin, filename);

    if (send(conn_fd, filename.c_str(), filename.size() + 1, 0) < 0) PERROR("send error");

    if (filename == "exit") return 0;

    int fd = open(("dow_" + filename).c_str(), O_WRONLY | O_CREAT), len;
    if (fd < 0) PERROR("file open error\n");

    while (true)
    {
        len = read(conn_fd, buffer, BUFSIZE);
        write(fd, buffer, len);
        if (len < BUFSIZE) break;
    }

    close(fd);
    close(conn_fd);

    return 0;
}