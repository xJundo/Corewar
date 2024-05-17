/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include "mylist.h"

nodes_t *previous_to_next(nodes_t **head, nodes_t *to_delete)
{
    if (*head == NULL || to_delete == NULL)
        return NULL;
    if (*head == to_delete) {
        if (to_delete->next != NULL) {
            (*head) = to_delete->next;
        } else
            (*head) = NULL;
        if (*head != NULL)
            (*head)->previous = NULL;
        return to_delete;
    }
    if (to_delete->previous != NULL)
        to_delete->previous->next = to_delete->next;
    if (to_delete->next != NULL)
        to_delete->next->previous = to_delete->previous;
    return to_delete;
}
