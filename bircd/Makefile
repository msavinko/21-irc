
SRCS =	main.c \
		init_env.c \
		clean_fd.c \
		get_opt.c \
		x.c \
		main_loop.c \
		init_fd.c \
		do_select.c \
		check_fd.c \
		srv_create.c \
		srv_accept.c \
		client_read.c \
		client_write.c

OBJS = ${SRCS:.c=.o}

NAME = bircd

CFLAGS = -I. -g3 -Wall -Werror

CC = gcc
RM = rm -f

${NAME}: ${OBJS}
	${CC} -o ${NAME} ${OBJS}

all: ${NAME}

clean:
	${RM} ${OBJS} *~ #*#

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all logo clean fclean re
