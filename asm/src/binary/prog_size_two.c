/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** prog_size
*/

#include "asm.h"

int recup_value_str(char *arg)
{
    char *str = malloc(sizeof(char) * 100);
    int j = 0;

    for (int i = 1; arg[i]; i++, j++)
        str[j] = arg[i];
    str[j] = '\0';
    j = 0;
    j = my_getnbr(str);
    free(str);
    return (j);
}

int recup_value_ind(char *arg)
{
    char *str = malloc(sizeof(char) * 100);
    int j = 0;

    for (int i = 0; arg[i]; i++, j++)
        str[j] = arg[i];
    str[j] = '\0';
    j = 0;
    j = my_getnbr(str);
    free(str);
    return (j);
}

int check_arg_type_one(char *arg)
{
    char *arr[] = {"live", "zjmp", "fork", NULL};

    for (int i = 0; arr[i]; i += 1)
        if (my_strcmp(arr[i], arg) == 0)
            return (1);
    return (2);
}

int check_arg_type_two(char *str)
{
    char *arr[] = {"zjmp", "ldi", "sti", "fork", "lldi", "lfork", NULL};

    for (int i = 0; arr[i]; i += 1)
        if (my_strcmp(arr[i], str) == 0)
            return (IND_SIZE);
    return (DIR_SIZE);
}