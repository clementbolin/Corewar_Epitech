/*
** EPITECH PROJECT, 2019
** my_strstr
** File description:
** lib
*/

#include <stdio.h>

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return i;
}

char *my_strstr(char *str, char const *to_find)
{
    int i = 0;
    int size = my_strlen(to_find);
    int j;

    while (str[i] != '\0') {
        j = 0;
        while (to_find[j] == str[i+j] && to_find[j] != '\0') {
            j++;
        }
        if (j == size)
            return (str + i);
        i++;
    }
    return (NULL);
}