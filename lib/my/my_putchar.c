/*
** EPITECH PROJECT, 2023
** putchar
** File description:
** my putchar
*/
#include <unistd.h>

void my_putchar(char c, int *count)
{
    write(1, &c, 1);
    *count += 1;
}
