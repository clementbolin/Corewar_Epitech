/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** lld.c
*/

#include "corewar.h"

int check_arg_lld(linkv_t *link)
{
    nodev_t *node = link->head;
    int i = 0;

    if (node->type == DIR || node->type == IND) {
        if (node->value > MEM_SIZE)
            return (84);
    } else
        return (84);
    for (; node->next != NULL; node = node->next, i++);
    if (i+1 > 2) return (84);
    if (node != NULL) {
        if (node->type != REG) return (84);
        if (node->value > 16) return (84);
    }
    return (0);
}

void lld(cor_t *vm UNUSED, champ_t *champ, linkv_t *link)
{
    nodev_t *node = NULL;
    int value = 0;

    if (link == NULL)
        return;
    node = link->head;
    if (check_arg_lld(link) == 84)
        return;
    value = node->value;
    node = node->next;
    if (node->value > 16)
        return;
    value = champ->pc + value;
    if (value < 0 || value > MEM_SIZE)
        return;
    value = vm->map[value];
    champ->reg[node->value] = value;
}