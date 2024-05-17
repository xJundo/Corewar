/*
** EPITECH PROJECT, 2023
** my_strcmp.c
** File description:
** return 1, 0, -1 if s1 is bigger, equal, smaller
*/

#include "mylist.h"

int my_intcmp_void(void *data, void *ref)
{
    if (*(int *)data == *(int *)ref)
        return 0;
    if (*(int *)data < *(int *)ref)
        return -1;
    if (*(int *)data > *(int *)ref)
        return 1;
}
