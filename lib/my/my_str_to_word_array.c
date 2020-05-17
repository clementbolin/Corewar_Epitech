/*
** EPITECH PROJECT, 2020
** lib
** File description:
** str_to_tab
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"

int jump_nonalpha(char str);

int my_len(char *str, int i);

int biglen(char *str);

char *convert(char const *src, char *dest, int *i);

char **my_str_to_word_array(char *str, int *nb_lines)
{
    char **tab = NULL;
    int i = 0;
    int k = 0;
    int size = 0;
    int m = my_strlen(str);

    *nb_lines = biglen(str);
    tab = malloc((sizeof(char *)) * (*nb_lines) + 1);
    while (k < m) {
        if (jump_nonalpha(str[k]) == 0) {
            size = my_len(str, k);
            tab[i] = malloc((sizeof(char)) * (size) + 1);
            tab[i] = convert(str, tab[i], &k);
            i += 1;
        }
        k += 1;
    }
    tab[i] = NULL;
    return (tab);
}

int biglen(char *str)
{
    int i = 0;
    int size = 0;

    while (str[i]) {
        if (jump_nonalpha(str[i]) == 0 && i == 0)
            size += 1;
        if ((i > 0) && jump_nonalpha(str[i]) == 0
            && (jump_nonalpha(str[i - 1]) == 1))
            size += 1;
        i += 1;
    }
    return (size);
}

int jump_nonalpha(char str)
{
    if (str == ' ')
        return (1);
    if (str == '\0')
        return (1);
    if (str == '\t')
        return (1);
    return (0);
}

int my_len(char *str, int i)
{
    int j = 0;
    int k = i;

    while (jump_nonalpha(str[k]) == 0) {
        j++;
        k++;
    }
    return (j);
}

char *convert(char const *src, char *dest, int *i)
{
    int j = 0;

    while (jump_nonalpha(src[*i]) == 0) {
        dest[j] = src[*i];
        *i += 1;
        j += 1;
    }
    dest[j] = '\0';
    return (dest);
}