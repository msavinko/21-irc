#include "bircd.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

void *x_void(void *err, void *res, char *str, char *file, int line)
{
	if(res == err)
	{
		fprintf(stderr, "%s error (%s, %d): %s\n", 
			str, file, line, strerror(errno));
		exit(1);
	}
	return res;
}

int x_int(int err, int res, char *str, char *file, int line)
{
	if(res == err)
	{
		fprintf(stderr, "%s error (%s, %d): %s\n", 
			str, file, line, strerror(errno));
		exit(1);
	} 
	return res;
}
