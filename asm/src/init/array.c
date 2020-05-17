/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** main
*/

#include "asm.h"

char **move_array(char **arr, int nb)
{
    for (int i = nb; arr[i + 1]; i += 1)
        arr[i] = my_strcpy(arr[i], arr[i + 1]);
    return (arr);
}

char *remove_commentary(char *str)
{
    for (int i = 0; str[i]; i += 1)
        if (str[i] == '#') {
            for (; str[i]; i += 1)
                str[i] = '\0';
            return (str);
        }
    return (str);
}

char *move_string(char *str, int nb)
{
    int i = 0;

    for (i = nb; str[i + 1]; i += 1)
        str[i] = str[i + 1];
    str[i] = '\0';
    return (str);
}

char **clean_array_two(char **arr, int size, int pos)
{
    for (size += 1; size < pos; size += 1)
        arr[size] = NULL;
    for (int i = 2; arr[i]; i++)
        for (int j = 0; arr[i][j]; j++)
            if (arr[i][j] == ',')
                arr[i] = move_string(arr[i], j);
    return (arr);
}

char **clean_array(char **arr)
{
    int size = 0;
    int pos = 0;

    for (int i = 0; arr[i]; i++)
        arr[i] = remove_commentary(arr[i]);
    for (; arr[size]; size += 1);
    pos = size;
    for (int i = 0; arr[i]; ++i) {
        for (;arr[i][0] == '\0' && i <= size;) {
            arr = move_array(arr, i);
            size -= 1;
        }
        if (i >= size)
            break;
        arr[i] = clean_string(arr[i]);
    }
    return (clean_array_two(arr, size, pos));
}