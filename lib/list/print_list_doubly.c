/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include "mylist.h"

void print_list_doubly(nodes_t **head)
{
    if (*head == NULL) {
        my_strput("EMPTY list\n");
        return;
    }
    for (nodes_t *tmp = *head; tmp; tmp = tmp->next) {
        if (tmp->previous == NULL)
            my_strput("P NULL");
        else {
            my_strput("P ");
            print_typed_value(tmp->previous->data, tmp->previous->type);
        }
        my_strput("<---") & print_typed_value(tmp->data, tmp->type)
        & my_strput("--->");
        if (tmp->next == NULL)
            my_strput("NULL N");
        else {
            print_typed_value(tmp->next->data, tmp->next->type);
            my_strput(" N\n");
        }
    }
}
