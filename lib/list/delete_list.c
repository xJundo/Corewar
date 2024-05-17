/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include "mylist.h"

int delete_data(nodes_t **head)
{
    nodes_t *tmp;

    while (*head != NULL) {
        tmp = *head;
        *head = (*head)->next;
        free(tmp->data);
    }
    return 0;
}

int delete_node(nodes_t **head)
{
    nodes_t *tmp;

    while (*head != NULL) {
        tmp = *head;
        *head = (*head)->next;
        free(tmp);
    }
    return 0;
}

int delete_node_and_data(nodes_t **head)
{
    nodes_t *tmp;

    while (*head != NULL) {
        tmp = *head;
        *head = (*head)->next;
        if (tmp->data != NULL) {
            free(tmp->data);
            tmp->data = NULL;
        }
        free(tmp);
        tmp = NULL;
    }
    return 0;
}

int delete_list(nodes_t **head, const char *what)
{
    if (my_cmpstr("data", what) == 0)
        return delete_data(head);
    if (my_cmpstr("node", what) == 0)
        return delete_node(head);
    if (my_cmpstr("nd", what) == 0)
        return delete_node_and_data(head);
    return 0;
}
