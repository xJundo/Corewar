/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include "op.h"

int my_str_is_composed_by(char *str, char *str2)
{
    int valid = 1;

    for (int i = 0; str[i] && valid; i++) {
        valid = 0;
        for (int j = 0; str2[j]; j++)
            valid += str[i] == str2[j] ? 1 : 0;
    }
    return valid;
}

int parse_flag(char **av, int ac, int *i, args_t *args)
{
    if (my_strcmp(av[*i], "-dump") == 0)
        return flag_dump(av, ac, i, args);
    if (my_strcmp(av[*i], "-n") == 0)
        return flag_n_id(av, ac, i, args);
    if (my_strcmp(av[*i], "-a") == 0)
        return flag_add(av, ac, i, args);
    return SUCCESS;
}

int parse_args(int ac, char **av)
{
    int result = SUCCESS;
    args_t args = {NULL, NULL, NULL};

    for (int i = 1; av[i]; i++) {
        if (av[i][0] == '-')
            result = parse_flag(av, ac, &i, &args);
        else
            result = parse_file(av[i], &args);
        if (result == FAILURE)
            return FAILURE;
    }
    place_champions();
    main_loop();
    return SUCCESS;
}
