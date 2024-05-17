/*
** EPITECH PROJECT, 2023
** my_strcmp.c
** File description:
** return 1, 0, -1 if s1 is bigger, equal, smaller
*/

#include "mylist.h"

int my_strcmp_void(void *s1, void *s2)
{
    int i = 0;

    while (((char *)s1)[i] != '\0' && ((char *)s2)[i] != '\0') {
        if (((char *)s1)[i] < ((char *)s2)[i])
            return -1;
        if (((char *)s1)[i] > ((char *)s2)[i])
            return ((char *)s1)[i]-((char *)s2)[i];
        i++;
    }
    return ((char *)s1)[i] - ((char *)s2)[i];
}
