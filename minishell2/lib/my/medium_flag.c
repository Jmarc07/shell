/*
** EPITECH PROJECT, 2023
** medium_flag
** File description:
** medium flag of printf
*/
#include "my.h"

void binary_b(const char *format, va_list list_arg, int i, int *count)
{
    if (format[i] == '%' && format[i + 1] == 'b') {
        my_convert_binary(va_arg(list_arg, int), count);
    }
}

void hexadecimal_x(const char *format, va_list list_arg, int i, int *count)
{
    if (format[i] == '%' && (format[i + 1] == 'x' || format[i + 1] == 'X')) {
        my_convert_hexa(va_arg(list_arg, long int), count);
    }
}

void octal_o(const char *format, va_list list_arg, int i, int *count)
{
    if (format[i] == '%' && format[i + 1] == 'o') {
        my_convert_octal(va_arg(list_arg, int), count);
    }
}

void pointer_p(const char *format, va_list list_arg, int i, int *count)
{
    if (format[i] == '%' && format[i + 1] == 'p') {
        my_printf_p(va_arg(list_arg, long int), count);
    }
}

void float_f(const char *format, va_list list_arg, int i, int *count)
{
    if (format[i] == '%' && format[i + 1] == 'f') {
        my_printf_f(va_arg(list_arg, double), count);
    }
}
