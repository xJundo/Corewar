/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include "mylist.h"
#include "../../include/my.h"

void push_b_doubly(nodes_t **head, void *data, type_t type)
{
    nodes_t *new = MALLOC(sizeof(nodes_t));
    nodes_t *tmp;

    if (*head == NULL) {
        new->data = data;
        new->type = type;
        new->previous = NULL;
        new->next = NULL;
        *head = new;
        return;
    }
    for (tmp = *head; tmp->next != NULL; tmp = tmp->next);
    new->data = data;
    new->type = type;
    new->previous = tmp;
    new->next = NULL;
    tmp->next = new;
}
