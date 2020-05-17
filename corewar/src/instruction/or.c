/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** or.c
*/

#include "corewar.h"

static int check_arg_or(linkv_t *link)
{
    nodev_t *tmp = link->head;
    int id = 0;

    while (tmp) {
        id++;
        if (id == 3 && tmp->type != T_REG)
            return (84);
        tmp = tmp->next;
    }
    if (id != 3)
        return (84);
    return (0);
}

void or(UNUSED cor_t *vm, UNUSED champ_t *champ, linkv_t *link)
{
    int nbr1 = 0;
    int nbr2 = 0;
    nodev_t *tmp = link->head;

    if (check_arg_or(link) == 84)
        return;
    nbr1 = (tmp->type == REG ? champ->reg[tmp->value] : tmp->value);
    tmp = tmp->next;
    nbr2 = (tmp->type == REG ? champ->reg[tmp->value] : tmp->value);
    tmp = tmp->next;
    champ->reg[tmp->value] = nbr1 | nbr2;
}