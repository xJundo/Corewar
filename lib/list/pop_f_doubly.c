/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include "mylist.h"

nodes_t *pop_f_doubly(nodes_t **list)
{
    if (*list == NULL)
        return NULL;
    return previous_to_next(list, *list);
}
