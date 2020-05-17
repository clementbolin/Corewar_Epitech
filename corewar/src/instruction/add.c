/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** add
*/

#include "corewar.h"

int check_arg_add(linkv_t *link)
{
    nodev_t *node = link->head;
    int i = 0;

    for (; node != NULL; node = node->next, i++) {
        if (node->type != REG)
            return (84);
    }
    if (i > 3)
        return (84);
    node = link->head;
    for (; node != NULL; node = node->next) {
        if (node->value > 16)
            return (84);
    }
    return (0);
}

void add(cor_t *vm UNUSED, champ_t *champ, linkv_t *link)
{
    int res = 0;
    int store = 0;
    nodev_t *node = NULL;

    if (check_arg_add(link) == 84) return;
    node = link->head;
    if (node == NULL) return;
    res = champ->reg[node->value];
    node = node->next;
    if (node == NULL) return;
    res += champ->reg[node->value];
    node = node->next;
    if (node == NULL) return;
    store = node->value;
    champ->reg[store] = res;
}