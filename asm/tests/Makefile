##
## EPITECH PROJECT, 2019
## makefile infin_add
## File description:
## compile lib etc
##

CC		=	gcc

CFLAGS	=	--coverage -lcriterion -I../../include

SRC	=	../src/init/champ.c							\
		../src/init/array.c							\
		../src/init/link_list.c						\
		../src/init/link_list_two.c					\
		../src/init/link_list_three.c				\
		../src/lib/my_strcmp_mod.c					\
		../src/lib/clean_my_string.c				\
		../../lib/my/str_to_array.c					\
		../../lib/my/my_strlen.c					\
		../../lib/my/my_strcpy.c					\
		test_get_everything.c						\


OBJ	=	$(SRC:.c=.o)

NAME	=	units

all:	$(NAME)

$(NAME):
	$(CC) -o $(NAME) $(SRC) $(CFLAGS)
	./$(NAME)
	rm -rf rapport

clean:
	rm -f *.gcda *.gcno *.info

fclean:	clean
		$(RM) $(NAME)

re:		fclean all
