#include "SimpleServerApi.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <errno.h>

#include <arpa/inet.h>


int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        printf("%s:argc not enough(%d)\n", __func__, argc);
        return -1;
    }

    ret_make_server ret = make_server(argv[1], atoi(argv[2]));
    int l = listen(ret.fd, 5);

    struct sockaddr_in peer;
    
    size_t len = sizeof(peer);
    int connfd = accept(ret.fd, (struct sockaddr*)&peer, (socklen_t*)&len);

    char buf[INET_ADDRSTRLEN];
    memset(buf, 0, INET_ADDRSTRLEN);
    if (inet_ntop(AF_INET, &peer.sin_addr, buf, INET_ADDRSTRLEN) == NULL)
    {
        printf("%s:inet_ntop fail:%s\n", __func__, strerror(errno));
    }
    else
    {
        printf("%s:client ip:%s port:%d\n", __func__, buf, peer.sin_port);
    }

    printf("%s ret %d %d %d %d \n", __func__, ret.fd, ret.error, l, connfd);
    return 0;
}
