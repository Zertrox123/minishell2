/*
** EPITECH PROJECT, 2024
** omar
** File description:
** my_str_isalpha.c
*/

int my_str_isalpha(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] > 90 && str[i] < 97 || str[i] > 122 || str[i] < 65)
            return 1;
    }
    return 0;
}
