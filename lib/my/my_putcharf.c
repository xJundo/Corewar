/*
** EPITECH PROJECT, 2023
** my_putchar
** File description:
** Prints a char in the stdout
*/

#include <unistd.h>

void my_putcharf(int fd, char c)
{
    write(fd, &c, 1);
}
