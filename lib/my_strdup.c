/*
** EPITECH PROJECT, 2024
** omar
** File description:
** my_strdup.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int my_strlenn(char const *str)
{
    int a = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        a++;
    }
    return a;
}

char *my_strdup(char const *src)
{
    char *str_cpy = malloc(sizeof(char) * (my_strlenn(src) + 1));
    int i = 0;

    for (; src[i] != '\0'; i++)
        str_cpy[i] = src[i];
    str_cpy[i] = '\0';
    return str_cpy;
}
