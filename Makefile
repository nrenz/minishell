NAME = minishell
LIB_F = libft
LIB = libft.a
SRC = src
OBJ = obj
INC = inc
CFLAGS = -Wall -Wextra -Werror -g -I$(INC)
RM = rm -rf
CC = gcc
SRCS =	src/main.c\
		src/pwd.c\
		src/envp.c\
		src/expand.c\
		src/lexer/lexer.c\
		src/lexer/lists.c\
		src/lexer/lists_del.c\
		src/built/ft_cd.c\
		src/built/ft_pwd.c\
		src/built/ft_env.c\
		src/built/ft_echo.c\
		src/built/ft_exit.c\
		src/built/ft_unset.c\
		src/built/ft_export.c\
		src/built/built_utils.c\
		src/built/built_utils2.c\
		src/built/built_lexer_list.c\
		src/parser/parser.c\
		src/parser/pipex.c\
		src/utils/errors_utils.c\
		src/utils/free_utils.c\
		src/utils/quotes_utils.c\
		src/utils/utils.c\
		src/utils/clean_up.c\

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIB_F)/$(LIB)
	@$(CC) $(CFLAGS) $(OBJS) $(LIB_F)/$(LIB) -o $(NAME) -lreadline

$(LIB_F)/$(LIB):
	@make -C $(LIB_F)
	@echo "libft is done!"

clean:
	@$(RM) $(OBJS)
	rm -rf obj 
	@echo "successfuly cleaned"

fclean: clean
	@$(RM) $(NAME)
	@make fclean -C $(LIB_F)
	@echo "executable removed successfuly"

leaks:
	make
	leaks --atExit -- ./minishell

re: fclean all