/*
** EPITECH PROJECT, 2024
** omar
** File description:
** my_strtoc.c
*/

#include "../include/my.h"
#include <stdlib.h>
#include <stdio.h>

static int malloc_tab(char *str, char tab)
{
    int x = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == tab)
            x++;
    }
    return x;
}

char **strtok(char *buffer, char character)
{
    char **tab = malloc(sizeof(char *) * (malloc_tab(buffer, character) + 2));
    int x = 0;
    int j = 0;

    if ((malloc_tab(buffer, character)) == 0) {
        tab[0] = buffer;
        return tab;
    }
    for (int i = 0; buffer[i] != '\0'; i++) {
        tab[x] = malloc(sizeof(char) * (my_strlen(buffer)));
        for (; buffer[i] != character && buffer[i] != '\0'; j++) {
            tab[x][j] = buffer[i];
            i++;
        }
        tab[x][j] = '\0';
        j = 0;
        x++;
    }
    tab[x] = NULL;
    return tab;
}
