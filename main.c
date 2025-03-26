/*
** EPITECH PROJECT, 2024
** omar
** File description:
** main.c
*/

#include "include/my.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

static int verif_command(char **argv, char **env)
{
    if (my_strncmp(argv[0], "setenv", 6) == 0)
        return 0;
    if (my_strncmp(argv[0], "unsetenv", 8) == 0)
        return 0;
    if (my_strncmp(argv[0], "cd", 2) == 0)
        return do_cd(argv, env);
    if (my_strncmp(argv[0], "exit", 4) == 0)
        return 84;
    if (my_strncmp(argv[0], "", 1) == 0)
        return 0;
    return exec_bin(argv, env);
}

char **actu_command(char **argv, char **env, int nbr_exec)
{
    char **tab = malloc(sizeof(char *) * 50);
    int i = start_with_exec(nbr_exec, argv);
    int a = 0;

    for (; argv[i] != NULL; i++) {
        if (my_strncmp(argv[i], "&&", 2) == 0 ||
        my_strncmp(argv[i], ";", 1) == 0)
            return tab;
        tab[a] = my_strdup(argv[i]);
        a++;
    }
    tab[i] = NULL;
    return tab;
}

char **command_env(char **argv, char **env)
{
    if (my_strncmp(argv[0], "setenv", 6) == 0)
        env = setenvi(argv, env);
    if (my_strncmp(argv[0], "unsetenv", 8) == 0)
        env = unsetenvi(argv, env);
    return env;
}

static stock_t *handling_command(char **argv, stock_t *var)
{
    char **temp;
    int nbr_exec = 0;
    int exec = 0;

    for (int i = 0; i < nbr_separator(argv); i++) {
        if (my_strncmp(argv[i], ";", 1) == 0)
            i++;
        temp = actu_command(argv, var->envi, nbr_exec);
        var->envi = command_env(var_remove_space(strtok(argv[i], ' '))
        , var->envi);
        if (verif_command(var_remove_space(strtok(argv[i], ' ')), var->envi)
        == 84) {
            var->status = 84;
            return var;
        }
        nbr_exec++;
    }
    var->status = 0;
    return var;
}

stock_t *isatty_0(int argc, char **argv, stock_t *var)
{
    char *input_user;

    var->status = 0;
    while (1) {
        input_user = read_input(argc, argv);
        if (var->status == 84)
            return var;
        if (input_user != NULL && input_user[0] != '\0')
            var = handling_command(right_argv(input_user), var);
        else {
            var->status = 0;
            return var;
        }
    }
    var->status = 0;
    return var;
}

int main(int argc, char **argv, char **env)
{
    char *input_user;
    char *buffer = malloc(sizeof(char) * 4096);
    char **envi = parsing_env(env);
    stock_t *ht = malloc(sizeof(stock_t));

    ht->envi = env;
    if (isatty(0) == 0) {
        ht = isatty_0(argc, argv, ht);
        return ht->status;
    }
    while (1) {
        mini_printf("\033[36m%s\033[0m - $> ", getcwd(buffer, 4096));
        input_user = read_input(argc, argv);
        ht = handling_command(right_argv(input_user), ht);
        if (ht->status == 84)
            return 84;
        if (ht->status == 2)
            return 0;
    }
}

/*
{ls; ls}
[[ls]] exec
[[ls]] exec

{    ls  ;   ls}
[[ls]] exec
[[ls]] exec

{    ls    -l ; ls}
[[ls]
[-l]] exec
[[ls]] exec

    for (int i = 0; argv[i] != NULL; i++)
        mini_printf("%s\n", argv[i])
*/
