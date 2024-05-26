/*
** EPITECH PROJECT, 2023
** my_printf_f
** File description:
** test
*/
#include "my.h"

void recursive_f(int *ptr, int i, int *count)
{
    if (ptr[i + 1] >= 5) {
        if (ptr[i] == 9) {
            recursive_f(ptr, i - 1, count);
            ptr[i] = 0;
        } else
            ptr[i] = ptr[i] + 1;
    }
}

void print_tab(int *tab, int i, int *count)
{
    recursive_f(tab, i - 2, count);
    for (i = 0; i < 6; i++) {
        my_put_nbr(tab[i], count);
    }
}

void my_printf_f(double nb, int *count)
{
    int integer = (int) nb;
    double temp = nb;
    int i;
    int tab[7];

    my_put_nbr(integer, count);
    my_putchar('.', count);
    if (nb < 0)
        temp *= -1;
    integer = (double) integer;
    temp -= integer;
    for (i = 0; i < 7; i++) {
        temp = (temp * 10) + 0.00000001;
        integer = (int) temp;
        integer %= 10;
        tab[i] = integer;
    }
    print_tab(tab, i, count);
}
