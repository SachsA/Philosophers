##
## EPITECH PROJECT, 2018
## Philosopher
## File description:
## Makefile tests
##

CC	=	gcc

RM	=	rm -rf

MD	=	mkdir tmp

SRC	=	../src/initialization.c	\
		../src/philosopher.c	\
		../src/main_core.c	\
		../src/job.c		\
		./tests_init_args.c	\
		./tests_main_core.c	\
		./tests_init_philo.c

CFLAGS	+=	-DUNIT_TEST
CFLAGS	+=	-I ../inc/
CFLAGS	+=	-W -Wall -Wextra -Werror
LDFLAGS	+=	-L ../lib/ -lriceferee -lpthread
TUFLAGS	+=	-coverage -lcriterion

NAME	=	unit_test

OBJ	=	$(SRC:.c=.o)

MV	=	mv ../src/*.o ./tmp

$(NAME):	$(OBJ)
		$(CC) $(CFLAGS) $(TUFLAGS) $(LDFLAGS) -o $(NAME) $(OBJ)
		$(MD)
		$(MV)

all:		$(NAME)

tests_run:	clean all
		./$(NAME)

clean:
		$(RM) $(OBJ) ./tmp

fclean:		clean
		$(RM) $(NAME) ./tmp

re:		fclean all

.PHONY:		all clean fclean re tests_run
