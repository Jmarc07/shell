/*
** EPITECH PROJECT, 2024
** strdup
** File description:
** my_strdup
*/

#include <stdlib.h>
#include "my.h"

char *my_strdup(char const *src)
{
    int len = my_strlen(src) + 1;
    char *copy = (char *) malloc(len * sizeof(char));

    for (int i = 0; i < len; i++) {
        copy[i] = src[i];
    }
    return copy;
}
