/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include <stdlib.h>
#include "mylist.h"

nodes_t *pop_b_doubly(nodes_t **list)
{
    if (*list == NULL)
        return NULL;
    for (nodes_t *tmp = *list; tmp != NULL; tmp = tmp->next) {
        if (tmp->next != NULL)
            continue;
        if (tmp->previous != NULL) {
            tmp->previous->next = NULL;
            return tmp;
        } else {
            *list = NULL;
            return tmp;
        }
    }
    return NULL;
}
