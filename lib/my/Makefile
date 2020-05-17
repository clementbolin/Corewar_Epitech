##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## task01
##

SRC		=		my_compute_power_rec.c		\
				my_compute_square_root.c	\
				my_find_prime_sup.c			\
				my_getnbr.c					\
				my_isneg.c 					\
				my_is_prime.c				\
				my_putchar.c				\
				my_put_nbr.c				\
				my_putstr.c					\
				my_revstr.c					\
				my_showmem.c				\
				my_showstr.c				\
				my_sort_int_array.c			\
				my_strcapitalize.c			\
				my_strcat.c					\
				my_strcmp.c					\
				my_strcpy.c					\
				my_str_isalpha.c			\
				my_str_islower.c			\
				my_str_isnum.c				\
				my_str_isprintable.c		\
				my_str_isupper.c			\
				my_strlen.c					\
				my_strlowcase.c				\
				my_strncat.c				\
				my_strncmp.c				\
				my_strncpy.c				\
				my_strstr.c					\
				my_strupcase.c				\
				my_swap.c					\
				my_strdup.c 				\
				my_putnbr_base.c			\
				putstr_error.c 				\
				my_printf.c 				\
				my_flags_print.c 			\
				my_flags2_print.c 			\
				my_flags3_print.c 			\
				my_flags4_print.c 			\
				my_str_to_word_array.c 		\
				str_to_array.c 				\

NAME	=		libmy.a
OBJ		= $(SRC:.c=.o)
CFLAGS	=	-W -Wall -Wextra

### COLORS ###
NOC			= \033[0m
BOLD		= \033[1m
UNDERLINE	= \033[4m
BLACK		= \033[1;30m
RED			= \033[1;31m
GREEN		= \033[1;32m
YELLOW		= \033[1;33m
BLUE		= \033[1;34m
VIOLET		= \033[1;35m
CYAN		= \033[1;36m
WHITE		= \033[1;37m

all:	$(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c -o $@ $<
	@echo "$(BLUE)Creating object file -> $(WHITE)$(notdir $@)... $(RED)[Done]"

$(NAME):	$(OBJ)
		ar rc $(NAME) $(OBJ)
		cp ./libmy.a ../
		cp ./libmy.a ../../
		cp ./my_printf.h ../../include
		cp ./my.h ../../include

clean:
	rm -f $(OBJ)

fclean:
	rm -f ./../libmy.a
	rm -f ./libmy.a
	rm -f ./../../libmy.a

re: fclean all