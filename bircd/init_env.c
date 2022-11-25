
#include <stdlib.h>
#include <sys/resource.h>
#include "bircd.h"

void init_env(t_env *e)
{
	int i = 0;
	struct rlimit rlp;

	X(-1, getrlimit(RLIMIT_NOFILE, &rlp), "getrlimit");
	e->maxfd = rlp.rlim_cur;
	e->fds = (t_fd*)Xv(NULL, malloc(sizeof(*e->fds) * e->maxfd), "malloc");
	while (i < e->maxfd)
		clean_fd(&e->fds[i++]);
}
