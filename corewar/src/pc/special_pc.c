/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** special_pc
*/

#include "corewar.h"

static ar_t array_spe[] = {
    {"live", 10, live},
    {0, 0, 0}
};

int check_cycle_spe_ft(cor_t *vm, champ_t *champ, char *mnemo)
{
    int i = 0;

    for (; array_spe[i].mnemo != 0; i++) {
        if (my_strcmp(array_spe[i].mnemo, mnemo) == 0)
            break;
    }
    if (champ->cycle >= array_spe[i].cycle) {
        array_spe[i].ft(vm, champ);
        champ->etat = 0;
        champ->cycle = 0;
        return (1);
    }
    return (0);
}

int manage_tab_inst_spe(cor_t *vm, champ_t *champ, char *mnemo)
{
    if (champ->etat == 0) {
        for (int i = 0; array_spe[i].mnemo != 0; i++) {
            if (my_strcmp(array_spe[i].mnemo, mnemo) == 0) {
                champ->cycle = 0;
                champ->etat = 1;
            }
        }
    } else
        if (check_cycle_spe_ft(vm, champ, mnemo) == 1) return (1);
    if (champ->etat == 0) return (1);
    champ->cycle += 1;
    return (0);
}

int special_value2(int i, cor_t *vm UNUSED, champ_t *champ)
{
    if (my_strcmp(op_tab[i].mnemonique, "lfork") == 0) {
        if (manage_tab_inst_spe(vm, champ, "lfork") == 1)
            champ->pc += 3;
        return (1);
    }
    if (my_strcmp(op_tab[i].mnemonique, "aff") == 0) {
        if (manage_tab_inst_spe(vm, champ, "aff") == 1)
            champ->pc += 2;
        return (1);
    }
    return (0);
}

int special_value(int i, cor_t *vm UNUSED, champ_t *champ)
{
    if (my_strcmp(op_tab[i].mnemonique, "live") == 0) {
        if (manage_tab_inst_spe(vm, champ, "live") == 1)
            champ->pc += 5;
        return (1);
    }
    if (my_strcmp(op_tab[i].mnemonique, "zjmp") == 0) {
        if (manage_tab_inst_spe(vm, champ, "zjmp") == 1)
            champ->pc += 3;
        return (1);
    }
    if (my_strcmp(op_tab[i].mnemonique, "fork") == 0) {
        if (manage_tab_inst_spe(vm, champ, "fork") == 1)
            champ->pc += 3;
        return (1);
    }
    if (special_value2(i, vm, champ) == 1) return (1);
    return (0);
}