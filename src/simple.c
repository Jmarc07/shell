/*
** EPITECH PROJECT, 2024
** delivery [WSL: Ubuntu]
** File description:
** simple
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <fcntl.h>
#include "../include/mysh.h"

void red_errors(int fd, char *name)
{
    if (fd == -1) {
        free(name);
        return;
    }
}

int open_files(char *filename)
{
    return open(filename, O_WRONLY | O_TRUNC | O_CREAT,
                S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
}

void redirect_simple(char **env, char *first_part, char *second_part)
{
    char *name = get_filename(second_part);
    int fd = open_files(name);
    int save = saves();

    if (!name) {
        return;
    }
    red_errors(fd, name);
    if (save == -1 || redirect(fd) == -1) {
        close(fd);
        free(name);
        return;
    }
    check_builtin(&env, first_part);
    restore(save);
    close(fd);
    free(name);
}
