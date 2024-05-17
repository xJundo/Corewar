/*
** EPITECH PROJECT, 2023
** op.c
** File description:
** op.c
*/

#include "op.h"

int aff(champion_t *champion)
{
    int coding_byte = get_vm()->arena[(champion->pc + 1) % MEM_SIZE];
    char param = coding_byte >> 6;
    int reg = get_value(T_REG, (champion->pc + 2) % MEM_SIZE);
    int value;

    if (param != 1 || (reg < 1 || reg > 16))
        return 1;
    value = champion->reg[reg - 1];
    my_printf(1, "%c\n", value % 256);
    return 0;
}
