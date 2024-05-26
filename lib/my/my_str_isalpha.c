/*
** EPITECH PROJECT, 2023
** my_strisalpha
** File description:
** my_strisalpha
*/

#include "my.h"

int is_lowcase(char c)
{
    return (c > 96 && c < 122);
}

int is_upercase(char c)
{
    return (c > 64 && c < 91);
}

int my_str_isalpha(char const *str)
{
    for (int i = 0; i < my_strlen(str); i++)
        if (!is_lowcase(str[i]) && !is_upercase(str[i]))
            return 0;
    return 1;
}
