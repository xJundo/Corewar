##
## EPITECH PROJECT, 2023
## my_printf
## File description:
## The main Makefile of our project
##

COLORS = $$(seq 1 7 | shuf -n 1)
RED = $$(tput setaf $(COLORS))
GREEN = $$(tput setaf $(COLORS))
YELLOW = $$(tput setaf $(COLORS))
RESET = $$(tput sgr0)
MAKEFLAGS += --no-print-directory

CFLAGS = -I./include -Wpedantic -Wextra
CFLAGS += -g -g3
BFLAGS = -lncurses
LFLAGS = -L./lib -lmy -llist
TEST_FLAGS = --coverage -lcriterion -lgcov

SRC	= src/main.c
SRC += src/main_loop.c
SRC += src/instructions.c
SRC += src/place_champion.c
SRC += src/parse_file.c
SRC += src/parse_args.c
SRC += src/op.c
SRC += src/flag/flag_dump.c
SRC += src/flag/flag_n_id.c
SRC += src/flag/flag_add.c
SRC += src/commands/zjmp.c
SRC += src/commands/xor.c
SRC += src/commands/sub.c
SRC += src/commands/sti.c
SRC += src/commands/st.c
SRC += src/commands/or.c
SRC += src/commands/my_fork.c
SRC += src/commands/lldi.c
SRC += src/commands/lld.c
SRC += src/commands/live.c
SRC += src/commands/lfork.c
SRC += src/commands/ldi.c
SRC += src/commands/ld.c
SRC += src/commands/and.c
SRC += src/commands/aff.c
SRC += src/commands/add.c
SRC += src/corewar.c

SRC_BONUS	= src_bonus/main.c
SRC_BONUS += src_bonus/main_loop.c
SRC_BONUS += src_bonus/print_color_arena.c
SRC_BONUS += src_bonus/instructions.c
SRC_BONUS += src_bonus/place_champion.c
SRC_BONUS += src_bonus/parse_file.c
SRC_BONUS += src_bonus/parse_args.c
SRC_BONUS += src_bonus/op.c
SRC_BONUS += src_bonus/flag/flag_dump.c
SRC_BONUS += src_bonus/flag/flag_n_id.c
SRC_BONUS += src_bonus/flag/flag_add.c
SRC_BONUS += src_bonus/commands/zjmp.c
SRC_BONUS += src_bonus/commands/xor.c
SRC_BONUS += src_bonus/commands/sub.c
SRC_BONUS += src_bonus/commands/sti.c
SRC_BONUS += src_bonus/commands/st.c
SRC_BONUS += src_bonus/commands/or.c
SRC_BONUS += src_bonus/commands/my_fork.c
SRC_BONUS += src_bonus/commands/lldi.c
SRC_BONUS += src_bonus/commands/lld.c
SRC_BONUS += src_bonus/commands/live.c
SRC_BONUS += src_bonus/commands/lfork.c
SRC_BONUS += src_bonus/commands/ldi.c
SRC_BONUS += src_bonus/commands/ld.c
SRC_BONUS += src_bonus/commands/and.c
SRC_BONUS += src_bonus/commands/aff.c
SRC_BONUS += src_bonus/commands/add.c
SRC_BONUS += src_bonus/corewar.c

OBJ	=	$(SRC:.c=.o)

NAME = corewar
NAME_BONUS = corewar_bonus

all: libmy liblist test
	@echo "$(RESET)"

libmy:
	@echo "$(RED)------------------"
	@echo "$(RED)doing libmy"
	@make -s -C ./lib/my/
	@echo "$(RED)------------------"

liblist:
	@echo "$(RED)------------------"
	@echo "$(GREEN)doing liblist"
	@make -s -C ./lib/list/
	@echo "$(RED)------------------"

test: $(OBJ)
	@gcc $(SRC) -o $(NAME) -g3 $(CFLAGS) $(LFLAGS)

bonus:
	@gcc $(SRC_BONUS) -o $(NAME_BONUS) -g3 $(CFLAGS) $(BFLAGS) $(LFLAGS)


valgrind: $(OBJ)
	@gcc $(SRC) -g3 $(CFLAGS) $(LFLAGS)
	@valgrind -s ./$(NAME)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

clean_lib:
	@make fclean -C./lib/my/
	@make fclean -C./lib/list/
	@make fclean -C./tests/

re:	clean_lib fclean all

unit_tests: re
	make unit_tests -C ./tests/

tests_run: re
	make -C ./tests/
	@gcovr
