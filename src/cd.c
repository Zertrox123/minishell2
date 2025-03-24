/*
** EPITECH PROJECT, 2024
** omar
** File description:
** cd.c
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "../include/my.h"

int do_cd(char **argv, char **env)
{
    char **temp;

    if (argv[1] == NULL && chdir("/home") == 0)
        return 0;
    temp = strtok(argv[1], '\n');
    if (temp[0][0] == '~' && chdir("/home") == 0)
        return 0;
    if (chdir(temp[0]) == 0)
        return 0;
    mini_printf("%s: No such file or directory.\n", temp[0]);
    return 84;
}

char **setenvi(char **argv, char **env)
{
    char **tab = parsing_env(env);
    char *av;
    int i = 0;

    if (argv[1] == NULL)
        return env;
    for (; tab[i] != NULL; i++);
    av = my_strcomb(argv[1], "=");
    if (argv[2] != NULL)
        av = my_strcomb(av, argv[2]);
    tab[i] = av;
    tab[i + 1] = NULL;
    return tab;
}

char **unsetenvi(char **argv, char **env)
{
    char **tab = malloc(sizeof(char *) * len_env(env));
    int a = 0;

    if (argv[1] == NULL)
        return env;
    for (int i = 0; env[i] != NULL; i++) {
        if (my_strncmp(env[i], argv[1], my_strlen(argv[1]) - 1) != 0) {
            tab[a] = my_strdup(env[i]);
            a++;
        }
    }
    tab[a] = NULL;
    return tab;
}
