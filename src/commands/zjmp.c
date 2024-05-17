/*
** EPITECH PROJECT, 2023
** op.c
** File description:
** op.c
*/

#include "op.h"

//NO CODING BYTE
//DIRECT 2 BYTES

int zjmp(champion_t *champion)
{
    int index = get_value(2, (champion->pc + 1) % MEM_SIZE);

    if (champion->carry == 1)
        champion->pc = (champion->pc + index % IDX_MOD) % MEM_SIZE;
    else
        champion->pc = (champion->pc + 3) % MEM_SIZE;
    return 0;
}
