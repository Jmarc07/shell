/*
** EPITECH PROJECT, 2021
** minishell
** File description:
** first
*/

#include <stdlib.h>
#include <unistd.h>
#include "../include/mysh.h"
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

char *without_pwd(const char *buff, const char *start)
{
    size_t len_buff = my_strlen(buff);
    size_t len_start = my_strlen(start);
    char *final = malloc(len_buff - len_start + 1);

    if (final == NULL) {
        return NULL;
    }
    my_strcpy(final, buff + len_start);
    return final;
}

char *home_pwd(char **env, char *start)
{
    int i = 0;

    for (; env[i] != NULL &&
    my_strncmp(start, env[i], my_strlen(start)) != 0; i++);
    if (env[i] == NULL) {
        return NULL;
    }
    return without_pwd(env[i], start);
}

void display_error_cd_n(const char *opt, char **env,
    const char *save, char *buff)
{
    if (access(opt, F_OK) == -1) {
        printf("%s: No such file or directory.\n", opt);
        my_strcpy(env[get_env_index(env) - 1], save);
        return;
    }
    if (access(opt, R_OK) == -1) {
        printf("%s: Permission denied.\n", opt);
        my_strcpy(env[get_env_index(env) - 1], save);
        return;
    }
    chdir(opt);
    getcwd(buff, 100);
    env[get_env_index(env) - 1] = pwd(buff, "PWD=");
}

void freed(char **divised_line, char *save)
{
    if (divised_line[1] == NULL) {
        my_printf("cd: No home directory.\n");
        free(save);
        return;
    }
}

void display_error_cd(char **env, char **divised_line)
{
    char buff[100];
    char *save = NULL;

    if (divised_line[1] != NULL && divised_line[2] != NULL) {
        printf("cd: Too many arguments.\n");
        return;
    }
    save = my_strdup(env[get_env_index(env) - 1]);
    getcwd(buff, sizeof(buff));
    env[get_env_index(env) - 1] = pwd(buff, "OLDPWD=");
    if (divised_line[1] == NULL) {
        divised_line[1] = home_pwd(env, "HOME=");
    } else if (my_strcmp(divised_line[1], "-") == 0) {
        divised_line[1] = without_pwd(save, "OLDPWD=");
    }
    freed(divised_line, save);
    display_error_cd_n(divised_line[1], env, save, buff);
    free(save);
}
