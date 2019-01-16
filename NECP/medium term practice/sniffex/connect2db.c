#include <stdio.h>
#include <string.h>
#include <mysql/mysql.h>

struct Request
{
    int requestid;
    char *clientip;
    char *host;
    char **keys;
    char **values;
};


int insert2db(struct Request *request)
{

    MYSQL mysql;

    MYSQL_RES *rea;
    MYSQL_ROW row;

    int flag;

    char query[4096];

    mysql_init(&mysql);
    if (!mysql_real_connect(&mysql, "localhost", "mysql", "mysql", "pcaps", 0, NULL, 0))
    {
        printf("connect failed\n");
        return -1;
    }

    sprintf(query, "insert into request (requestid, clientip, host) values (%d, '%s', '%s')", request->requestid, request->clientip, request->host);
    if (mysql_real_query(&mysql, query, (unsigned int)strlen(query)))
    {
        printf("insert into request failed\n");
        return -1;
    }


    char **key = request->keys, **value = request->values;
    for (; *key != NULL && *value != NULL; ++key, ++value)
    {
        sprintf(query, "insert into header (requestid, header_key, header_value) values (%d, '%s', '%s')", request->requestid, *key, *value);
        if (mysql_real_query(&mysql, query, (unsigned int)strlen(query))) return -1;
    }

    mysql_close(&mysql);

    return 0;
}

/*
int main(int argc, char **argv)
{
    int requestid = 1;
    char clientip[] = "118.228.173.70";
    char host[] = "www.baidu.com";
    char *keys[] = {
        "host",
        "testkey",
        NULL
    };
    char *values[] = {
        "www.baidu.com",
        "testvalue",
        NULL
    };

    struct Request request = {
        requestid,
        clientip,
        host,
        keys,
        values
    };

    insert2db(&request);

    return 0;
}
*/