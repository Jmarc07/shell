/*
** EPITECH PROJECT, 2023
** strncpy
** File description:
** copies n characters from a string to another
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int i;

    for (i = 0; src[i] != '\0' && i < n; i++) {
        dest[i] = src[i];
    }
    if (src[i] == '\0' && i < n) {
        dest[i] = src[i];
    }
    return (dest);
}
