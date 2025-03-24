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

static int count_pipe(char **argv)
{
    int count = 0;

    for (int i = 0; argv[i] != NULL; i++) {
        if (my_strncmp(argv[i], "|", 1) == 0)
            count++;
    }
    return count;
}

static char **command_pipe(char **argv, int start)
{
    char **first_argv = malloc(sizeof(char *) * 50);
    int a = 0;

    for (; argv[start] != NULL; start++) {
        if (my_strncmp(argv[start], "|", 1) == 0)
            break;
        first_argv[a] = argv[start];
        a++;
    }
    first_argv[a] = NULL;
    return first_argv;
}

static int find_pipe(char **argv)
{
    int count = 0;
    int i = 0;

    for (; argv[i] != NULL; i++) {
        if (my_strncmp(argv[i], "|", 1) == 0)
            break;
    }
    if (argv[i] == NULL)
        return 0;
    return i;
}

int do_pipe(char *one_path, char **arg0, char **arg1, char **env)
{
    char *second_path = my_strcat("/usr/bin/", arg1[0]);
    int pipes[2];
    pid_t pid;

    pipe(pipes);
    pid = fork();
    if (pid == 0) {
        close(pipes[0]);
        dup2(pipes[1], STDOUT_FILENO);
        close(pipes[1]);
        execve(one_path, arg0, env);
        exit(EXIT_SUCCESS);
    } else {
        close(pipes[1]);
        dup2(pipes[0], STDIN_FILENO);
        close(pipes[0]);
        execve(second_path, arg1, env);
        exit(EXIT_SUCCESS);
    }
}

int gestion_pipe(char *one_path, char **all_argv, char **env)
{
    char **argv;
    char **argv1;
    int status = 0;
    int i = 0;

    for (; i != count_pipe(all_argv); i++) {
        argv = command_pipe(all_argv, start_with_pipe(i, all_argv));
        argv1 = command_pipe(all_argv, start_with_pipe(i + 1, all_argv));
        status += do_pipe(my_strcat("/usr/bin/", argv[0]), argv, argv1, env);
    }
    status += do_pipe(my_strcat("/usr/bin/", argv[0]), argv, argv1, env);
    return 0;
}

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

    if (find_pipe(argv) != 0)
        return gestion_pipe(my_strcat(my_strdup("/usr/bin/"), argv[0]),
        argv, env);
    for (int i = 0; real_path[i] != NULL; i++) {
        one_path = my_strcat(real_path[i], "/");
        one_path = my_strcat(one_path, temp_arg[0]);
        status += exec_bin2(one_path, argv, env);
    }
    status += exec_bin2(argv[0], argv, env);
    if (status > 0)
        return 0;
    mini_printf("%s: Command not found.\n", argv[0]);
    return 84;
}
