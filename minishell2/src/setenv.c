/*
** EPITECH PROJECT, 2021
** minishell
** File description:
** first
*/

#include "../include/mysh.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void print_env(char **env)
{
    for (int i = 0; env[i] != NULL; i++) {
        my_printf("%s\n", env[i]);
    }
}

int my_setenv_checks(char **env, char **arg, int arg_n)
{
    if (arg_n == 1) {
        print_env(env);
        return 1;
    }
    if (arg_n > 3) {
        my_printf("setenv: Too many arguments.\n");
        return 1;
    }
    if (!my_str_isalpha(arg[1])) {
        my_printf("setenv: Var name must contain alphanumeric characters.\n");
        return 1;
    }
    return 0;
}

void my_setenv(char ***env, char **arg)
{
    int arg_n = 0;

    while (arg[arg_n] != NULL) {
        arg_n++;
    }
    if (arg_n < 2) {
        printf("setenv: Too few arguments.\n");
        return;
    }
    if (arg_n > 3) {
        printf("setenv: Too many arguments.\n");
        return;
    }
    *env = remove_env(*env, arg[1]);
    if (arg_n == 2) {
        *env = add_env(*env, arg[1], "");
    } else if (arg_n == 3) {
        *env = add_env(*env, arg[1], arg[2]);
    }
}

void my_unsetenv(char ***env, char **arg)
{
    int arg_n = 0;

    for (; arg[arg_n] != NULL; arg_n++);
    if (arg_n < 2) {
        my_printf("unsetenv: Too few arguments.\n");
        return;
    }
    if (arg_n > 2) {
        my_printf("unsetenv: Too many arguments.\n");
        return;
    }
    *env = remove_env(*env, arg[1]);
}
