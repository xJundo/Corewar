/*
** EPITECH PROJECT, 2023
** my_put_nbr
** File description:
** Prints a number (nb) in stdout
*/

#include "my.h"

static char *put_str_nb(double nb, int len_nb)
{
    char nb_str[len_nb];
    double figure_temp = nb;

    for (int i = 0; i < len_nb; i++) {
        nb_str[len_nb - i - 1] = 48 + (figure_temp % 10);
        figure_temp = (figure_temp - (figure_temp % 10)) / 10;
    }
    nb_str[len_nb] = '\0';
    return my_strdup(nb_str);
}

char *my_put_nbr_double(double nb)
{
    int len_nb = 1;
    double temp_nb = nb;

    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    while ((temp_nb / 10) != 0) {
        len_nb = len_nb + 1;
        temp_nb = temp_nb / 10;
    }
    if (nb == DBL_MIN) {
        return "2.225074e-308";
    } else
        return put_str_nb(nb, len_nb);
}
