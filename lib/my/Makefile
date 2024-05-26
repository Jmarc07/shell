##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## makefile
##

NAME    =  libmy.a

SRC =   $(shell find -type f -name '*.c')

OBJ =   $(SRC:.c=.o)

CFLAGS  =   -W -Wall -Wextra -I./include -Wpedantic

$(NAME) :    $(OBJ)
		ar rc libmy.a $(OBJ)
		cp libmy.a ../libmy.a
		cp my.h ../../include

all	:   $(NAME)

clean   :
		rm -f *~
		rm -f #*#
		rm -f $(OBJ)

fclean  :   clean
		rm -f $(NAME)

re  :	fclean all

.PHONY  :   all clean   fclean    re
