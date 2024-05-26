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

void split_buffer(char *buffer, char *first_part, char *second_part)
{
    int i = 0;
    int start = 0;

    while (buffer[i] && buffer[i] != '|' &&
    !(buffer[i] == '>' && buffer[i + 1] == '>') &&
        !(buffer[i] == '<' && buffer[i + 1] == '<') && buffer[i] != ';') {
        first_part[i] = buffer[i];
        i++;
    }
    first_part[i] = '\0';
    start = i;
    while (buffer[i]) {
        second_part[i - start] = buffer[i];
        i++;
    }
    second_part[i - start] = '\0';
}

void find_redirect_next(char **env, char *first_part, char *second_part)
{
    if (second_part[0] == ';') {
        separate_line(env, first_part, second_part);
        return;
    }
    if (second_part[0] == '|') {
        piping(env, first_part, second_part);
        return;
    }
}

void find_redirect(char **env, char *first_part, char *second_part)
{
    int i = 0;

    if (second_part[i] == '<') {
        return;
    }
    if (second_part[i] == '>' && second_part[i + 1] != '>') {
        redirect_simple(env, first_part, second_part);
        return;
    }
    find_redirect_next(env, first_part, second_part);
}

void allocate_parts(char **first_part, char **second_part, char *buffer)
{
    size_t len = my_strlen(buffer) + 1;

    *first_part = malloc(len);
    *second_part = malloc(len);
    if (!first_part || !second_part) {
        perror("malloc");
        free(first_part);
        free(second_part);
        exit(EXIT_FAILURE);
    }
}

void redirect_init(char **env, char *buffer)
{
    char *first_part;
    char *second_part;

    allocate_parts(&first_part, &second_part, buffer);
    if (!first_part || !second_part) {
        return;
    }
    split_buffer(buffer, first_part, second_part);
    find_redirect(env, first_part, second_part);
    free(first_part);
    free(second_part);
}
