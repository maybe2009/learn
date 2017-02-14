#include "SimpleServerApi.h"

#include <string.h>
#include <stdio.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>

ret_make_server make_server(const char* ip, uint16_t port, int backlog)
{
    ret_make_server ret = { 0, -100 };

    ret.fd = socket(AF_INET, SOCK_STREAM, 0);
    if (ret.fd == -1)
    {
        printf("%s: create socket fail: %s\n", __func__, strerror(errno));
        ret.error = -1;
        return ret;
    }

    struct sockaddr_in address;
    memset(&address, 0, sizeof(address));
    address.sin_family = AF_INET;
    address.sin_port = htons(port);

    if (inet_pton(AF_INET, ip, &(address.sin_addr)) != 1)
    {
        printf("%s:parse ip:%s error:%s\n", __func__, ip, strerror(errno));
        ret.error = -2;
        return ret;
    }

    //address.sin_addr.s_addr = htonl(INADDR_ANY);
    if (bind(ret.fd, (struct sockaddr*)&address, sizeof(address)) != 0)
    {
        printf("%s:bind fail:%s\n", __func__, strerror(errno));
        ret.error = -3;
        return ret;
    }

    ret.error = 0;
    return ret;
}
