/*
** EPITECH PROJECT, 2024
** omar
** File description:
** my_put_nbr.c
*/

#include "../include/my.h"
#include <unistd.h>

int my_put_nbr(long nb)
{
    long number;
    long stock = nb;

    if (stock < 0) {
        my_putchar(45);
        stock = stock * (-1);
    }
    if (stock >= 10) {
        number = stock % 10;
        stock = stock / 10;
        my_put_nbr(stock);
        my_putchar(number + 48);
    } else {
        my_putchar(stock + 48);
        return 0;
    }
}

int my_count_nbr(int nb)
{
    long stock = nb;
    int i = 0;

    if (stock < 0)
        stock *= (-1);
    while (stock >= 10) {
        stock /= 10;
        i++;
    }
    return i + 1;
}
