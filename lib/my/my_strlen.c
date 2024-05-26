/*
** EPITECH PROJECT, 2023
** my_strlen
** File description:
** day04/task03
*/

int my_strlen(char const *str)
{
    int count = 0;

    while (str[0] != '\0') {
        count++;
        str++;
    }
    return count;
}
