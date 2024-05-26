/*
** EPITECH PROJECT, 2023
** my_convert_binary
** File description:
** converts into binary
*/

#include "my.h"

void my_convert_binary(int nb, int *count)
{
    int bin[32];
    int i = 0;
    int j;

    if (nb == 0) {
        return;
    }
    while (nb != 0) {
        bin[i + 1] = nb % 2;
        nb = nb / 2;
    }
    for (j = i - 1; j >= 0; j--) {
        my_put_nbr(bin[j], count);
    }
}
