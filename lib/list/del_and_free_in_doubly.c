/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include "mylist.h"

static int remove_first(nodes_t **head, void *id, int cmp(void *, void *))
{
    nodes_t *tmp;

    if ((*head)->previous == NULL && (*head)->next == NULL
        && cmp((*head)->data, id) == 0) {
        *head = NULL;
        return 1;
    }
    tmp = *head;
    if (cmp((*head)->data, id) == 0) {
        (*head) = (*head)->next;
        (*head)->previous = NULL;
        free(tmp->data);
        free(tmp);
        return 1;
    }
    return 0;
}

static int remove_ailleurs(void *id, int cmp(void *, void *), nodes_t *tmp)
{
    if (cmp(tmp->data, id) == 0) {
        tmp->previous->next = tmp->next;
        if (tmp->next == NULL)
            return 1;
        tmp->next->previous = tmp->previous;
        free(tmp->data);
        free(tmp);
        return 1;
    }
    return 0;
}

int remove_doubly_free(nodes_t **head, void *id, int cmp(void *, void *))
{
    if (*head == NULL)
        return 0;
    if (remove_first(head, id, cmp))
        return 1;
    for (nodes_t *tmp = (*head)->next; tmp; tmp = tmp->next)
        if (remove_ailleurs(id, cmp, tmp))
            return 1;
    return 0;
}
