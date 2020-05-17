/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** flag
*/

#include "corewar.h"

int bonus_flag(char **av)
{
    for (int i = 0; av[i]; i++) {
        if (my_strcmp(av[i], "-b") == 0)
            return (1);
    }
    return (0);
}