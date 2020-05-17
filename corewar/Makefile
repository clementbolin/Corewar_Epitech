##
## EPITECH PROJECT, 2019
## makefile
## File description:
## match
##

SRC		= 		./src/main.c 									\
				./src/init/init_champ.c 						\
				./src/init/fill_champ.c 						\
				./src/init/init_arena.c 						\
				./src/init/init_register.c 						\
				./src/display/display_map.c 					\
				./src/init/init_color_map.c 					\
				./src/display/display_color.c 					\
				./src/display/main_display.c 					\
				./src/pc/augment_pc.c 							\
				./src/instruction/link/basic_link.c 			\
				./src/instruction/link/inst_link.c 				\
				./src/instruction/link/fill_link_inst.c 		\
				./src/manage_cycle.c 							\
				./src/pc/tool_pc.c 								\
				./src/pc/pc.c 									\
				./src/pc/special_pc.c							\
				./src/flag.c 									\
				./src/tool.c									\
				./src/instruction/manage_instruction.c 			\
				./src/op.c 										\
				./src/instruction/tool_inst.c 					\
				./src/instruction/ld.c 							\
				./src/instruction/st.c 							\
				./src/instruction/add.c 						\
				./src/instruction/sub.c 						\
				./src/instruction/live.c 						\
				./src/instruction/sti.c 						\
				./src/display/display_button_menu.c				\
				./src/instruction/and.c							\
				./src/instruction/xor.c							\
				./src/instruction/or.c							\
				./src/instruction/ldi.c							\
				./src/instruction/lld.c							\

OBJ		= $(SRC:.c=.o)
CC 		= gcc
RM		= rm -f
NAME	= corewar
TEST 	= make -C ./tests
CFLAGS	= -W -Wall -Wextra -g3 -Wno-deprecated -Werror -I./../include/
LDFLAGS		=  -L. ../lib/libmy.a -lncurses

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
		@echo "\033[5m\033[3m\033[33mEtat for -> $(NAME) -> clean -> OK\033[0m"

fclean: clean
		$(RM) $(NAME)
		@echo "\033[5m\033[3m\033[33mEtat for -> $(NAME) -> fclean -> OK\033[0m"

start:
	@echo "$(YELLOW)We Start Compile VM corewar$(WHITE)"

re:		fclean all