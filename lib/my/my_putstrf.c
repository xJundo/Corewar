/*
** EPITECH PROJECT, 2023
** my_putstr
** File description:
** Prints a string (str) in stdout
*/

#include "my.h"

int my_putstrf(int fd, char const *str)
{
    write(fd, str, my_strlen(str));
    return 0;
}
