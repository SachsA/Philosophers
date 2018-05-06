##
## EPITECH PROJECT, 2018
## Philosopher
## File description:
## Makefile
##

GCC		=	gcc

MK		=	make

RUN		=	tests_run

RM		=	rm -rf

SRC		=	./src/initialization.c	\
			./src/philosopher.c	\
			./src/main_core.c	\
			./src/main.c		\
			./src/job.c

OBJ		=	$(SRC:.c=.o)

CFLAGS		+=	-W -Wall -Wextra -Wshadow
CFLAGS		+=	-I ./inc/

LDFLAGS		+=	-L ./lib/ -lriceferee -lpthread

NAME		=	./philo

ifeq ($(DEBUG), TRUE)
	CFLAGS += -g
else
	CFLAGS += -Werror
endif

ifeq ($(BONUS), TRUE)
	CFLAGS += -D__BONUS__
endif

all:			$(NAME)

$(NAME):		$(OBJ)
			$(GCC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
			$(RM) $(OBJ)
			$(MK) clean -C ./tests/

fclean:			clean
			$(RM) $(NAME)
			$(MK) fclean -C ./tests/

tests_run:
			$(MK) $(RUN) -C ./tests/

re:			fclean all

.PHONY:			all clean fclean re tests_run
