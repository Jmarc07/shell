/*
** EPITECH PROJECT, 2023
** my_convert_hexa
** File description:
** converts an integer to an hexadecimal
*/
#include "my.h"

void my_convert_hexa(long int nb, int *count)
{
    long int temp;
    char tab[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
        'a', 'b', 'c', 'd', 'e', 'f'};

    if (nb == 0) {
        my_putchar(48, count);
    }
    if (nb < 0) {
        temp = 4294967296 + nb;
        my_convert_hexa(temp, count);
    } else {
        temp = nb % 16;
        nb = nb / 16;
        if (nb != 0) {
            my_convert_hexa(nb, count);
        }
        my_putchar(tab[temp], count);
    }
}
