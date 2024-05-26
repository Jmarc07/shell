/*
** EPITECH PROJECT, 2021
** minishell
** File description:
** first
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <errno.h>
#include "../include/mysh.h"

// void process_remaining_commands(char **env, char *commands)
// {
//     char *next_command = commands;
//     char *next_semicolon;
//     next_semicolon = my_strchr(next_command, ';');

//     while (*next_command != '\0') {
//         if (next_semicolon != NULL) {
//             *next_semicolon = '\0';
//         }
//         check_builtin(&env, next_command);
//         if (next_semicolon != NULL) {
//             next_command = next_semicolon + 1;
//             next_semicolon = my_strchr(next_command, ';');
//         } else {
//             break;
//         }
//     }
// }

// void separate_line(char **env, char *first_part, char *second_part)
// {
//     char *semicolon = my_strchr(second_part, ';');

//     if (semicolon != NULL) {
//         *semicolon = '\0';
//         check_builtin(&env, first_part);
//         process_remaining_commands(env, semicolon + 1);
//     } else {
//         check_builtin(&env, first_part);
//     }
// }

void process_remaining_commands(char **env, char *commands)
{
    char *next_command = commands;
    char *next_semicolon;

    while (*next_command != '\0') {
        next_semicolon = my_strchr(next_command, ';');
        if (next_semicolon != NULL) {
            *next_semicolon = '\0';
        }
        if (*next_command != '\0') {
            check_builtin(&env, next_command);
        }
        if (next_semicolon != NULL) {
            next_command = next_semicolon + 1;
        } else {
            break;
        }
    }
}

void separate_line(char **env, char *first_part, char *second_part)
{
    char *semicolon = my_strchr(second_part, ';');

    if (semicolon != NULL) {
        *semicolon = '\0';
        check_builtin(&env, first_part);
        process_remaining_commands(env, semicolon + 1);
    } else {
        check_builtin(&env, first_part);
    }
}

void cond(ssize_t read, char *line)
{
    if (read == -1 && errno != 0) {
        perror("getline");
    }
    free(line);
}

void voice(const char *second_part, int i)
{
    while (second_part[i] == ' ') {
        i++;
    }
}

void double_right(const char *second_part)
{
    int i = 2;
    const char *marker = second_part + i;
    size_t marker_len = my_strlen(marker) - 1;
    char *line = NULL;
    size_t len = 0;
    ssize_t read = getline(&line, &len, stdin);

    voice(second_part, i);
    while (read != -1) {
        if (my_strncmp(line, marker, marker_len) == 0) {
            break;
        }
        if (write(STDOUT_FILENO, line, read) == -1) {
            perror("write");
            break;
        }
    }
    cond(read, line);
}
