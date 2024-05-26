/*
** EPITECH PROJECT, 2024
** delivery [WSL: Ubuntu]
** File description:
** strcmp_in
*/

#include <unistd.h>
#include <stdlib.h>
#include "../include/mysh.h"

int my_strcmp_uncomplete(char *str, char *cmp)
{
    int cnt = 0;

    for (; str[cnt] != '\0'; cnt++) {
        if (str[cnt] != cmp[cnt]) {
            return (84);
        }
    }
    return (1);
}
