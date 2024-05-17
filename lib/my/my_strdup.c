/*
** EPITECH PROJECT, 2023
** my_strdup
** File description:
** Returns a duplication of a string (src)
*/

#include "my.h"

char *my_strdup(char const *src)
{
    char *result;
    int len_src = my_strlen(src);
    int i = 0;

    result = my_malloc(sizeof(char) * (len_src + 1), 1);
    for (; i < len_src; i++) {
        result[i] = src[i];
    }
    result[i] = '\0';
    return result;
}
