/*
** EPITECH PROJECT, 2023
** flag u
** File description:
** flag u
*/
#include "my.h"

int my_printf_u(unsigned int nb, int *count)
{
    unsigned int nb2;

    if (nb >= 10) {
        nb2 = nb % 10;
        nb = nb / 10;
        my_put_nbr(nb, count);
        my_putchar((nb2 + 48), count);
    } else {
        my_putchar((nb + 48), count);
    }
    return 0;
}
