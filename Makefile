NAME = irc_serv

DIR_SRCS = srcs
DIR_HEADERS = includes
DIR_OBJS = objs
DIR_BOT = bot

SRCS = 	main.cpp \
		Chat.cpp \
		Client.cpp \
		Hash.cpp \
		History.cpp \
		Message.cpp \
		Server.cpp \
		UserInfo.cpp \
		utils.cpp

PATH_SRCS = $(addprefix $(DIR_SRCS)/, $(SRCS))

HEADERS = 	Chat.hpp \
			Client.hpp \
			Hash.hpp \
			History.hpp \
			Message.hpp \
			Server.hpp \
			UserInfo.hpp \
			utils.hpp

PATH_HEADERS = $(addprefix $(DIR_HEADERS)/, $(HEADERS))

OBJS = $(patsubst %.cpp, %.o, $(SRCS))
PATH_OBJS = $(addprefix $(DIR_OBJS)/, $(OBJS))

CC = clang++
RM = rm -rf
FLAGS = -Wall -Wextra -Werror -std=c++98 -g

all: $(NAME)

$(NAME): mkdir_obj $(PATH_OBJS)
	$(CC) $(FLAGS) $(PATH_OBJS) -o $@

$(DIR_OBJS)/%.o: $(DIR_SRCS)/%.cpp $(PATH_HEADERS) Makefile
	$(CC) $(FLAGS) -I $(DIR_HEADERS) -c $< -o $@

mkdir_obj:
	mkdir -p $(DIR_OBJS)

bot:
	make -C $(DIR_BOT)

clean:
	$(RM) $(DIR_OBJS)
	make -C $(DIR_BOT) fclean

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all logo clean fclean re mkdir_obj bot