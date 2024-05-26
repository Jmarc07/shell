/*
** EPITECH PROJECT, 2024
** minishell2
** File description:
** remove_env
*/

#include <stdlib.h>
#include "../include/mysh.h"

char **create_new_env(char **env, int env_len, int index)
{
    int new_env_len = (index != -1) ? env_len - 1 : env_len;
    char **new_env = malloc(sizeof(char *) * (new_env_len + 1));
    int j = 0;

    if (new_env == NULL) {
        exit(84);
    }
    for (int i = 0; i < env_len; i++) {
        if (i != index) {
            new_env[j] = env[i];
            j++;
        } else {
            free(env[i]);
        }
    }
    new_env[new_env_len] = NULL;
    return new_env;
}

char **remove_env(char **env, const char *key)
{
    int key_len = strlen(key);
    int j = 0;

    for (int i = 0; env[i] != NULL; i++) {
        if (my_strncmp(env[i], key, key_len) != 0 || env[i][key_len] != '=') {
            env[j] = env[i];
            j++;
        } else {
            free(env[i]);
        }
    }
    env[j] = NULL;
    return env;
}
