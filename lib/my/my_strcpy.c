/*
** EPITECH PROJECT, 2019
** my_strcpy
** File description:
** task
*/

#include <unistd.h>
#include <stdlib.h>

int size_strcpy(char *str)
{
    int i = 0;

    for (; str[i]; i++);
    return (i);
}

char *my_strcpy(char *dest, char *src)
{
    int i = 0;

    dest = malloc(sizeof(char) * (size_strcpy(src) + 1));
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}
