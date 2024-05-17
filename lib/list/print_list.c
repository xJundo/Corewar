/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include "mylist.h"

int print_typed_value(void *data, type_t type)
{
    if (type == CHAR)
        my_charput(*(char *)data);
    if (type == INT)
        my_nbr_put(*(int *)data);
    if (type == STR)
        my_strput((char *)data);
    if (type == UNKNOW)
        my_strput(print_adress((unsigned long int)data, "0123456789abcdef"));
    return 0;
}

int print_list(nodes_t **head)
{
    nodes_t *temp;

    if (*head == NULL) {
        my_strput("EMPTY list\n");
        return 0;
    }
    temp = *head;
    while (temp != NULL) {
        print_typed_value(temp->data, temp->type);
        my_strput("---->");
        temp = temp->next;
    }
    my_strput("NULL\n");
    return 1;
}
