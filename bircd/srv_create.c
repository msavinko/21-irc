#include "bircd.h"
#include <netinet/in.h>
#include <netdb.h>
#include <stdlib.h>

void srv_create(t_env *e, int port)
{
	struct protoent *pe = (struct protoent*)Xv(NULL, getprotobyname("tcp"), "getprotobyname");
	int s = X(-1, socket(PF_INET, SOCK_STREAM, pe->p_proto), "socket");
	struct sockaddr_in sin;
	
	sin.sin_family = AF_INET;
	sin.sin_addr.s_addr = INADDR_ANY;
	sin.sin_port = htons(port);
	X(-1, bind(s, (struct sockaddr*)&sin, sizeof(sin)), "bind");
	X(-1, listen(s, 42), "listen");
	e->fds[s].type = FD_SERV;
	e->fds[s].fct_read = srv_accept;
}
