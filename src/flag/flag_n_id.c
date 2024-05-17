/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include "op.h"


int id_exist(int id)
{
    for (nodes_t *tmp = get_vm()->progs_ids; tmp; tmp = tmp->next) {
        if (id == my_getnbr(tmp->data))
            return 1;
    }
    return 0;
}

int get_first_id(void)
{
    for (int i = 1; i <= 4; i++) {
        if (!id_exist(i)) {
            push_b_doubly(&get_vm()->progs_ids,
            my_strdup(my_str_nbr((i))), STR);
            return i;
        }
    }
    return 0;
}

int get_and_check_prog_number(char **av, int ac, int *i, args_t *args)
{
    int prog_number = my_getnbr(av[*i + 1]);

    for (nodes_t *tmp = get_vm()->progs_ids; tmp; tmp = tmp->next) {
        if (prog_number == my_getnbr(tmp->data)) {
            my_printf(2, "Prog number already used.\n");
            return FAILURE;
        }
    }
    push_b_doubly(&get_vm()->progs_ids, my_strdup(av[*i + 1]), STR);
    args->prog_number = my_strdup(av[*i + 1]);
    *i += 1;
    return SUCCESS;
}

int flag_n_id(char **av, int ac, int *i, args_t *args)
{
    if (*i + 1 >= ac) {
        my_printf(2, "Missing prog number.\n");
        return FAILURE;
    }
    if (!my_str_is_composed_by(av[*i + 1], "0123456789")) {
        my_printf(2, "Prog number must be a number.\n");
        return FAILURE;
    }
    if (my_getnbr(av[*i + 1]) <= 0) {
        my_printf(2, "Prog number must be greater than 0.\n");
        return FAILURE;
    }
    return get_and_check_prog_number(av, ac, i, args);
}
