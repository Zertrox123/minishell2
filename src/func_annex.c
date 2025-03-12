/*
** EPITECH PROJECT, 2024
** omar
** File description:
** func_annex.c
*/

#include "../include/my.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

char *read_input(int argc, char **argv)
{
    char *str = NULL;
    char *real;
    int i = 0;
    size_t reading;
    ssize_t input;

    input = getline(&str, &reading, stdin);
    if (input == -1)
        return NULL;
    real = malloc(sizeof(char) * my_strlen(str));
    for (; i != my_strlen(str) - 1; i++)
        real[i] = str[i];
    real[i] = '\0';
    return real;
}

int start_with_exec(int nbr_exec, char **argv)
{
    int a = 0;

    if (nbr_exec == 0)
        return 0;
    for (int i = 0; i != nbr_exec; i++) {
        while (my_strncmp(argv[a], "&&", 2) != 0 && argv[a] != NULL)
            a++;
        a++;
    }
    return a;
}

int nbr_separator(char **argv)
{
    int separator = 0;

    for (int i = 0; argv[i] != NULL; i++) {
        if (my_strncmp(argv[i], "&&", 2) == 0)
            separator++;
    }
    return separator + 1;
}
