/*
** EPITECH PROJECT, 2023
** my list size
** File description:
** taille de liste
*/

#include "mylist.h"

int list_size(nodes_t **head)
{
    int size = 0;
    nodes_t *tmp = *head;

    while (tmp != NULL) {
        size++;
        tmp = tmp->next;
    }
    return size;
}
