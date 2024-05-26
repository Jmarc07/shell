/*
** EPITECH PROJECT, 2024
** delivery
** File description:
** my_strchr
*/

#include <stdio.h>

char *my_strchr(const char *s, int c)
{
    while (*s != '\0') {
        if (*s == (char)c) {
            return (char *)s;
        }
        s++;
    }
    return NULL;
}
