##
## EPITECH PROJECT, 2023
## my_printf
## File description:
## The main Makefile of our project
##

CFLAGS = -I../include/ -g3 -Werror -Wpedantic
#CFLAGS += -lcsfml-graphics -lcsfml-window -lcsfml-system
CFLAGS += -lm
LFLAGS = -L../lib -lmy -llist
TEST_FLAGS = --coverage -lcriterion -lgcov

MAIN	=	main.c		\

SRC	=	../lib/my/my_array_of_array_len.c	\
		../lib/my/my_compute_factorial_rec.c	\
		../lib/my/my_compute_power_rec.c		\
		../lib/my/my_compute_square_root.c	\
		../lib/my/my_concat_params.c		\
		../lib/my/my_convert_base.c		\
		../lib/my/my_convert_base_unsigned.c	\
		../lib/my/my_find_prime_sup.c		\
		../lib/my/my_getnbr.c			\
		../lib/my/my_getnbr_base.c		\
		../lib/my/my_isneg.c			\
		../lib/my/my_is_prime.c			\
		../lib/my/my_print_combn.c		\
		../lib/my/my_print_params.c		\
		../lib/my/my_put_nbr.c			\
		../lib/my/my_putchar.c			\
		../lib/my/my_putnbr_base.c		\
		../lib/my/my_putstr.c			\
		../lib/my/my_putstr_error.c		\
		../lib/my/my_putstr_sized.c		\
		../lib/my/my_rev_params.c		\
		../lib/my/my_revstr.c			\
		../lib/my/my_show_word_array.c		\
		../lib/my/my_showmem.c			\
		../lib/my/my_showstr.c			\
		../lib/my/my_sort_int_array.c		\
		../lib/my/my_sort_params.c		\
		../lib/my/my_str_isalpha.c		\
		../lib/my/my_str_islower.c		\
		../lib/my/my_str_isnum.c			\
		../lib/my/my_str_isprintable.c		\
		../lib/my/my_str_isupper.c		\
		../lib/my/my_str_nbr.c			\
		../lib/my/my_str_nbr_base_unsigned.c	\
		../lib/my/my_str_nbr_base_long_long_int.c\
		../lib/my/my_str_nbr_unsigned.c		\
		../lib/my/my_str_nbr_unsigned_long.c	\
		../lib/my/my_str_nbr_long_long.c		\
		../lib/my/my_str_nbr_size_t.c		\
		../lib/my/my_strcapitalize.c             \
		../lib/my/my_strcat.c                    \
		../lib/my/my_strcmp.c                    \
		../lib/my/my_strcpy.c                    \
		../lib/my/my_strdup.c			\
		../lib/my/my_strlen.c			\
		../lib/my/my_strlowcase.c		\
		../lib/my/my_strncat.c			\
		../lib/my/my_strncmp.c			\
		../lib/my/my_strncpy.c			\
		../lib/my/my_strstr.c			\
		../lib/my/my_strupcase.c			\
		../lib/my/my_swap.c			\
		../lib/my/flags/flag_c.c			\
	        ../lib/my/flags/flag_s.c			\
                ../lib/my/flags/flag_d.c	\
                ../lib/my/flags/flag_i.c			\
                ../lib/my/flags/flag_p.c			\
                ../lib/my/flags/flag_o.c			\
                ../lib/my/flags/flag_u.c			\
                ../lib/my/flags/flag_x.c			\
                ../lib/my/flags/flag_bigx.c		\
                ../lib/my/flags/flag_e.c			\
                ../lib/my/flags/flag_bige.c		\
                ../lib/my/flags/flag_f.c			\
                ../lib/my/flags/flag_bigf.c		\
                ../lib/my/flags/flag_g.c			\
                ../lib/my/flags/flag_bigg.c		\
                ../lib/my/flags/flag_a.c			\
                ../lib/my/flags/flag_biga.c		\
                ../lib/my/flags/flag_n.c			\
                ../lib/my/flags/flag_m.c			\
                ../lib/my/flags/flag_b.c			\
                ../lib/my/flags/flag_bigs.c		\
                ../lib/my/flags/flag_bigd.c		\
		../lib/my/flags/find_format.c		\
		../lib/my/flags/get_format.c			\
		../lib/my/flags/my_show_formating.c	\
		../lib/my/flags/sub_format_double.c	\
		../lib/my/my_printf.c				\
		../lib/my/flags/format_it_int.c		\
		../lib/my/flags/format_it_double.c	\
		../lib/my/flags/precise_it_int.c	\
		../lib/my/flags/precise_it_double.c	\
		../lib/my/flags/format_it_str.c		\
		../lib/my/flags/format_it_char.c	\
		../lib/my/flags/sub_format_int.c	\
		../lib/my/flags/sub_format_str.c	\
		../lib/my/flags/sub_format_char.c	\
		../lib/my/flags/specifier_int.c		\
		../lib/my/flags/specifier_base.c	\


# SRC	= src/main.c
SRC += ../src/main_loop.c 
SRC += ../src/instructions.c
SRC += ../src/place_champion.c
SRC += ../src/parse_file.c
SRC += ../src/parse_args.c
SRC += ../src/op.c
SRC += ../src/flag/flag_dump.c
SRC += ../src/flag/flag_n_id.c
SRC += ../src/flag/flag_add.c
SRC += ../src/commands/zjmp.c
SRC += ../src/commands/xor.c
SRC += ../src/commands/sub.c
SRC += ../src/commands/sti.c
SRC += ../src/commands/st.c
SRC += ../src/commands/or.c
SRC += ../src/commands/my_fork.c
SRC += ../src/commands/lldi.c
SRC += ../src/commands/lld.c
SRC += ../src/commands/live.c
SRC += ../src/commands/lfork.c
SRC += ../src/commands/ldi.c
SRC += ../src/commands/ld.c
SRC += ../src/commands/and.c
SRC += ../src/commands/aff.c
SRC += ../src/commands/add.c
SRC += ../src/corewar.c


all:  tests_run

fclean:
	@rm -f unit_tests*

re:	fclean all

unit_tests:
	@gcc -o unit_tests $(SRC) *.c $(CFLAGS) $(LFLAGS) $(TEST_FLAGS)

tests_run: unit_tests
	@./unit_tests

