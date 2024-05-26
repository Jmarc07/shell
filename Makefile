##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## setting up
##

NAME	=  mysh

SRC	=   $(shell find -type f -name '*.c')

OBJ	=   $(SRC:.c=.o)

CFLAGS	=   -W -Wall -Wextra -I./include -Wpedantic -L./lib/my -g3

$(NAME) :    $(OBJ)
		gcc -o $(NAME) $(OBJ)	$(CFLAGS)

all	:   $(NAME)

clean   :
		rm -f *~
		rm -f #*#
		rm -f $(OBJ)

fclean  :   clean
		rm -f $(NAME)


re  :	fclean all

.PHONY  :   all clean   fclean    re
