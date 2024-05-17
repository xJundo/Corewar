/*
** EPITECH PROJECT, 2023
** op.c
** File description:
** op.c
*/

#include "op.h"

//NO CODING BYTE

int live(champion_t *champion)
{
    int value = get_value(4, (champion->pc + 1) % MEM_SIZE);

    for (nodes_t *tmp = get_vm()->champions; tmp != NULL; tmp = tmp->next) {
        if (((champion_t *)tmp->data)->prog_number == value) {
            ((champion_t *)tmp->data)->live = 1;
            get_vm()->total_live++;
        }
    }
    champion->pc = (champion->pc + 5) % MEM_SIZE;
    return 0;
}
