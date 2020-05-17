/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** init_arena
*/

#include "corewar.h"

void cpy_champ_in_vm(cor_t *vm)
{
    int r = 0;

    printf("nb champ: %d\n", vm->nb_champ);
    for (int i = 0; i < vm->nb_champ; i++) {
        r = MEM_SIZE/(5-i);
        vm->champ[i].pc = r;
        vm->champ[i].basic_pc = r;
        vm->champ[i].max_pc = r + vm->champ[i].header.prog_size;
        for (int j = 2192; j < vm->champ[i].header.prog_size+2192; j++, r++)
            vm->map[r] = vm->champ[i].inst[j];
    }
}

void init_arena(cor_t *cor, char **av)
{
    cor->map = malloc(sizeof(char) * (MEM_SIZE + 1));
    cor->map[MEM_SIZE] = '\0';
    cor->champ = init_champion(av);
    cor->nb_champ = nb_champ(av);
    cor->draw = 0;
    cor->carry = 0;
    cpy_champ_in_vm(cor);
    init_map_color(cor);
    cor->cycle_die = CYCLE_TO_DIE;
    cor->cycle_delta = CYCLE_DELTA;
    cor->nbr_live = 0;
}