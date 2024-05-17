/*
** EPITECH PROJECT, 2023
** my_getnbr
** File description:
** get str in number
*/

#include "my.h"

float my_str_to_float(char *str)
{
    float n = 0.0;
    float temp = 10.0;

    n += my_getnbr(str);
    str = &str[my_strlen(my_str_nbr(my_getnbr(str))) + 1];
    for (int i = 0; str[i]; i++) {
        if (n < 0)
            n -= (str[i] - '0') / temp;
        else
            n += (str[i] - '0') / temp;
        temp = temp * 10.0;
    }
    return n;
}
