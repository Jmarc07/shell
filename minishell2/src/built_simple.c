/*
** EPITECH PROJECT, 2024
** delivery [WSL: Ubuntu]
** File description:
** built_simple
*/

#include <fcntl.h>
#include "../include/mysh.h"

char *get_filename(char *second_part)
{
    char *name;
    int i = 1;

    while (second_part[i] == ' ') {
        i++;
    }
    name = my_strdup(second_part + i);
    return name;
}

int saves(void)
{
    return dup(STDOUT_FILENO);
}

int open_file(char *filename, int append)
{
    int flags = O_WRONLY | O_CREAT;

    if (filename == NULL || filename[0] == '\0') {
        return -1;
    }
    if (append) {
        flags |= O_APPEND;
    } else {
        flags |= O_TRUNC;
    }
    return open(filename, flags,
                S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
}

int redirect(int fd)
{
    if (fd == -1) {
        return -1;
    }
    return dup2(fd, STDOUT_FILENO);
}

void restore(int save_fd)
{
    if (save_fd != -1) {
        dup2(save_fd, STDOUT_FILENO);
        close(save_fd);
    }
}
