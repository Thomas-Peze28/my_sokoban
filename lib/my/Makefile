##
## EPITECH PROJECT, 2024
## makefile
## File description:
## makefile
##

SRC	=	my_strlowcase.c	\
		my_strlen.c  \
		my_strupcase.c \
		my_put_nbr.c  \
		my_putchar.c  \
		my_putstr.c  \
		my_revstr.c  \
		my_strcmp.c \
		my_strncmp.c \
		my_strcpy.c \
		my_strdup.c \
		my_strcat.c \
		my_str_to_word_array_02.c \
		my_printf/my_printf.c	\
		my_printf/my_put_float.c	\
		my_printf/my_put_long.c	\
		my_printf/my_put_unsigned.c	\
		my_printf/my_putnbr_base.c	\
		my_printf/my_putnbr_e.c	\
		my_printf/my_putnbr_sc.c	\
		my_printf/my_round.c	\
		clean_str.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
		ar rc $(NAME) $(OBJ)
		cp my.h ../../include
		cp $(NAME) ../

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
