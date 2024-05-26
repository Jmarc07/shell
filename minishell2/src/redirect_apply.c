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
#include <fcntl.h>
#include "../include/mysh.h"

void red_error(int fd, char *name)
{
    if (fd == -1) {
        free(name);
    }
}

static void norm(int fd, char *name)
{
    if (fd == -1) {
        free(name);
        return;
    }
}

void redirect_double(char **env, char *first_part,
    char *second_part, int append)
{
    char *name = get_filename(second_part);
    int fd = open_file(name, append);
    int save = saves();

    if (!name) {
        return;
    }
    norm(fd, name);
    if (save == -1 || redirect(fd) == -1) {
        close(fd);
        free(name);
        return;
    }
    check_builtin(&env, first_part);
    if (redirect(save) == -1) {
        return;
    }
    restore(save);
    close(fd);
    free(name);
}
