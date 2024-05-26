/*
** EPITECH PROJECT, 2023
** base_flag
** File description:
** base flag of printf
*/
#include "my.h"

void decimal(const char *format, va_list list_arg, int i, int *count)
{
    if (format[i] == '%' && (format[i + 1] == 'd' || format[i + 1] == 'i')) {
        my_put_nbr(va_arg(list_arg, long), count);
    } else if (format[i] == '%' && format[i + 1] == 'u') {
        my_printf_u(va_arg(list_arg, long), count);
    }
}

void string_s(const char *format, va_list list_arg, int i, int *count)
{
    if (format[i] == '%' && format[i + 1] == 's') {
        my_putstr(va_arg(list_arg, char *), count);
    }
}

void character_c(const char *format, va_list list_arg, int i, int *count)
{
    if (format[i] == '%' && format[i + 1] == 'c') {
        my_putchar(va_arg(list_arg, int), count);
    }
}

void percent(const char *format, int i, int *count)
{
    if (format[i] == '%' && format[i + 1] == '%') {
        my_putchar('%', count);
    }
}

void number_n(const char *format, va_list list_arg, int i, int *count)
{
    if (format[i] == '%' && format[i + 1] == 'n') {
        my_printf_n(va_arg(list_arg, int *), count);
    }
}
