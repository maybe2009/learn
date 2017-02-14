#include "SimpleServerApi.h"

#include <stdio.h>
#include <stdlib.h>

int main(int argc , const char* argv[])
{
	ret_make_server ret = make_server(argv[1], atoi(argv[2]));
	if (ret.error != 0)
	{
		printf("make_server with error:%d\n", ret.error);
		return -1;
	}
	return 0;
}