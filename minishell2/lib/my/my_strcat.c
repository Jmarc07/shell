/*
** EPITECH PROJECT, 2023
** my_strcat
** File description:
** function that concatonates two strings
*/

char *my_strcat(char *dest, char const *src)
{
    int n = 0;

    for (int i = 0; dest[i] != '\0'; i++) {
        n++;
    }
    for (int a = 0; src[a] != '\0'; a++) {
        dest[n + a] = src[a];
    }
    return (dest);
}
