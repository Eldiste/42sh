##
## EPITECH PROJECT, 2022
## MAKEFIL
## File description:
## MAKEFIL
##

SRC	=	$(shell find . -type f -name "*.c")

OBJ	=	$(SRC:.c=.o)

NAME =	42sh

CFLAGS = -g3 -I./include

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -W -Wextra -Wall -o $(NAME) $(OBJ)

clean:
	rm -f $(shell find . -type f -name '*.o')

fclean:	clean
	rm -f $(NAME)

re:	fclean all

auteur:
	echo $(USER) > auteur
