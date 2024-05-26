/*
** EPITECH PROJECT, 2021
** minishell
** File description:
** first
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include "../include/mysh.h"

int separate(char ***envi, char *buffer)
{
    int redirection = 0;

    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == '|' || buffer[i] == '>' ||
        buffer[i] == '<' || buffer[i] == ';')
            redirection++;
    }
    if (redirection != 0) {
        redirect_init(*envi, buffer);
        return 0;
    }
    return check_builtin(envi, buffer);
}

char **size_envi(char **env, char **envi)
{
    int i = 0;

    for (i = 0; env[i] != NULL; i++);
    envi = malloc(i * sizeof(char *) + 1);
    return envi;
}

char *size_buffer(const char **argv, char *buffer)
{
    int i = 0;
    int total = 0;

    for (; argv[i] != NULL; i++)
        total += my_strlen(argv[i]);
    buffer = malloc(1 + total);
    return buffer;
}

int main(int argc, const char **argv, char **env)
{
    char **envi = NULL;
    char *buffer = NULL;
    size_t nb_read = 0;
    int return_value = 0;

    argc = (int) argc;
    envi = create_env(env);
    buffer = size_buffer(argv, buffer);
    if (envi == NULL)
        return 84;
    while (1) {
        if (isatty(0) == 1)
            my_printf("$> ");
        if (getline(&buffer, &nb_read, stdin) == -1)
            return return_value;
        if (my_strlen(buffer) > 1)
            return_value = separate(&envi, buffer);
    }
    return return_value;
}
