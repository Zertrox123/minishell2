/*
** EPITECH PROJECT, 2024
** B-MUL-100-LYN-1-1-myradar-gauthier.candelier
** File description:
** my_str_things.c
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_strlen(char *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++);
    return i;
}

void my_putstr(char *str)
{
    write(1, str, my_strlen(str));
}

char *my_strcpy(char *dest, char *src)
{
    int i;

    for (i = 0; src[i] != '\0'; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return dest;
}
