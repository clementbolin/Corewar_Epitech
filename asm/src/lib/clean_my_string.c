/*
** EPITECH PROJECT, 2020
** clean_my_string
** File description:
** cleans string of all \t or spaces
*/

#include "asm.h"

int clean_string2(char *str)
{
    int i = 0;
    int count = 0;

    if (!str)
        return 1;
    for (; str[i] == ' ' || str[i] == '\t'; i += 1);
    do {
        for (;str[i] != ' ' && str[i] != '\t' && str[i]; i += 1)
            count += 1;
        count += 1;
        for (;str[i] == ' ' || str[i] == '\t'; i += 1);
    } while (str[i]);
    return (count);
}

char *clean_result(char *result, int count)
{
    if (result[count - 1] == ' ')
        result[--count] = '\0';
    else
        result[count] = '\0';
    return (result);
}

char *clean_string(char *str)
{
    char *result = NULL;
    int i = 0;
    int tmp = 0;
    int count = 0;

    result = malloc(sizeof(char) * (clean_string2(str) + 1));
    for (; str[i] == ' ' || str[i] == '\t'; i += 1);
    while (str[i]) {
        for (;str[i] != ' ' && str[i] != '\t' && str[i]; i += 1)
            result[count++] = str[i];
        for (; str[i] == ' ' || str[i] == '\t'; i += 1) {
            if (tmp == 0)
                result[count++] = ' ';
            tmp += 1;
        }
        tmp = 0;
    }
    return (clean_result(result, count));
}