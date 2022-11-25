NAME = irc_bot

SRCS =	main.cpp \
		Bot.cpp utils.cpp \
		Request.cpp

HEADERS =	Bot.hpp \
			utils.hpp \
			Request.hpp

DIR_OBJS = obj

OBJS = $(patsubst %.cpp, %.o, $(SRCS))
PATH_OBJS = $(addprefix $(DIR_OBJS)/, $(OBJS))

CC = clang++
RM = rm -rf
FLAGS = -Wall -Wextra -Werror -std=c++98 -g

all: $(NAME)

$(NAME): mkdir_obj $(PATH_OBJS)
	$(CC) $(FLAGS) $(PATH_OBJS) -o $@

$(DIR_OBJS)/%.o: %.cpp $(PATH_HEADERS) Makefile
	$(CC) $(FLAGS) -c $< -o $@

mkdir_obj:
	mkdir -p $(DIR_OBJS)

clean:
	$(RM) $(DIR_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all logo clean fclean re mkdir_obj
