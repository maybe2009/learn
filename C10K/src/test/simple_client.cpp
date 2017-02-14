#include "SimpleClientApi.h"

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#include <arpa/inet.h>

int main(int argc, char* argv[])
{
    if (argc < 3)
    {
        printf("%s:argument not enough(%d)\n", __func__, argc);
        return -1;
    }

    ret_make_client ret = make_client(argv[1], atoi(argv[2]));

    printf("%s:ret %d %d\n", __func__, ret.fd, ret.error);

    return 0;
}