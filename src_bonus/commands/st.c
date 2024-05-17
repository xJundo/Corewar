/*
** EPITECH PROJECT, 2023
** op.c
** File description:
** op.c
*/

#include "op.h"

void print_color_st(champion_t *champion, char *param, int *beuteu)
{
    print_color_cursor_to_value(champion->pc,
    champion->pc + 1 + beuteu[0] + beuteu[1], champion->color, 1);
}

static void get_where_to_store(champion_t *champion,
    char *param, int value_to_store, int *beuteu)
{
    int where_to_store = 0;

    if (param[1] == 1) {
        where_to_store =
        get_value(beuteu[1], (champion->pc + 2 + beuteu[0]) % MEM_SIZE);
        if (!reg_is_valid(where_to_store))
            return;
        champion->reg[where_to_store - 1] = value_to_store;
    } else {
        where_to_store =
        get_value(beuteu[1], (champion->pc + 2 + beuteu[0]) % MEM_SIZE);
        set_value(value_to_store, REG_SIZE,
        (champion->pc + where_to_store % IDX_MOD) % MEM_SIZE);
    }
}

int my_st(champion_t *champion)
{
    int coding_byte = get_vm()->arena[(champion->pc + 1) % MEM_SIZE];
    char param[2] =
    {coding_byte >> 6 & 3, coding_byte >> 4 & 3};
    int beuteu[] =
    {BTR(param[0], 0), BTR(param[1], 0)};
    int value_to_store = get_value(beuteu[0], (champion->pc + 2) % MEM_SIZE);

    print_color_st(champion, param, beuteu);
    if (!reg_is_valid(value_to_store))
        return 1;
    value_to_store = champion->reg[value_to_store - 1];
    get_where_to_store(champion, param, value_to_store, beuteu);
    print_color_st(champion, param, beuteu);
    champion->pc = (champion->pc + beuteu[0] + beuteu[1] + 2) % MEM_SIZE;
    return 0;
}
