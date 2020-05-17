##
## EPITECH PROJECT, 2019
## makefile
## File description:
## match
##

CC 		= gcc
RM		= rm -f
COREWAR = make -C ./corewar
ASM 	= make -C ./asm
LIB		= make -C ./lib/my
TEST 	= make test_run -C ./asm

all:
	$(LIB)
	$(COREWAR)
	$(ASM)

test_run:
			$(TEST)
		./tests/unit_tests

retest:
	$(TEST) re
	./tests/unit_tests

clean:
		$(LIB) clean
		$(RM) $(OBJ)
		$(COREWAR) clean
		$(ASM) clean

fclean: clean
		$(LIB) fclean
		$(COREWAR) fclean
		$(ASM) fclean

re:		fclean all