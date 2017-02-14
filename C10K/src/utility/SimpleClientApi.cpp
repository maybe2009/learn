//
// Created by DW on 2017/1/22.
//

#include "SimpleClientApi.h"

#include <stdint.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

ret_make_client make_client(const char* ip, uint16_t port)
{
    ret_make_client ret;
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

    if (inet_pton(AF_INET, ip, &address.sin_addr) != 1)
    {
        printf("%s:parse ip:%s error:%s\n", __func__, ip, strerror(errno));
        ret.error = -2;
        return ret;
    }
    
	if (connect(ret.fd, (sockaddr*)&address, sizeof(address)) != 0)
	{
		printf("%s:connect fail:%s\n", __func__, strerror(errno));
		ret.error = -3;
		return ret;
	}

    ret.error = 0;
    return ret;
}