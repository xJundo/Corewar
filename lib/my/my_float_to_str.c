/*
** EPITECH PROJECT, 2023
** my_getnbr
** File description:
** get str in number
*/

#include "my.h"

char *my_float_to_str(float nb, int precision)
{
    float temp = nb - (int)nb;
    int len_int = my_strlen(my_str_nbr(nb));
    int n = 8 + len_int;
    char *str = malloc(sizeof(char) * (n + 1));
    int i = 0;
    int temp2;

    my_memset(str, 0, n + 1);
    my_strcat(str, my_str_nbr((int)nb));
    my_strcat(str, ".");
    if (temp < 0)
        temp *= -1;
    while (i < precision && i < 6) {
        temp *= 10;
        temp2 = temp;
        my_strcat(str, my_str_nbr(temp2));
        temp -= temp2;
        i++;
    }
    return str;
}
