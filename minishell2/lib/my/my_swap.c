/*
** EPITECH PROJECT, 2024
** swap
** File description:
** swap
*/

void my_swap(int *a, int *b)
{
    int c = *a;

    a = b;
    *b = c;
}
