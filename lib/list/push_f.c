/*
** EPITECH PROJECT, 2023
** my params to linked list
** File description:
** my params to linked list
*/

#include "mylist.h"
#include <stdlib.h>

void push_f(nodes_t **head, void *data, type_t type)
{
    nodes_t *new = malloc(sizeof(nodes_t));

    new->data = data;
    new->type = type;
    new->next = *head;
    *head = new;
}
