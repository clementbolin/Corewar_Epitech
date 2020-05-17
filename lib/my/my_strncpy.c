/*
** EPITECH PROJECT, 2019
** my_strncpy
** File description:
** copy n character
*/

#include <stdio.h>

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;
    int size_src = 0;

    for (; src[size_src] != '\0'; size_src++);

    while (src[i] != src[n]) {
        dest[i] = src[i];
        i++;
    }
    for (; i < n; i++)
        dest[i] = '\0';
    return (dest);
}
