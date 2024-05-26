/*
** EPITECH PROJECT, 2023
** my_putnbr day3
** File description:
** display number
*/
#include "my.h"

int my_put_nbr(int nb, int *count)
{
    int nb2;

    if (nb < 0){
        my_putchar('-', count);
        nb = nb * (-1);
    }
    if (nb >= 10) {
        nb2 = nb % 10;
        nb = nb / 10;
        my_put_nbr(nb, count);
        my_putchar((nb2 + 48), count);
    } else {
        my_putchar((nb + 48), count);
    }
    return (0);
}
