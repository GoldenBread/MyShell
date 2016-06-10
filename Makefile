##
## Makefile for 42sh in /home/thierry/Rendu/PSU_2015_42sh
## 
## Made by Thierry LEVISSE
## Login   <thierry@epitech.net>
## 
## Started on Tue May 31 02:54:43 2016 Thierry LEVISSE
## Last update Fri Jun 10 02:32:55 2016 Thierry LEVISSE
##

NAME	=	mysh

SRC	=	src/main.c \
		src/cmd_exec.c \
		src/get_redir.c \
		src/sweep_out.c \
		src/separator.c \
		src/built_in/env/get_prompt.c \
		src/built_in/env/default_path.c \
		src/built_in/env/print_env.c \
		src/built_in/my_exit.c \
		src/built_in/my_exit_tools.c \
		src/built_in/init_pwd.c \
		src/built_in/cd.c \
		src/built_in/env/get_var_env.c \
		src/built_in/echo/echo.c \
		src/built_in/echo/epur_quote.c \
		src/built_in/echo/my_quote_to_wordtab.c \
		src/built_in/env/find_env.c \
		src/built_in/env/get_env.c \
		src/built_in/env/modif_env.c \
		src/built_in/env/my_built_env.c \
		src/built_in/env/my_unsetenv.c \
		src/built_in/env/check_char_setenv.c \
		src/built_in/built.c \
		src/built_in/echo/echo_loop.c \
		src/parsing/init_tree.c \
		src/parsing/str_to_wordtab.c \
		src/parsing/epur_token.c \
		src/parsing/space_token.c \
		src/parsing/check_token.c \
		src/parsing/basic_tree.c \
		src/parsing/get_next_line.c \
		src/parsing/get_next_line_tools.c \
		src/parsing/set_tree.c \
		src/parsing/free_tree.c \
		src/basic_tools/init_tabptr.c \
		src/basic_tools/free_misc.c \
		src/basic_tools/realloc.c \
		src/basic_tools/xmalloc.c \
		src/basic_tools/string_get_w_delay.c \
		src/darray_tools/darray_malloc.c \
		src/darray_tools/free_darray.c \
		src/darray_tools/realloc_d.c \
		src/darray_tools/darray_dup.c \
		src/string/strcmp.c \
		src/string/bzero.c \
		src/string/putchar.c \
		src/string/putstr.c \
		src/string/strcpy.c \
		src/string/strdup.c \
		src/string/strlen.c \
		src/string/strcat.c \
		src/display/disp_darray.c \
		src/display/disp_tree_cmd.c \
		src/errors/errors.c \
		src/execution/exec_simple.c \
		src/execution/pipe.c \
		src/execution/pipe_tools.c \
		src/execution/redir.c \
		src/execution/find_and_search.c \
		src/errors/signal.c \
		src/errors/check_syscall.c \
		src/errors/fd_error.c \
		src/parsing/ambig_redir.c \
		src/parsing/ambi_redir.c \
		src/parsing/check_redir.c

OBJ	=	$(SRC:.c=.o)

CC	=	gcc

RM	=	rm -f

CFLAGS	=	-W -Wextra -Wall -I./includes/

all: 		$(NAME)

$(NAME): 	$(OBJ)
		$(CC) $(OBJ) -o $(NAME)

clean:
		$(RM) $(OBJ)

fclean: 	clean
		$(RM) $(NAME)

re: 		fclean all

debug: 		CFLAGS += -g -ggdb3
debug: 		re
