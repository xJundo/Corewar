/*
** EPITECH PROJECT, 2023
** op.c
** File description:
** op.c
*/

#include "op.h"

//DIRECT 2 BYTES

int ldi(champion_t *champion)
{
    int coding_byte = get_vm()->arena[(champion->pc + 1) % MEM_SIZE];
    char param[3] = {coding_byte >> 6 & 3,
    coding_byte >> 4 & 3, coding_byte >> 2 & 3};
    int beuteu[] = {BTR(param[0], 1), BTR(param[1], 1), BTR(param[2], 1)};
    int x1 = get_value(beuteu[0], (champion->pc + 2) % MEM_SIZE);
    int x2 = get_value(beuteu[1], (champion->pc + 2 + beuteu[0]) % MEM_SIZE);
    int reg = get_vm()->arena[(champion->pc + 2 + beuteu[0] + beuteu[1])
    % MEM_SIZE];
    int value = get_value(T_IND, (champion->pc + x1 % IDX_MOD) % MEM_SIZE);
    int sum = value + x2;

    if (param[2] != 1 || !reg_is_valid(reg))
        return 1;
    champion->reg[reg - 1] =
    get_value(REG_SIZE, (champion->pc + sum % IDX_MOD) % MEM_SIZE);
    champion->carry = champion->reg[reg - 1] == 0 ? 1 : 0;
    champion->pc =
    (champion->pc + beuteu[0] + beuteu[1] + beuteu[2] + 2) % MEM_SIZE;
    return 0;
}
