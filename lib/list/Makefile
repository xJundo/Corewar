##
## EPITECH PROJECT, 2023
## starting with makefile
## File description:
## starting with makefile
##

CFLAGS = -Werror -Wpedantic

SRC	=	push_f.c			\
		del_matching_node.c	\
		print_list.c		\
		my_list_size.c		\
		my_strput.c			\
		my_charput.c		\
		my_nbr_put.c		\
		my_cmpstr.c			\
		my_strcmp_void.c	\
		my_intcmp_void.c	\
		my_dupstr.c			\
		my_lenstr.c			\
		just_remove_in_list.c\
		my_pointercmp.c		\
		print_adress.c		\
		del_in_doubly.c		\
		del_and_free_in_doubly.c	\
		print_list_doubly.c	\
		push_f_doubly.c		\
		push_b_doubly.c		\
		delete_list.c		\
		previous_to_next.c		\
		pop_b_doubly.c		\
		pop_f_doubly.c		\

OBJ	=	$(SRC:.c=.o)

NAME	=	liblist.a

all: $(NAME)

$(NAME): $(OBJ)
	@cp mylist.h ../../include
	@ar rc $(NAME) $(OBJ)
	@cp $(NAME) ../

clean:
	@rm -f $(OBJ)

test:
	gcc $(SRC) -o main -g3 $(CFLAGS)

fclean: clean
	@rm -f $(NAME)

re:	fclean all
