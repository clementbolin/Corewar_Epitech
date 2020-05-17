/*
** EPITECH PROJECT, 2019
** my_strdup
** File description:
** task01
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strcpy(char *dest, char const *src);

char *my_strdup(char const *src)
{
    char *str_cpy = NULL;
    int size_src = my_strlen(src);

    str_cpy = malloc(sizeof(char) * (size_src + 1));
    my_strcpy(str_cpy, src);

    return (str_cpy);
}