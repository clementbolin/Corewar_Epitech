/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** sti
*/

#include "corewar.h"

int check_arg_sti(linkv_t *link)
{
    nodev_t *node = link->head;
    int i = 0;

    if (node->type != REG) return (84);
    node = node->next;
    i += 1;
    for (; node != NULL; i++, node = node->next) {
        if (i == 3 && node->type == IND)
            return (84);
    }
    if (i != 3)
        return (84);
    return (0);
}

void sti(cor_t *vm, champ_t *champ, linkv_t *link)
{
    nodev_t *node = NULL;
    int store = 0;
    int value = 0;

    if (!link || link->head == NULL) return;
    if (check_arg_sti(link) == 84) return;
    node = link->head;
    value = node->value;
    node = node->next;
    if (node->type == REG && node->value > 16) return;
    store = node->value;
    node = node->next;
    store = champ->pc + (store + node->value) % IDX_MOD;
    if (node->type == REG && store < 16)
        champ->reg[store] = value;
    if (node->type != REG && store > 0 && store < MEM_SIZE) {
        vm->map[store] = value;
        write_color_in_map(champ, vm, store);
    }
}