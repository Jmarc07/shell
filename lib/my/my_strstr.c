/*
** EPITECH PROJECT, 2024
** delivery [WSL: Ubuntu]
** File description:
** my_strstr
*/

#include <stdio.h>

int str_prefix(const char *str, const char *to_find)
{
    while (*str && *to_find && *str == *to_find) {
        str++;
        to_find++;
    }
    return *to_find == '\0';
}

char *my_strstr(const char *str, const char *to_find)
{
    if (!*to_find) {
        return (char *)str;
    }
    for (; *str; str++) {
        if (*str == *to_find && str_prefix(str, to_find)) {
            return (char *)str;
        }
    }
    return NULL;
}
