/*
** EPITECH PROJECT, 2023
** op.c
** File description:
** op.c
*/

#include "op.h"

int sub(champion_t *champion)
{
    int coding_bytes = get_vm()->arena[(champion->pc + 1) % MEM_SIZE];
    char params[3] = {(coding_bytes) >> 6 & 3,
                    (coding_bytes) >> 4 & 3,
                    (coding_bytes) >> 2 & 3};
    int beuteu[] = {BTR(params[0], 0),
                    BTR(params[1], 0),
                    BTR(params[2], 0)};
    int reg1 = get_vm()->arena[(champion->pc + 2) % MEM_SIZE];
    int reg2 = get_vm()->arena[(champion->pc + 2 + beuteu[0]) % MEM_SIZE];
    int reg3 =
    get_vm()->arena[(champion->pc + 2 + beuteu[0] + beuteu[1]) % MEM_SIZE];

    if (!reg_is_valid(reg1) || !reg_is_valid(reg2) || !reg_is_valid(reg3))
        return 1;
    champion->reg[reg3 - 1] =
    champion->reg[reg1 - 1] - champion->reg[reg2 - 1];
    champion->carry = champion->reg[reg3 - 1] == 0 ? 1 : 0;
    champion->pc =
    (champion->pc + beuteu[0] + beuteu[1] + beuteu[2] + 2) % MEM_SIZE;
    return 0;
}
