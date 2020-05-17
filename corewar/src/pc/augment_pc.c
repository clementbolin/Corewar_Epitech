/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** augment_pc
*/

#include "corewar.h"

int increase_pc(char *str, char *mnemonique)
{
    if (my_strcmp(str, "01") == 0)
        return (1);
    if (my_strcmp(str, "10") == 0) {
        if (check_special_val(mnemonique) == 1)
            return (2);
        return (4);
    }
    if (my_strcmp(str, "11") == 0)
        return (2);
    return (0);
}