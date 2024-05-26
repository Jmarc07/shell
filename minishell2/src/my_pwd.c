/*
** EPITECH PROJECT, 2024
** delivery [WSL: Ubuntu]
** File description:
** my_pwd
*/

#include <stdlib.h>
#include <unistd.h>
#include "../include/mysh.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

char *pwd(const char *path, const char *prefix)
{
    char *result = malloc(my_strlen(prefix) + my_strlen(path) + 1);

    if (result != NULL) {
        my_strcpy(result, prefix);
        my_strcat(result, path);
    }
    return result;
}
