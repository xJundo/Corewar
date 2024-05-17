/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include "op.h"

int my_memcpy_circular(void *dest, void *src, int size, int start)
{
    int i = 0;

    for (i = 0; i < size; i++) {
        ((char *)dest)[(start + i) % MEM_SIZE] = ((char *)src)[i];
    }
    return i;
}

static int size_champ_no_address(void)
{
    int nb = 0;

    for (nodes_t *tmp = get_vm()->champions; tmp; tmp = tmp->next) {
        if (((champion_t *)tmp->data)->address == -1)
            nb += ((champion_t *)tmp->data)->header->prog_size;
    }
    return nb;
}

static int equidistance(void)
{
    champion_t *champion = NULL;
    int max_size = MEM_SIZE - size_champ_no_address();
    int address[] = {0, MEM_SIZE / 4, 2 * (MEM_SIZE / 4), 3 * (MEM_SIZE / 4)};
    int i = 0;

    for (nodes_t *tmp = get_vm()->champions; tmp; tmp = tmp->next) {
        champion = tmp->data;
        if (champion->address != -1) {
            champion->pc = champion->address;
            continue;
        }
        champion->address = address[i];
        i++;
        champion->pc = champion->address;
    }
    return 0;
}

static void suite_sort(champion_t *champion, champion_t *champion_next,
    nodes_t *tmp, nodes_t *tmp2)
{
    if (champion->prog_number > champion_next->prog_number) {
        tmp->data = champion_next;
        tmp2->data = champion;
        champion = tmp->data;
        champion_next = tmp2->data;
    }
}

void sort_list_champions(void)
{
    champion_t *champion = NULL;
    champion_t *champion_next = NULL;

    for (nodes_t *tmp = get_vm()->champions; tmp; tmp = tmp->next) {
        champion = tmp->data;
        for (nodes_t *tmp2 = tmp->next; tmp2; tmp2 = tmp2->next) {
            champion_next = tmp2->data;
            suite_sort(champion, champion_next, tmp, tmp2);
        }
    }
}

int place_champions(void)
{
    champion_t *champion = NULL;

    sort_list_champions();
    equidistance();
    for (nodes_t *tmp = get_vm()->champions; tmp; tmp = tmp->next) {
        champion = tmp->data;
        my_memcpy_circular(get_vm()->arena, champion->prog,
        champion->header->prog_size, champion->address);
    }
    return 0;
}
