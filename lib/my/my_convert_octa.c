/*
** EPITECH PROJECT, 2023
** convert octa
** File description:
** flag -o
*/
#include <string.h>
#include <stdarg.h>
#include "my.h"

void my_convert_octal(int nb, int *count)
{
    int reste = 0;
    int base = 1;
    int octal = 0;

    while (nb > 0) {
        reste = nb % 8;
        octal = octal + reste * base;
        nb = nb / 8;
        base = base * 10;
    }
    my_put_nbr(octal, count);
}
