/*
** EPITECH PROJECT, 2024
** delivery [WSL: Ubuntu]
** File description:
** pipe
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <fcntl.h>
#include "../include/mysh.h"

void use_pipe(char **env, char *second_part, int tube[2])
{
    pid_t pid = fork();

    if (pid == 0) {
        close(tube[1]);
        dup2(tube[0], STDIN_FILENO);
        close(tube[0]);
        for (int i = 0; second_part[i] != '\0'; i++) {
            second_part[i] = second_part[i + 1];
        }
        check_builtin(&env, second_part);
        exit(1);
    } else {
        wait(NULL);
    }
}

void piping(char **env, char *first_part, char *second_part)
{
    int tube[2];
    pid_t pid = fork();

    pipe(tube);
    if (pid == 0) {
        close(tube[0]);
        dup2(tube[1], STDOUT_FILENO);
        check_builtin(&env, first_part);
        exit(1);
    } else {
        use_pipe(env, second_part, tube);
    }
}
