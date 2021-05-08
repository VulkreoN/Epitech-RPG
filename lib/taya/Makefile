##
## EPITECH PROJECT, 2021
## lib_Taya
## File description:
## Makefile
##

CC	=	gcc

CFLAGS	=	-W -Wall -Wpedantic -Wextra -I./include

SRC	=	int/my_getnbr.c	\
		int/my_isneg.c	\
		int/my_intlen.c \
		int/my_atoi.c	\
		puts/my_putchar.c	\
		puts/my_putnbr.c	\
		puts/my_putnbr_unsigned.c	\
		puts/my_putoctal.c	\
		puts/my_puthexa.c	\
		puts/my_putuhexa.c	\
		puts/my_putstr.c	\
		puts/my_putstr_error.c	\
		puts/my_ldprintf.c	\
		puts/my_dputstr.c	\
		puts/my_dputchar.c	\
		puts/my_dputnbr.c	\
		puts/my_print_array.c	\
		puts/my_printf.c \
		puts/octal.c \
		strings/my_revstr.c	\
		strings/my_str_isnum.c	\
		strings/my_strcmp.c	\
		strings/my_strlen.c	\
		strings/my_strupcase.c	\
		strings/my_strlowcase.c	\
		strings/my_strcpy.c	\
		strings/my_strncpy.c	\
		strings/my_strdup.c	\
		strings/my_strndup.c	\
		strings/my_swap.c	\
		strings/my_strcat.c			\
		csfml/mouse/mouse_handling.c	\
		csfml/object_handling/get_object_texture.c	\
		csfml/object_handling/handle_sprite.c	\
		csfml/object_handling/sort_list.c	\
		csfml/object_handling/texture_name_linked_list.c	\
		csfml/position/my_position.c				\
		csfml/object_handling/make_text.c	\
		array/my_arraylen.c	\
		array/my_free_array.c	\
		array/my_str_to_word_array.c

NAME	=	libtaya.a

OBJ	=	$(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	@ar rc $(NAME) $(OBJ)
	@cp $(NAME) ../
	@rm $(NAME)

clean:
	@rm -f $(OBJ)

fclean:	clean
	@rm -f $(NAME)
	@rm -f ../$(NAME)

auteur:
	@echo $(USER) > auteur

re:	fclean	all