#ifndef SIMPLE_SERVER_API_INCLUDE
#define SIMPLE_SERVER_API_INCLUDE
#include <stdint.h>

typedef struct {
	int fd;
	int error;
} ret_make_server;

ret_make_server make_server(const char* ip, uint16_t port, int backlog = 5);

#endif 
