/*
** EPITECH PROJECT, 2023
** corewar
** File description:
** The test file for the unit tetes
*/

#include "op.h"
#include <criterion/criterion.h>
#include "criterion/redirect.h"
// #include "../lib/my/flags/myformats.h"
// #include "../lib/my/my.h"


Test(parse_args, valid_args)
{
    char *av[] = {"./corewar", "-dump", "10", "-n", "1", "champ1.cor", "-a", "0", "-n", "2", "champ2.cor", NULL};
    int ac = 11;
    cr_assert_eq(parse_args(ac, av), FAILURE);
}

Test(parse_args, invalid_args)
{
    char *av[] = {"./corewar", "-dump", "10", "-n", "1", "champ1.cor", "-a", "0", "-n", "1", "champ2.cor", NULL};
    int ac = 11;
    cr_assert_eq(parse_args(ac, av), FAILURE);
}

Test(parse_file, valid_file)
{
    args_t args = {NULL, NULL, NULL};
    cr_assert_eq(parse_file("champ.cor", &args), FAILURE);
}

Test(parse_file, invalid_file)
{
    args_t args = {NULL, NULL, NULL};
    cr_assert_eq(parse_file("invalid.cor", &args), FAILURE);
}

Test(flag_dump, valid_dump)
{
    char *av[] = {"./corewar", "-dump", "10", NULL};
    int ac = 3;
    int i = 1;
    args_t args = {NULL, NULL, NULL};
    cr_assert_eq(flag_dump(av, ac, &i, &args), SUCCESS);
}

Test(flag_dump, invalid_dump)
{
    char *av[] = {"./corewar", "-dump", "invalid", NULL};
    int ac = 3;
    int i = 1;
    args_t args = {NULL, NULL, NULL};
    cr_assert_eq(flag_dump(av, ac, &i, &args), FAILURE);
}

Test(flag_n, valid_n)
{
    char *av[] = {"./corewar", "-n", "1", NULL};
    int ac = 3;
    int i = 1;
    args_t args = {NULL, NULL, NULL};
    cr_assert_eq(flag_n_id(av, ac, &i, &args), SUCCESS);
}

Test(flag_n, invalid_n)
{
    char *av[] = {"./corewar", "-n", "invalid", NULL};
    int ac = 3;
    int i = 1;
    args_t args = {NULL, NULL, NULL};
    cr_assert_eq(flag_n_id(av, ac, &i, &args), FAILURE);
}

Test(flag_a, valid_a)
{
    char *av[] = {"./corewar", "-a", "0", NULL};
    int ac = 3;
    int i = 1;
    args_t args = {NULL, NULL, NULL};
    cr_assert_eq(flag_add(av, ac, &i, &args), SUCCESS);
}

Test(flag_a, invalid_a)
{
    char *av[] = {"./corewar", "-a", "invalid", NULL};
    int ac = 3;
    int i = 1;
    args_t args = {NULL, NULL, NULL};
    cr_assert_eq(flag_add(av, ac, &i, &args), FAILURE);
}