#ifndef BIRCD_H_
#define BIRCD_H_

#include <sys/select.h>

#define FD_FREE 0
#define FD_SERV 1
#define FD_CLIENT 2
#define BUF_SIZE 4096
#define MAX(a,b) ((a > b) ? a : b)
#define X(err,res,str) (x_int(err,res,str,__FILE__,__LINE__))
#define Xv(err,res,str) (x_void(err,res,str,__FILE__,__LINE__))
#define USAGE "Usage: %s port\n"

typedef struct s_fd
{
	int type;
	void (*fct_write)();
	void (*fct_read)();
	char buf_write[BUF_SIZE + 1];
	char buf_read[BUF_SIZE + 1];
} t_fd;

typedef struct s_env
{
	t_fd *fds;
	int maxfd;
	int max;
	int r;
	int port;
	fd_set fd_write;
	fd_set fd_read;
} t_env;

void main_loop(t_env *e);
void client_read(t_env *e, int cs);
void get_opt(t_env *e, int ac, char **av);
void srv_create(t_env *e, int port);
void init_env(t_env *e);
void *x_void(void *err, void *res, char *str, char *file, int line);
void srv_accept(t_env *e, int s);
int x_int(int err, int res, char *str, char *file, int line);
void do_select(t_env *e);
void client_write(t_env *e, int cs);
void clean_fd(t_fd *fd);
void init_fd(t_env *e);
void check_fd(t_env *e);

#endif
