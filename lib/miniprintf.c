/*
** EPITECH PROJECT, 2024
** delivery
** File description:
** miniprintf.c
*/

#include "../include/my.h"
#include <stdarg.h>
#include <stdio.h>

int another_switch_case(const char *format, va_list parameters, int i,
    int counter)
{
    char *sto;

    switch (format[i]) {
    case 's':
        sto = va_arg(parameters, char *);
        counter += my_strlen(sto);
        my_putstr(sto);
        break;
    case 'c':
        my_putchar(va_arg(parameters, int));
        counter++;
        break;
    case '%':
        my_putchar('%');
        counter++;
        break;
    default:
        break;
    }
    return counter;
}

int switch_case(const char *format, va_list parameters, int i, int counter)
{
    int st = 0;
    char *sto;

    switch (format[i]) {
    case 'd':
        st = va_arg(parameters, int);
        my_put_nbr(st);
        counter += my_count_nbr(st);
        break;
    case 'i':
        st = va_arg(parameters, int);
        my_put_nbr(st);
        counter += my_count_nbr(st);
        break;
    default:
        counter = another_switch_case(format, parameters, i, counter);
    }
    return counter;
}

int mini_printf(const char *format, ...)
{
    va_list parameters;
    int counter = 0;

    va_start(parameters, format);
    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%') {
            counter = switch_case(format, parameters, i + 1, counter);
            i++;
        } else {
            my_putchar(format[i]);
            counter++;
        }
    }
    va_end(parameters);
    return counter + 1;
}
