/*
** EPITECH PROJECT, 2021
** minishell
** File description:
** first
*/
#include <unistd.h>
#include <stdlib.h>
#include "../include/mysh.h"

char *copy_path(char *buffer, char *path)
{
    int b = 0;

    for (int i = 0; i != my_strlen(buffer); i++) {
        path[i + 9] = buffer[i];
    }
    while (buffer[b] != ' ' && path[b + 9] != '\0') {
        b++;
    }
    while (path[b + 9] == '\n' || path[b + 9] == '\0' || path[b + 9] == ' ') {
        b--;
    }
    path[b + 9 + 1] = '\0';
    if (access(path, X_OK) != 0) {
        for (int b = 0; buffer[b] != '\0' && buffer[b] != ' '; b++)
            path[b] = buffer[b];
        path[b + 1] = '\0';
        return path;
    }
    return (path);
}

int count_args(char *buffer, char sep)
{
    int nbr = 1;

    for (int i = 0; buffer[i] != '\0'; i++)
        if (buffer[i] != '\0' && buffer[i] != sep && buffer[i + 1] == sep)
            nbr++;
    return (nbr);
}

void remove_space(char *buffer)
{
    int i = 0;

    for (; buffer[i] != '\0'; i++) {
        if (buffer[i] == '\t')
            buffer[i] = ' ';
    }
    for (i = 0; buffer[i] == ' '; i++);
    for (; i > 0; i--) {
        for (int curser = 0; buffer[curser] != '\0'; curser++)
            buffer[curser] = buffer[curser + 1];
    }
    for (i = my_strlen(buffer) - 1; i > 0 && (buffer[i] == ' ' ||
    buffer[i] == '\t' || buffer[i] == '\n'); i--) {
        buffer[i] = '\n';
    }
}

void coon(int i, int arg_n, char *buffer, char **divised_line)
{
    for (; i != arg_n; i++)
        divised_line[i] = malloc(sizeof(char) * my_strlen(buffer));
    remove_space(buffer);
}

char **copy_all(char *buffer)
{
    int arg_n = count_args(buffer, ' ') + count_args(buffer, '\t');
    char **divised_line = malloc(my_strlen(buffer) * arg_n);
    int j = 0;
    int i = 0;
    int k = 0;

    coon(i, arg_n, buffer, divised_line);
    for (i = 0; buffer[i] != '\n' && buffer[i] != '\0'; i++) {
        while (buffer[i] == ' ' && buffer[i + 1] == ' ')
            i++;
        if (buffer[i] == ' ') {
            i++;
            j++;
            k = 0;
        }
        divised_line[j][k] = buffer[i];
        k++;
    }
    divised_line[j + 1] = NULL;
    return (divised_line);
}
