##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

SRC		=	get_next_line.c \
			my_putstr.c \
			my_strlen.c \
			my_str_to_int.c \
			int_to_str.c \
			my_put_nbr.c \
			my_putchar.c \
			my_strcmp.c \
			my_strncmp.c

DEST_LIB_DIR	=	.

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all: $(NAME)

$(NAME):
	gcc -g -c $(SRC)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
