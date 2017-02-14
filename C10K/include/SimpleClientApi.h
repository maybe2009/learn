//
// Created by DW on 2017/1/22.
//

#ifndef C10K_PROBLEM_SIMPLECLIENTAPI_H
#define C10K_PROBLEM_SIMPLECLIENTAPI_H

#include <netinet/in.h>

typedef struct 
{
    int fd;
    int error;
} ret_make_client;

ret_make_client make_client(const char* ip, uint16_t port);

#endif //C10K_PROBLEM_SIMPLECLIENTAPI_H
