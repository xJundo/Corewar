/*
** EPITECH PROJECT, 2023
** op.c
** File description:
** op.c
*/

#include "op.h"

//DIRECT 2 BYTES
//NO CODING BYTE

int my_fork(champion_t *champion)
{
    int index = get_value(T_IND, (champion->pc + 1) % MEM_SIZE);
    int new_pc = (champion->pc + index % IDX_MOD) % MEM_SIZE;
    champion_t *new_champion = MALLOC(sizeof(champion_t));

    if (!new_champion)
        return 1;
    new_champion->pc = new_pc;
    new_champion->carry = champion->carry;
    new_champion->prog_number = get_first_id();
    new_champion->live = 0;
    new_champion->cooldown = 800;
    new_champion->header = champion->header;
    new_champion->parent = champion;
    new_champion->color = champion->color;
    print_color_cursor((champion->pc + index % IDX_MOD) % MEM_SIZE, 5, 0);
    push_b_doubly(&get_vm()->champions, new_champion, UNKNOW);
    return 0;
}
