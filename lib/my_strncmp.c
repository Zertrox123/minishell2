/*
** EPITECH PROJECT, 2024
** omar
** File description:
** my_strncmp.c
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    for (; s1[i] != '\0' && s2[i] != '\0' && n != 0; i++) {
        if (s1[i] > s2[i])
            return 1;
        if (s1[i] < s2[i])
            return -1;
        n--;
    }
    if (s1[i] == s2[i])
        return 0;
    if (s1[i] != '\0')
        return 1;
    if (s2[i] != '\0')
        return -1;
}

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    while (s1[i] != '\0' && s2[i] != '\0'){
        if (s1[i] > s2[i])
            return 1;
        if (s1[i] < s2[i])
            return -1;
    }
    if (s2[i] != '\0')
        return 1;
    if (s1[i] != '\0')
        return -1;
    return 0;
}
