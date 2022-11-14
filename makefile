# ----------------------------------------Name
NAME = minishell

# ----------------------------------------FILES
FILES_SRCS =	main.c \
				enomem.c \
				error_msg.c \
				executor.c \
				executor_utils.c \
				cmd_finder.c \
				io_redirector.c \
				heredoc.c \
				hd_utils.c \
				ft_echo.c \
				ft_exit.c \
				ft_env.c \
				ft_pwd.c \
				ft_cd.c \
				ft_unset.c \
				signals.c \
				ft_export.c \
				ft_export_print.c \
				lexer.c \
				lexer_token.c \
				lexer_token_utils.c \
				lexer_token_del.c \
				lexer_token_print.c \
				free_lexer.c \
				parser.c \
				parser_utils.c \
				parse_io.c \
				parse_io_utils.c \
				parse_hd_dlm.c \
				parse_cmd.c \
				parse_cmd_utils.c \
				parse_str.c \
				parse_quote.c \
				parse_dquote.c \
				parse_expand.c \
				free_parser.c \
				environment.c \
				environment_get.c \
				environment_add.c \
				environment_unset.c \
				environment_shlvl.c \
				environment_utils.c \

FILES_OBJS = $(FILES_SRCS:.c=.o)

# ----------------------------------------Directories
DIR_SRCS = ./src/
DIR_OBJS = ./obj/
DIR_LIBFT = ./src/libft

vpath %.c $(DIR_SRCS) $(DIR_OBJS)
vpath %.c $(DIR_SRCS)lexer/ $(DIR_OBJS)
vpath %.c $(DIR_SRCS)parser/ $(DIR_OBJS)
vpath %.c $(DIR_SRCS)executor/ $(DIR_OBJS)
vpath %.c $(DIR_SRCS)builtins/ $(DIR_OBJS)
vpath %.c $(DIR_SRCS)environment/ $(DIR_OBJS)
vpath %.c $(DIR_SRCS)heredoc/ $(DIR_OBJS)
vpath %.c $(DIR_SRCS)signals/ $(DIR_OBJS)


# ----------------------------------------Sources
SRCS = $(FILES_SRCS:%=$(DIR_SRCS)%)

# ----------------------------------------Objects
OBJS = $(FILES_OBJS:%=$(DIR_OBJS)%)

# ----------------------------------------Flags
CC = gcc
# CFLAGS = -Wall -Wextra -Werror
INC = -Iinc -I$(DIR_LIBFT)

# ----------------------------------------Libraries
LIBFT = $(DIR_LIBFT)/libft.a

# ----------------------------------------Debug
ifdef WITH_ADDRESS
CFLAGS += -g -fsanitize=address
endif


# ----------------------------------------Making
all: $(NAME)

$(NAME): $(DIR_OBJS) $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L $(HOME)/.brew/opt/readline/lib -lreadline $(INC) $(LIBFT)

$(DIR_OBJS)%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@  -I $(HOME)/.brew/opt/readline/include $(INC)

$(DIR_OBJS):
	mkdir -p $@

$(LIBFT):
	make -C $(DIR_LIBFT)

# ----------------------------------------Debug
address:
	$(MAKE) re WITH_ADDRESS=1

# ----------------------------------------Cleaning
clean:
	make -C $(DIR_LIBFT) clean
	rm -f $(OBJS)

fclean: clean
	make -C $(DIR_LIBFT) fclean
	rm -f $(NAME)
	rm -rf hd_files

re: fclean all

.PHONY: all clean fclean re