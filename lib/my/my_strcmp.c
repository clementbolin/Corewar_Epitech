/*
** EPITECH PROJECT, 2019
** my_strcmp
** File description:
** task06
*/

#include <stdio.h>

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    if (!s1 || !s2)
        return (-1);
    while (s1[i] && s2[i] && s1[i] == s2[i])
        i++;
    return (s1[i] - s2[i]);
}