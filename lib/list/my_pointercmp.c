/*
** EPITECH PROJECT, 2023
** my_strcmp.c
** File description:
** return 1, 0, -1 if s1 is bigger, equal, smaller
*/

#include "mylist.h"

int my_pointercmp(void *s1, void *s2)
{
    if (s1 > s2)
        return 1;
    if (s1 == s2)
        return 0;
    return -1;
}
