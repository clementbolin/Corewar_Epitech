/*
** EPITECH PROJECT, 2019
** my_strcat
** File description:
** lib
*/

#include <stdlib.h>

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return (i);
}

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int size = 0;
    char *str = malloc(sizeof(char) * (my_strlen(dest) + my_strlen(src) + 2));

    for (; dest[size] != '\0'; size++)
        str[size] = dest[size];

    while (src[i] != '\0') {
        str[size + i] = src[i];
        i++;
    }
    str[size + i] = '\0';
    return (str);
}