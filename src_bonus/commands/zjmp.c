/*
** EPITECH PROJECT, 2023
** op.c
** File description:
** op.c
*/

#include "op.h"

//NO CODING BYTE
//DIRECT 2 BYTES

void print_color_zjmp(champion_t *champion, int index)
{
    if (champion->carry) {
        print_color_cursor_to_value(champion->pc,
        champion->pc + 2, champion->color, 1);
        print_color_cursor(
        (champion->pc + index % IDX_MOD) % MEM_SIZE, champion->color, 1);
    } else {
        print_color_cursor(champion->pc, champion->color, 1);
        print_color_cursor((champion->pc + 3) % MEM_SIZE, champion->color, 1);
    }
}

int zjmp(champion_t *champion)
{
    int index = get_value(2, (champion->pc + 1) % MEM_SIZE);

    print_color_zjmp(champion, index);
    if (champion->carry == 1)
        champion->pc = (champion->pc + index % IDX_MOD) % MEM_SIZE;
    else
        champion->pc = (champion->pc + 3) % MEM_SIZE;
    return 0;
}
