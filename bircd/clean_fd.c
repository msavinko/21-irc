
#include <stdlib.h>
#include "bircd.h"

void clean_fd(t_fd *fd)
{
	fd->fct_read = NULL;
	fd->fct_write = NULL;
	fd->type = FD_FREE;
}
