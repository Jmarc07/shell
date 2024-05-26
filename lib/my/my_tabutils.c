/*
** EPITECH PROJECT, 2023
** B-PSU-200-TLS-2-1-42sh-jean-marc.naounou
** File description:
** my_tablen
*/

#include <stdlib.h>
#include "my.h"

#include <stdlib.h>
#include <string.h>

int my_tablen(char **tab)
{
    int len = 0;

    if (tab == NULL) {
        return 0;
    }
    while (tab[len] != NULL) {
        len++;
    }
    return len;
}

void my_tabcpy(char ***dest, char **src)
{
    int i = 0;

    while (src[i] != NULL) {
        (*dest)[i] = my_strdup(src[i]);
        i++;
    }
    (*dest)[i] = NULL;
}

char **my_tabdup(char **tab)
{
    int len = my_tablen(tab);
    char **new_tab = malloc(sizeof(char *) * (len + 1));

    if (new_tab == NULL)
        return NULL;
    for (int i = 0; i < len; i++)
        new_tab[i] = my_strdup(tab[i]);
    new_tab[len] = NULL;
    return new_tab;
}

void my_tabfree(char **tab)
{
    if (tab == NULL)
        return;
    for (int i = 0; tab[i] != NULL; i++)
        free(tab[i]);
    free(tab);
}
