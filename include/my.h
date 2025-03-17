/*
** EPITECH PROJECT, 2024
** omar
** File description:
** my.h
*/

#ifndef MY_H
    #define MY_H

typedef struct stock_i {
    int status;
    char **envi;
} stock_t;

int my_strncmp(char const *s1, char const *s2, int n);
int start_with_exec(int nbr_exec, char **argv);
int my_strcmp(char const *s1, char const *s2);
char *my_strcat(char *dest, char const *src);
char **strtok(char *buffer, char character);
int my_str_isalpha(char const *str, int i);
char **unsetenvi(char **argv, char **env);
int mini_printf(const char *format, ...);
char *my_strcomb(char *dest, char *src);
char **setenvi(char **argv, char **env);
char *read_input(int argc, char **argv);
int exec_bin(char **argv, char **env);
char **var_remove_space(char **argv);
int my_str_islower(char const *str);
int do_cd(char **arg, char **env);
char *my_strdup(char const *src);
char **right_argv(char *buffer);
void my_putstr(char const *str);
char **parsing_env(char **env);
int my_getnbr(char const *str);
int my_strlen(char const *str);
int my_strlen(char const *str);
int nbr_separator(char **argv);
char *getpath(char **env);
int my_count_nbr(int nb);
int my_put_nbr(long nb);
int len_env(char **env);
void my_putchar(char c);
void my_putchar(char c);
char *path(char **tab);

#endif /* MY_H */
