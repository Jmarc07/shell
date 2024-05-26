/*
** EPITECH PROJECT, 2023
** my_putstr
** File description:
** Write a function that displays, one-by-one, the characters of a string.
*/
#include "my.h"

int my_putstr(char const *str, int *count)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i], count);
        i++;
    }
    return 0;
}
