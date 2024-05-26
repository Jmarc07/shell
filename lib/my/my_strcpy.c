/*
** EPITECH PROJECT, 2023
** strcpy
** File description:
** copie a string into another
*/

char *my_strcpy(char *dest, char const *src)
{
    int i;

    for (i = 0; src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    dest[i] = src[i];
    return (dest);
}
