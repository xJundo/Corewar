/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include "mylist.h"
#include "../../include/my.h"

void push_f_doubly(nodes_t **head, void *data, type_t type)
{
    nodes_t *new = MALLOC(sizeof(nodes_t));

    new->data = data;
    new->type = type;
    new->previous = NULL;
    new->next = *head;
    if (*head != NULL)
        (*head)->previous = new;
    *head = new;
    return;
}
