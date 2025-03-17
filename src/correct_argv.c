/*
** EPITECH PROJECT, 2024
** omar
** File description:
** correct_argv.c
*/

#include "../include/my.h"
#include <stdio.h>
#include <stdlib.h>


char *remove_space(char *buffer)
{
    char *argv = malloc(sizeof(char) * (my_strlen(buffer) + 1));
    int a = 0;

    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] != '\t' && buffer[i] != ' ') {
            argv[a] = buffer[i];
            a++;
        }
    }
    argv[a] = '\0';
    return argv;
}

char **var_remove_space(char **argv)
{
    char **tab = malloc(sizeof(char *) * len_env(argv));
    int i = 0;

    for (int a = 0; argv[a] != NULL; a++) {
        if (argv[a][0] != '\0') {
            tab[i] = remove_space(argv[a]);
            i++;
        }
    }
    tab[i] = NULL;
    return tab;
}

int nbr_sp(char *buffer)
{
    int nbr = 0;

    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] == ';')
            nbr++;
    }
    return nbr;
}

char **right_argv(char *buffer)
{
    char **argv = strtok(buffer, ';');
    int nbr_separat = nbr_sp(buffer);
    char **st = malloc(sizeof(char *) * (nbr_separat + 2));
    int a = 0;

    for (int i = 0; argv[i] != NULL; i++) {
        st[a] = argv[i];
        a++;
        if (argv[i + 1] != NULL) {
            st[a] = my_strdup(";");
            a++;
        }
    }
    st[a] = NULL;
    return st;
}
