/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include "op.h"

int is_address_valid(char *address, args_t *args, int *i)
{
    for (nodes_t *tmp = get_vm()->addresses; tmp; tmp = tmp->next) {
        if (my_getnbr(address) == my_getnbr(tmp->data)) {
            my_printf(2, "Address already used.\n");
            return FAILURE;
        }
    }
    push_b_doubly(&get_vm()->addresses, my_strdup(address), STR);
    args->load_address = my_strdup(address);
    *i += 1;
    return SUCCESS;
}

int flag_add(char **av, int ac, int *i, args_t *args)
{
    if (*i + 1 >= ac) {
        my_printf(2, "Missing load number.\n");
        return FAILURE;
    }
    if (!my_str_is_composed_by(av[*i + 1], "0123456789")) {
        my_printf(2, "Invalid load number.\n");
        return FAILURE;
    }
    return is_address_valid(av[*i + 1], args, i);
}
