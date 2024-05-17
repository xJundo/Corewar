/*
** EPITECH PROJECT, 2023
** HEADER_NAME
** File description:
** HEADER_NAME
*/

#include "my.h"
#include "../../include/mylist.h"

void push_f_doublym(nodes_t **head, void *data, type_t type)
{
    nodes_t *new = malloc(sizeof(nodes_t));

    new->data = data;
    new->type = type;
    new->previous = NULL;
    new->next = *head;
    if (*head != NULL)
        (*head)->previous = new;
    *head = new;
    return;
}

void *my_malloc(size_t size, int alloc)
{
    void *ptr = NULL;
    static nodes_t *list = NULL;

    if (size != 0) {
        ptr = malloc(size);
        my_memset(ptr, 0, size);
    }
    if (alloc == 1)
        push_f_doublym(&list, ptr, UNKNOW);
    else {
        delete_list(&list, "nd");
        list = NULL;
    }
    return ptr;
}
