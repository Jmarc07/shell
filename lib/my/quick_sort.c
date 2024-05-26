/*
** EPITECH PROJECT, 2024
** quick_sort
** File description:
** quick sort algo
*/
#include "my.h"
#include <stdio.h>

int partition(int *arr, int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            my_swap(&arr[i], &arr[j]);
        }
    }
    my_swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quicksort(int *arr, int low, int high)
{
    int pi;

    if (low < high) {
        pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}
