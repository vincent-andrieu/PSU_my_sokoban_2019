##
## EPITECH PROJECT, 2019
## makefile
## File description:
## project makefile
##

SRC =   src/main.c	\
		src/usage/usage.c	\
		src/map.c	\
		src/arrows.c	\
		src/targets.c

OBJ =   $(SRC:.c=.o)

NAME    =   my_sokoban

CFLAGS  +=  -I include -Wall -Wextra -g
LDFLAGS +=  -L lib/my -lmy -lncurses

all:    $(NAME)

$(NAME):    $(OBJ)
	make -C lib/my/
	gcc -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	@make clean -C lib/my/ --no-print-directory
	@rm -f $(OBJ)

fclean: clean
	@make fclean -C lib/my/ --no-print-directory
	@rm -f $(NAME)

re: fclean all

run: all
	./$(NAME)

.PHONY: all clean fclean