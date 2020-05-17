/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** and.c
*/

#include "corewar.h"

static int check_arg(linkv_t *link)
{
    int id = 0;
    nodev_t *tmp = link->head;

    while (tmp) {
        id++;
        if (id == 3) {
            if (tmp->type != REG)
                return (84);
        }
        tmp = tmp->next;
    }
    if (id < 3)
        return (84);
    return (0);
}

void and(UNUSED cor_t *vm, champ_t *champ, linkv_t *link)
{
    int nbr1 = 0;
    int nbr2 = 0;
    nodev_t *tmp = link->head;

    if (check_arg(link) == 84)
        return;
    nbr1 = (tmp->type == REG ? champ->reg[tmp->value] : tmp->value);
    tmp = tmp->next;
    nbr2 = (tmp->type == REG ? champ->reg[tmp->value] : tmp->value);
    tmp = tmp->next;
    champ->reg[tmp->value] = nbr1 & nbr2;
}