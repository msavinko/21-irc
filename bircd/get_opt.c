#include <stdio.h>
#include <stdlib.h>
#include "bircd.h"

void get_opt(t_env *e, int argc, char **argv)
{
	if (argc != 2)
	{
		fprintf(stderr, USAGE, argv[0]);
		exit(1);
	}
	e->port = atoi(argv[1]);
}

