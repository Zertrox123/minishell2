/*
** EPITECH PROJECT, 2024
** omar
** File description:
** get_things.c
*/

#include "../include/my.h"
#include <stdio.h>
#include <stdlib.h>

char *getpath(char **env)
{
    char *buffer;

    for (int i = 0; env[i] != NULL; i++) {
        if (my_strncmp("PATH=", env[i], 4) == 0) {
            buffer = malloc(sizeof(char) * (my_strlen(env[i]) + 1));
            buffer = my_strdup(env[i]);
            buffer[my_strlen(env[i])] = '\0';
            return buffer;
        }
    }
    free(buffer);
    return "";
}

char *path(char **tab)
{
    return tab[1];
}
