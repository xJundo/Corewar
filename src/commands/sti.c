/*
** EPITECH PROJECT, 2023
** op.c
** File description:
** op.c
*/

#include "op.h"

//DIRECT 2 BYTES

int sti(champion_t *champion)
{
    int coding_byte = get_vm()->arena[(champion->pc + 1) % MEM_SIZE];
    char param[3] = {coding_byte >> 6 & 3, coding_byte >> 4 & 3,
        coding_byte >> 2 & 3};
    int br[] = {BTR(param[0], 1), BTR(param[1], 1), BTR(param[2], 1)};
    int reg = get_vm()->arena[(champion->pc + 2) % MEM_SIZE];
    int x1 = get_value(br[1], (champion->pc + 2 + br[0]) % MEM_SIZE);
    int x2 = get_value(br[2], (champion->pc + 2 + br[0] + br[1]) % MEM_SIZE);

    if (param[0] != 1 || !reg_is_valid(reg))
        return 1;
    x1 = param[1] == 1 ? champion->reg[x1 - 1] : x1;
    x2 = param[2] == 1 ? champion->reg[x2 - 1] : x2;
    set_value(champion->reg[reg - 1], REG_SIZE,
    (champion->pc + (x1 + x2) % IDX_MOD) % MEM_SIZE);
    champion->pc = (champion->pc + br[0]
    + br[1] + br[2] + 2) % MEM_SIZE;
    return 0;
}
