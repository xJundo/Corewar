/*
** EPITECH PROJECT, 2023
** op.c
** File description:
** op.c
*/

#include "op.h"

int my_and(champion_t *champion)
{
    int coding_byte = get_vm()->arena[(champion->pc + 1) % MEM_SIZE];
    char param[3] = {coding_byte >> 6 & 3,
    coding_byte >> 4 & 3, coding_byte >> 2 & 3};
    int beuteu[] = {BTR(param[0], 0),
                    BTR(param[1], 0),
                    BTR(param[2], 0)};
    int first =
    get_value(BTR(param[0], 0), (champion->pc + 2) % MEM_SIZE);
    int second = get_value(BTR(param[1], 0),
    (champion->pc + 2 + beuteu[0]) % MEM_SIZE);
    int reg =
    get_vm()->arena[(champion->pc + 2 + beuteu[0] + beuteu[1]) % MEM_SIZE];

    if (param[2] != 1 || !reg_is_valid(reg))
        return 1;
    champion->reg[reg - 1] = first & second;
    return 0;
}
