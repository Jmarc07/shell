/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** main my_printf
*/
#include "my.h"

void flag(const char *format, va_list list_arg, int *count)
{
    int i = 0;

    while (format[i] != '\0') {
        decimal(format, list_arg, i, count);
        string_s(format, list_arg, i, count);
        character_c(format, list_arg, i, count);
        percent(format, i, count);
        hexadecimal_x(format, list_arg, i, count);
        binary_b(format, list_arg, i, count);
        octal_o(format, list_arg, i, count);
        float_f(format, list_arg, i, count);
        pointer_p(format, list_arg, i, count);
        number_n(format, list_arg, i, count);
        if (format[i] != '%')
            my_putchar(format[i], count);
        else
            i++;
        i++;
    }
}

int my_printf(const char *format, ...)
{
    va_list list_arg;
    int count = 0;

    va_start(list_arg, format);
    flag(format, list_arg, &count);
    va_end(list_arg);
    return 0;
}
