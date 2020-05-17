/*
** EPITECH PROJECT, 2019
** my_strcapitalize
** File description:
** lib
*/

#include <stdio.h>

char iscapital(char c)
{
    if (c >= 65 && c <= 90)
        return (c);
    else
        return (c - 32);
}

char *my_strcapitalize(char *str)
{
    int i = 0;

    str[i] = iscapital(str[i]);
    while (str[i] != '\0') {
        if (str[i] == ' ' && str[i + 1] >= 'a' && str[i + 1] <= 'z') {
            str[i + 1] = str[i + 1] - 32;
            i++;
        }
        i++;
    }
    return (str);
}