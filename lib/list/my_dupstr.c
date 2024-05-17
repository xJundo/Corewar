/*
** EPITECH PROJECT, 2023
** my_strdup
** File description:
** Returns a duplication of a string (src)
*/

#include <stdlib.h>
#include "mylist.h"

char *my_dupstr(char const *src)
{
    char *result;
    int len_src = my_lenstr(src);
    int i = 0;

    result = malloc(sizeof(char) * (len_src + 1));
    for (; i < len_src; i++) {
        result[i] = src[i];
    }
    result[i] = '\0';
    return result;
}
