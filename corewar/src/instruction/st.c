/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** st
*/

#include "corewar.h"

int check_arg_st(linkv_t *link)
{
    nodev_t *node = link->head;
    int i = 0;

    for (; node != NULL; node = node->next, i++) {
        if (i == 0 && node->type != REG)
            return (84);
        if (i == 1 && node->type == DIR)
            return (84);
    }
    if (i > 2)
        return (84);
    return (0);
}

void st(cor_t *vm UNUSED, champ_t *champ, linkv_t *link)
{
    int value = 0;
    int store = 0;
    nodev_t *node = NULL;

    if (check_arg_st(link) == 84)
        return;
    node = link->head;
    if (node == NULL) return;
    value = champ->reg[node->value];
    node = node->next;
    if (node == NULL) return;
    store = node->value;
    if (node->type != REG) {
        store = champ->pc + store % IDX_MOD;
        if (store < 0 || store > MEM_SIZE) return;
        vm->map[store] = value;
        write_color_in_map(champ, vm, store);
    } else
        champ->reg[store] = value;
}