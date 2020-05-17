/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** tool
*/

#include "asm.h"

int tab_len(char **tab)
{
    int i = 0;

    for (; tab[i] != NULL; i++);
    return (i);
}

char *cpy_name_file(char *str)
{
    char *name = malloc(sizeof(char) * my_strlen(str));
    int j = 0;
    int etat = 0;

    for (int i = 0; str[i]; i++) {
        if (str[i] == '/')
            etat = 1;
    }
    if (etat == 0)
        return (my_strcpy(name, str));
    else {
        for (int i = my_strlen(str)-1 ; i != 0; i--, j++) {
            if (str[i] == '/')
                break;
            name[j] = str[i];
        }
        name[j] = '\0';
        name = my_revstr(name);
    }
    return (name);
}

void name_file_cor(char *name)
{
    int i = my_strlen(name);

    for (; name[i] != '.'; i--);
    name[i] = '\0';
}

int little_to_big_short(int var)
{
    int tmp;

    tmp = 0;
    tmp = (var & 0xFF00) >> 24;
    tmp |= ((var & 0x00FF) << 8);
    return (tmp);
}