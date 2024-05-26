/*
** EPITECH PROJECT, 2023
** B-PSU-200-TLS-2-1-42sh-jean-marc.naounou
** File description:
** env
*/

#include <stdlib.h>
#include "../include/mysh.h"

char **create_env(char **env)
{
    char **new_env = my_tabdup(env);

    return new_env;
}

static void now(char **new_env)
{
    if (!new_env) {
        exit(84);
    }
}

char **add_env(char **env, char *key, char *value)
{
    int envlen = my_tablen(env);
    char **new_env = malloc(sizeof(char *) * (envlen + 2));
    int keylen = my_strlen(key);
    int valuelen = my_strlen(value);

    now(new_env);
    for (int i = 0; i < envlen; i++) {
        new_env[i] = env[i];
    }
    new_env[envlen] = malloc(keylen + valuelen + 2);
    if (!new_env[envlen]) {
        exit(84);
    }
    my_strcpy(new_env[envlen], key);
    my_strcat(new_env[envlen], "=");
    my_strcat(new_env[envlen], value);
    new_env[envlen + 1] = NULL;
    free(env);
    return new_env;
}

int get_env_index(char **env)
{
    int i = 0;

    while (env[i] != NULL) {
        i++;
    }
    return i;
}
