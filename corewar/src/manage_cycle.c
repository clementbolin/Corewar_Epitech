/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** manage_cycle
*/

#include "corewar.h"

void manage_live_champ(cor_t *vm)
{
    for (int i = 0; i != vm->nb_champ; i++) {
        if (vm->champ[i].live > vm->cycle_die)
            vm->champ[i].live = -100;
    }
    for (int i = 0; i != vm->nb_champ; i++) {
        if (vm->champ[i].live < 0)
            continue;
        vm->champ[i].live += 1;
    }
}

int check_champ_live(cor_t *vm)
{
    for (int i = 0; i != vm->nb_champ; i++) {
        if (vm->champ[i].live >= 0)
            return (1);
    }
    return (0);
}

int change_value_cycle(cor_t *vm)
{
    if (vm->cycle_die <= 0 || check_champ_live(vm) == 0)
        return (1);
    manage_live_champ(vm);
    if (vm->nbr_live >= NBR_LIVE) {
        vm->cycle_die -= vm->cycle_delta;
        vm->nbr_live = 0;
        return (0);
    }
    vm->nbr_live += 1;
    return (0);
}