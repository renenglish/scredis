#ifndef __SCREDSI__H
#define __SCREDSI__H
//// about network
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
//// about IO & Util
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <util/die.h>

typedef struct redis_client{
	int fd;
}redis_client;
typedef struct redis_response{
	char * data;
	int len;
}redis_response;
// public api
redis_client * redis_connect(const char*host,const char *port);
redis_response * redis_command(redis_client *c,const char*fmt,...);
void free_client();
void free_response();


#endif
