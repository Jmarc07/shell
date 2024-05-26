/*
** EPITECH PROJECT, 2023
** strcmp
** File description:
** reproduce the strcmp function/task06
*/

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    for (; s1[i] != '\0' && s2[i] != '\0'; i++) {
        if ((s1[i] - s2[i]) != 0)
            return -1;
    }
    return 0;
}
