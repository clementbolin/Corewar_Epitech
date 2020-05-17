/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** manage_instruction
*/

#include "corewar.h"

static array_t inst_array[] = {
    {"ld", 5, ld},
    {"st", 5, st},
    {"add", 10, add},
    {"sub", 10, sub},
    {"and", 6, and},
    {"xor", 6, xor},
    {"xor", 6, or},
    {"xor", 6, ldi},
    {"sti", 25, sti},
    {"lld", 5, lld},
    {0, 0, 0}
};

int recup_value_one_arg(char *arena, int pc, int size)
{
    int nb = 0;

    for (int i = 0; i < size; i += 1) {
        nb = nb << 8;
        nb += arena[pc % MEM_SIZE];
        pc += 1;
    }
    return (nb);
}

linkv_t *recup_link_inst(cor_t *vm UNUSED, champ_t *champ, char *cdg_bin UNUSED, char *mnemo)
{
    int j = 0;
    linkv_t *link = init_list_inst();
    info_t info;

    info.str = malloc(sizeof(char) * 10);
    info.tmp = champ->last_pc+2;
    for (int i = 0; cdg_bin[i]; i++) {
        if (j == 2) {
            info.str[j] = '\0';
            info.tmp = fill_value_link(info, link, mnemo, vm);
            free(info.str);
            info.str = malloc(sizeof(char) * 10);
            j = 0;
        }
        info.str[j] = cdg_bin[i];
        j += 1;
    }
    free(info.str);
    return (link);
}

int check_cycle_ft(cor_t *vm, champ_t *champ, char *cdg_bin, char *mnemo)
{
    linkv_t *link = NULL;
    int i = 0;

    for (; inst_array[i].mnemonique != 0; i++) {
        if (my_strcmp(inst_array[i].mnemonique, mnemo) == 0)
            break;
    }
    if (champ->cycle >= inst_array[i].cycle) {
        link = recup_link_inst(vm, champ, cdg_bin, mnemo);
        inst_array[i].ft(vm, champ, link);
        champ->etat = 0;
        champ->cycle = 0;
        destroy_link_inst(link);
        return (1);
    }
    return (0);
}

void manage_instruction(cor_t *vm, champ_t *champ, char *cdg_bin, char *mnemo)
{
    linkv_t *link UNUSED= NULL;
    int i = 0;

    if (champ->etat == 0) {
        for (; inst_array[i].mnemonique != 0; i++) {
            if (my_strcmp(inst_array[i].mnemonique, mnemo) == 0) {
                champ->cycle = 0;
                champ->etat = 1;
            }
        }
    } else {
        if (check_cycle_ft(vm, champ, cdg_bin, mnemo) == 1) return;
    }
    champ->cycle += 1;
}