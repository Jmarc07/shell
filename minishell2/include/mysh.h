/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** minishell
*/

#ifndef MINISHELL
    #define MINISHELL
    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <sys/types.h>
    #include <sys/wait.h>
    #include <signal.h>
    #include "my.h"
char **create_env(char **env);
char **add_env(char **env, char *key, char *value);
int get_env_index(char **env);
char **remove_env(char **env, const char *key);
void my_unsetenv(char ***env, char **arg);
int my_setenv_checks(char **env, char **arg, int arg_n);
void my_setenv(char ***env, char **arg);
void print_env(char **env);
void my_exit(char **arg);
char *pwd(const char *path, const char *prefix);
void display_error_cd(char **env, char **divised_line);
void specifique_function(char ***env, char **divised_line);
void error_execve(char *opt);
int execute(char **env, char **divised_line, char *buffer);
int check_builtin(char ***env, char *buffer);
char *copy_path(char *buffer, char *path);
char **copy_all(char *buffer);
int count_args(char *buffer, char tab);
void my_tabfree(char **tab);
char **my_tabdup(char **tab);
void my_tabcpy(char ***tab1, char **tab2);
int my_tablen(char **tab);
int my_strcmp_uncomplete(char *str, char *cmp);
void separate_line(char **env, char *first_part, char *second_part);
void double_right(const char *second_part);
void redirect_double(char **env, char *first_part,
    char *second_part, int append);
void redirect_simple(char **env, char *first_part, char *second_part);
void piping(char **env, char *first_part, char *second_part);
void use_pipe(char **env, char *second_part, int tube[2]);
void redirect_init(char **env, char *buffer);
char *get_filename(char *second_part);
int open_file(char *filename, int append);
int saves(void);
int redirect(int fd);
void restore(int save_fd);
char *my_strtok(char *str, char delim);

#endif /* !MINISHELL */
