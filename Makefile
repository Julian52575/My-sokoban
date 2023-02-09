##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## it makes files
##

SRC		=	$(wildcard src/*/*/*/*.c src/*/*/*.c src/*/*.c src/*.c)

SRC2	=	$(wildcard lib/my/*.c)

OBJ = $(SRC:.c=.o) $(SRC2:.c=.o)

CFLAGS += -Wall -g -Wextra -I./lib/includes -L./lib/my -lmy

NAME = "my_sokoban"

$(NAME): $(OBJ)
	gcc -g -o $(NAME) $(OBJ) -lncurses

all:     $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:     fclean all

.PHONY: all clean fclean re
