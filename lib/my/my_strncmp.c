/*
** EPITECH PROJECT, 2023
** strcnpm
** File description:
** Reproduce the behavior of the strncmp function/task07
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    int a = 0;
    int b = 0;
    int i = 0;

    while (i < n && (s1[i] != '\0' || s2[i] != '\0')) {
        a += s1[i];
        b += s2[i];
        i++;
    }
    return (a - b);
}
