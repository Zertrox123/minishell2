##
## EPITECH PROJECT, 2024
## omar
## File description:
## Makefile
##

SRC	=	lib/miniprintf.c	\
		lib/my_put_nbr.c	\
		lib/my_str_things.c	\
		lib/my_strncmp.c	\
		lib/my_strtoc.c	\
		lib/my_strcat.c	\
		lib/my_strdup.c	\
		src/get_things.c	\
		src/exec_bin.c	\
		src/cd.c	\
		src/parsing_env.c	\
		src/func_annex.c	\
		main.c	\

OBJ = $(SRC:.c=.o)

CFLAGS = -g3

NAME = mysh

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ) $(CFLAGS) -g3

all: $(NAME)

tests_run:
	gcc -o unit_tests $(SRC) $(TST) --coverage -lcriterion
	./unit_tests

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f *.gcno
	rm -f *.gcda
	rm -f unit_tests

re: fclean all
