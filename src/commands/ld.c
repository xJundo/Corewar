/*
** EPITECH PROJECT, 2023
** op.c
** File description:
** op.c
*/

#include "op.h"

int my_ld(champion_t *champion)
{
    int coding_bytes = get_vm()->arena[(champion->pc + 1) % MEM_SIZE];
    char param[2] =
    {(coding_bytes) >> 6 & 3, (coding_bytes) >> 4 & 3};
    int br[] =
    {BTR(param[0], 0), BTR(param[1], 0)};
    int x1 = get_value(br[0], (champion->pc + 2) % MEM_SIZE);
    int reg = get_value(br[1], (champion->pc + 2 + br[0]) % MEM_SIZE);
    int value = get_value(4, (champion->pc + x1 % IDX_MOD) % MEM_SIZE);

    if (param[0] == 2)
        value = x1;
    if ((param[0] != 2 && param[0] != 3)
    || (param[1] != 1 || !reg_is_valid(reg))
    || coding_bytes >> 2 & 3 != 0 || coding_bytes & 3 != 0)
        return 1;
    champion->reg[reg - 1] = value;
    champion->carry = value == 0 ? 1 : 0;
    champion->pc = (champion->pc + br[0] + br[1] + 2) % MEM_SIZE;
    return 0;
}
