/*
** EPITECH PROJECT, 2023
** my_printf_p
** File description:
** displays in hex arg ptr
*/
#include "my.h"

void my_printf_p(long int nb, int *count)
{
    my_putchar('0', count);
    my_putchar('x', count);
    my_convert_hexa(nb, count);
}
