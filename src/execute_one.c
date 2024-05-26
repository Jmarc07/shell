/*
** EPITECH PROJECT, 2021
** minishell
** File description:
** first
*/

#include "../include/mysh.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <string.h>
#include <sys/wait.h>


static void display_signal(int status)
{
    int termsig = 0;
    int i = 128;

    if (WIFSIGNALED(status) != 0) {
        termsig = WTERMSIG(status);
        if (termsig != 0 && termsig != SIGFPE) {
            my_printf(strsignal(termsig));
        }
        if (termsig == SIGFPE) {
            my_printf("Floating exception");
        }
        if (WCOREDUMP(status) != 0)
            my_printf(" (core dumped)");
        my_printf("\n");
        exit(termsig + i);
    }
}

void exe(int status)
{
    wait(&status);
    if (WIFEXITED(status)) {
        WEXITSTATUS(status);
    } else if (WIFSIGNALED(status)) {
        display_signal(status);
    }
}

int execute(char **env, char **divised_line, char *buffer)
{
    pid_t pid = fork();
    int status = 0;
    char path[128] = "/usr/bin/";

    if (pid == 0) {
        my_strcpy(path, copy_path(buffer, path));
        execve(path, divised_line, env);
        error_execve(divised_line[0]);
        exit(1);
    } else if (pid < 0) {
        perror("fork");
        return 1;
    }
    exe(status);
    return status;
}

void error_execve(char *opt)
{
    my_printf("%s: Command not found.\n", opt);
}

int check_builtin(char ***env, char *buffer)
{
    char **divised_line = copy_all(buffer);

    if (my_strcmp(divised_line[0], "env\n") == 0 ||
    my_strcmp(divised_line[0], "setenv\n") == 0 ||
    my_strcmp(divised_line[0], "unsetenv\n") == 0 ||
    my_strcmp(divised_line[0], "exit\n") == 0 ||
    my_strcmp(divised_line[0], "cd\n") == 0) {
        specifique_function(env, divised_line);
    } else {
        return execute(*env, divised_line, buffer);
    }
    return 0;
}
