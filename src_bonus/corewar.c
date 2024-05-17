/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/


#include "op.h"

vm_t *get_vm(void)
{
    static vm_t vm =
    {-1,
    NULL,
    NULL,
    0,
    {0},
    {0},
    NULL,
    {0},
    0,
    0,
    0,
    .total_live = 0,
    .nbr_live = NBR_LIVE,
    1};

    return &vm;
}

int help(void)
{
    my_putstr("USAGE\n");
    my_putstr("./corewar [-dump nbr_cycle] "
    "[[-n prog_number] [-a load_address] prog_name] ...\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("-dump nbr_cycle dumps the memory after "
    "the nbr_cycle execution (if the round isn't\n");
    my_putstr("already over) with the following format: "
    "32 bytes/line in hexadecimal (A0BCDEFE1DD3...)\n");
    my_putstr("-n prog_number sets the next program's number."
    " By default, the first free number in the\n");
    my_putstr("parameter order\n");
    my_putstr("-a load_address sets the next program's loading address."
    "When no address is specified,\noptimize the addresses so that the "
    "processes are as far");
    my_putstr(" away from each other as\npossible. "
    "The addresses are MEM_SIZE modulo.\n");
    return 0;
}

int corewar(int ac, char **av)
{
    if (ac == 2 && my_strcmp(av[1], "-h") == 0)
        return (help());
    if (parse_args(ac, av) == FAILURE) {
        FREE;
        return 84;
    }
    FREE;
    return 0;
}
