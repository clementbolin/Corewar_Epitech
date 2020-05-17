##
## EPITECH PROJECT, 2019
## makefile
## File description:
## match
##

SRC		= 		./src/main.c							\
				./src/link/basic_link.c					\
				./src/open_file.c						\
				./src/binary/write_header.c				\
				./src/binary/write_instruction.c		\
				./src/binary/write_instruction_two.c	\
				./src/tool.c							\
				./src/log.c								\
				./src/bin_to_hexa.c						\
				./src/binary/prog_size.c				\
				./src/binary/prog_size_two.c			\
				./src/binary/write_arg.c				\
				./src/op.c								\
				./src/init/main_init.c					\
				./src/init/champ.c						\
				./src/init/array.c						\
				./src/init/link_list.c					\
				./src/init/link_list_two.c				\
				./src/init/link_list_three.c			\
				./src/init/check_pre_label.c			\
				./src/lib/clean_my_string.c				\
				./src/lib/my_strcmp_mod.c				\

OBJ		= $(SRC:.c=.o)
CC 		= gcc
RM		= rm -f
NAME	= asm
TEST 	= make -C ./tests
CFLAGS	= -W -Wall -Wextra -g3 -Wno-deprecated -Werror -I./../include/
LDFLAGS		=  -L. ../lib/libmy.a

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

all: 		start $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c -o $@ $<
	@echo "$(BLUE)Creating object file -> $(WHITE)$(notdir $@)... $(RED)[Done]"

$(NAME):	$(OBJ)
		@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LDFLAGS)
		@echo "$(GREEN)[$(NAME)] was successfully created$(WHITE)"

test_run:
			$(TEST)
		./tests/unit_tests

clean:
		$(RM) $(OBJ)
		make fclean -C ./tests
		@echo "\033[5m\033[3m\033[33mEtat for -> $(NAME) -> clean -> OK\033[0m"

fclean: clean
		$(RM) $(NAME)
		@echo "\033[5m\033[3m\033[33mEtat for -> $(NAME) -> fclean -> OK\033[0m"

start:
	@echo "$(CYAN)We Start Compile ASM$(WHITE)"

re:		fclean all