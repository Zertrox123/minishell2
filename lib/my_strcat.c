/*
** EPITECH PROJECT, 2024
** omar
** File description:
** my_strcat.c
*/

#include "../include/my.h"
#include <stdlib.h>

char *my_strcat(char *dest, char const *src)
{
    int len = my_strlen(dest) + my_strlen(src);
    char *final = malloc(sizeof(char) * (len + 1));
    int a = 0;

    for (int i = 0; dest[i] != '\0'; i++) {
        final[a] = dest[i];
        a++;
    }
    for (int i = 0; src[i] != '\0'; i++) {
        final[a] = src[i];
        a++;
    }
    final[a] = '\0';
    return final;
}
