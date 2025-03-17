/*
** EPITECH PROJECT, 2024
** omar
** File description:
** exec_bin.c
*/

#include "../include/my.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

int exec_bin2(char *one_path, char **argv, char **env)
{
    pid_t pid;
    int wait = 0;

    pid = fork();
    if (pid == -1)
        return 0;
    if (pid == 0) {
        execve(one_path, argv, env);
        exit(EXIT_FAILURE);
    } else {
        waitpid(pid, &wait, 0);
        if (WIFEXITED(wait) && WEXITSTATUS(wait) == 0)
            return 1;
    }
    return 0;
}

int exec_bin(char **argv, char **env)
{
    char *temp_str = getpath(env);
    char **temp_path = strtok(temp_str, '=');
    char **real_path = strtok(path(temp_path), ':');
    char **temp_arg = strtok(argv[0], '\n');
    char *one_path;
    int status = 0;

    for (int i = 0; real_path[i] != NULL; i++) {
        one_path = my_strcat(real_path[i], "/");
        one_path = my_strcat(one_path, temp_arg[0]);
        status += exec_bin2(one_path, argv, env);
        if (status > 0)
            return 0;
    }
    status += exec_bin2(argv[0], argv, env);
    if (status > 0)
        return 0;
    mini_printf("%s: Command not found.\n", argv[0]);
    return 84;
}
