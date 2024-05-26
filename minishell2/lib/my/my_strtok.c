/*
** EPITECH PROJECT, 2024
** delivery [WSL: Ubuntu]
** File description:
** my_strtok
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *next_tok(char delim, char *current_position)
{
    char *token_start = current_position;

    while (*current_position && *current_position != delim) {
        current_position++;
    }
    if (*current_position == delim) {
        *current_position = '\0';
        current_position++;
    } else {
        current_position = NULL;
    }
    return token_start;
}

char *my_strtok(char *str, char delim)
{
    static char *current_position = NULL;

    if (str != NULL) {
        current_position = str;
    } else if (current_position == NULL || *current_position == '\0') {
        return NULL;
    }
    while (*current_position == delim) {
        current_position++;
    }
    if (*current_position == '\0') {
        return NULL;
    }
    return next_tok(delim, current_position);
}
