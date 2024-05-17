/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include <stdlib.h>
#include "mylist.h"

int del_node(int (*cmp)(void *, void *),
    void *data, nodes_t **previous, nodes_t **temp)
{
    if (cmp((*temp)->data, data) == 0) {
        (*previous)->next = (*temp)->next;
        free((*temp)->data);
        free((*temp));
        return 1;
    }
    return 0;
}

int del_first_node(nodes_t **head, void *data,
    int (*cmp)(void *, void *), nodes_t **previous)
{
    if (cmp((*head)->data, data) == 0) {
        *head = (*head)->next;
        free((*previous)->data);
        free((*previous));
        return 1;
    }
    return 0;
}

int remove_in_list(nodes_t **head, void *data, int (*cmp)())
{
    nodes_t *previous;

    if ((*head) == NULL)
        return 0;
    previous = *head;
    if (del_first_node(head, data, cmp, &previous))
        return 1;
    for (nodes_t *temp = (*head)->next; temp != NULL; temp = temp->next) {
        if (del_node(cmp, data, &previous, &temp))
            return 1;
        previous = temp;
    }
    return 0;
}

int del_matching_node(nodes_t **head, void *data, int (*cmp)(void *, void *))
{
    remove_in_list(head, data, cmp);
    return 0;
}
