/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include "my.h"
#include <stddef.h>

void *my_memset(void *ptr, int value, size_t num)
{
    unsigned char *bytePtr = (unsigned char *)ptr;
    size_t i;

    for (i = 0; i < num; i++)
        bytePtr[i] = (unsigned char)value;
    return ptr;
}
