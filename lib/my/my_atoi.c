/*
** EPITECH PROJECT, 2024
** my_atoi
** File description:
** my_atoi
*/

int my_atoi(char *str)
{
    int result = 0;
    int n = 1;
    int i = 0;

    if (str[0] == '-') {
        n = -1;
        i = 1;
    }
    for (; str[i] != '\0'; ++i) {
        if (str[i] >= '0' && str[i] <= '9') {
            result = result * 10 + (str[i] - '0');
        } else {
            return 0;
        }
    }
    return n * result;
}
