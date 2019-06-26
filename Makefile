##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Make
##

LIB_PATH	=	./lib/my

SRC		=	src/main.c \
			src/navy.c \
			src/display.c \
			src/communication.c \
			src/utils.c \
			src/map.c \
			src/game.c

OBJ		=	$(SRC:.c=.o)

CFLAGS		+=	-W -Wall -Wextra -g3

NAME	=	navy

all: make_lib $(NAME)

$(NAME): $(OBJ)
	gcc -g $(OBJ) -o $(NAME) -I./include -L./lib/my -lmy

clean:
	rm -f $(OBJ) temp.txt pid.txt hit_or_missed.txt

fclean: clean_lib clean
	rm -f $(NAME)

re: fclean all

make_lib:
	cd $(LIB_PATH) && $(MAKE) re

clean_lib:
	cd $(LIB_PATH) && $(MAKE) fclean
