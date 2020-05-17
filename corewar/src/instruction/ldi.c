/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** ldi.c
*/

#include "corewar.h"

static int check_arg_ldi(linkv_t *link)
{
    nodev_t *tmp = link->head;
    int id = 0;

    while (tmp) {
        id++;
        if (id == 2 && tmp->type == T_IND)
            return (84);
        if (id == 3 && tmp->type != T_REG)
            return (84);
        tmp = tmp->next;
    }
    if (id != 3)
        return (84);
    return (0);
}

void ldi(UNUSED cor_t *vm, UNUSED champ_t *champ, UNUSED linkv_t *link)
{
    if (check_arg_ldi(link) == 84)
        return;
}