/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include "op.h"

int check_dump_number(char **av, int ac, int *i, args_t *args)
{
    if (!my_str_is_composed_by(av[*i + 1], "0123456789ABCDEF")) {
        my_printf(2, "Dump cycle number must be in hexa format.\n");
        return FAILURE;
    }
    get_vm()->dump_nb =
    my_getnbr(my_convert_base(av[*i + 1], "0123456789ABCDEF", "0123456789"));
    *i += 1;
    if (get_vm()->dump_nb <= 0)
        my_printf(2, "Dump cycle number must be greater than 0.\n");
    return SUCCESS;
}

int flag_dump(char **av, int ac, int *i, args_t *args)
{
    if (*i + 1 >= ac) {
        my_printf(2, "Missing dump cycle number.\n");
        return FAILURE;
    }
    return check_dump_number(av, ac, i, args);
}
