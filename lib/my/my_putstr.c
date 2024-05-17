/*
** EPITECH PROJECT, 2023
** my_putstr
** File description:
** Prints a string (str) in stdout
*/

#include "my.h"
#include <unistd.h>

int my_putstr(char const *str)
{
    write(1, str, my_strlen(str));
    return 0;
}
