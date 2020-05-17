/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** fill_link
*/

#include "asm.h"

int is_label(char *str)
{
    for (int i = 0; str[i]; i += 1)
        if (str[i] == ':' && str[i - 1] != '%')
            return (1);
    return (0);
}

char *get_args_two(char *str, int tmp, char *res, int i)
{
    if (tmp == 1) {
        i += 2;
        for (; str[i] != ' '; i += 1);
        i += 1;
        for (tmp = i; str[i]; i += 1);
        res = malloc(sizeof(char) * (i + 1 - tmp));
        res[i - tmp] = '\0';
        for (i = 0; str[tmp + i]; i += 1)
            res[i] = str[tmp + i];
        return (res);
    }
    for (i = 0; str[i] != ' '; i += 1);
    i += 1;
    for (tmp = i; str[i]; i += 1);
    res = malloc(sizeof(char) * (i + 1 - tmp));
    res[i - tmp] = '\0';
    for (i = 0; str[tmp + i]; i += 1)
        res[i] = str[tmp + i];
    return (res);
}

char *get_args(char *str)
{
    int tmp = 0;
    char *res = NULL;
    int i = 0;

    for (i = 0; str[i]; i += 1)
        if (str[i] == ':' && str[i - 1] != '%') {
            tmp = 1;
            if (str[i + 1] == '\0')
                return (NULL);
            break;
        }
    return (get_args_two(str, tmp, res, i));
}