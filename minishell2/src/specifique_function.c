/*
** EPITECH PROJECT, 2021
** minishell
** File description:
** first
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include "../include/mysh.h"


void my_exit(char **arg)
{
    int arg_n = 0;

    for (; arg[arg_n] != NULL; arg_n++);
    if (arg_n != 1) {
        my_printf("exit: Expression Syntax.\n");
        return;
    }
    exit(0);
}

void specifique_function(char ***env, char **divised_line)
{
    if (my_strcmp(divised_line[0], "exit\0") == 0 ||
    my_strcmp(divised_line[0], "exit\n") == 0)
        my_exit(divised_line);
    if (my_strcmp(divised_line[0], "cd") == 0 ||
    my_strcmp(divised_line[0], "cd\n") == 0)
        display_error_cd(*env, divised_line);
    if (my_strcmp(divised_line[0], "env") == 0 ||
    my_strcmp(divised_line[0], "env\n") == 0)
        print_env(*env);
    if (my_strcmp(divised_line[0], "setenv") == 0 ||
    my_strcmp(divised_line[0], "setenv\n") == 0)
        my_setenv(env, divised_line);
    if (my_strcmp(divised_line[0], "unsetenv") == 0 ||
    my_strcmp(divised_line[0], "unsetenv\n") == 0)
        my_unsetenv(env, divised_line);
}
