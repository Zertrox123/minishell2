/*
** EPITECH PROJECT, 2024
** omar
** File description:
** parsing_env.c
*/

#include "../include/my.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int len_env(char **env)
{
    int i = 0;

    for (; env[i] != NULL; i++);
    return i + 2;
}

char *my_strcomb(char *dest, char *src)
{
    char *final = malloc(sizeof(char) *
    (my_strlen(dest) + my_strlen(src) + 1));
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

char **parsing_env(char **env)
{
    char **tab = malloc(sizeof(char *) * len_env(env));
    int i = 0;
    int j = 0;

    for (; env[i] != NULL; i++) {
        tab[i] = malloc(sizeof(char) * (my_strlen(env[i]) + 1));
        tab[i] = my_strdup(env[i]);
    }
    tab[i] = NULL;
    return tab;
}
