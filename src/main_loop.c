/*
** EPITECH PROJECT, 2023
** op.c
** File description:
** op.c
*/

#include "op.h"

void dump_memory(int *dump)
{
    if (get_vm()->dump_nb == -1 || *dump <= get_vm()->dump_nb)
        return;
    for (int i = 0; i < MEM_SIZE; i++) {
        if (i == MEM_SIZE - 1 || i % 32 == 31)
            my_printf(1, "%02x\n", get_vm()->arena[i]);
        else
            my_printf(1, "%02x ", get_vm()->arena[i]);
    }
}

int loop_prog(int i, int *dump)
{
    int nb_cycle = 0;

    while (nb_cycle < i) {
        dump_memory(dump);
        for (nodes_t *tmp = get_vm()->champions; tmp; tmp = tmp->next)
            do_instruction(tmp->data, *dump);
        if (get_vm()->dump_nb != -1 && *dump > get_vm()->dump_nb)
            *dump = 0;
        (*dump)++;
        (nb_cycle)++;
        get_vm()->total_cycle++;
        if (nb_cycle == 10)
            break;
    }
}

int main_loop(void)
{
    int dump = 0;

    for (int i = 0; i < MEM_SIZE; i++) {
        my_printf(1, "%02x ", get_vm()->arena[i]);
        if (i % 32 == 31)
            my_printf(1, "\n");
    }
    return 0;
}
