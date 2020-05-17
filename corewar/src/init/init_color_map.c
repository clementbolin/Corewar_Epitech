/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** second_map
*/

#include "corewar.h"

void init_color_map(void)
{
    start_color();
    init_pair(PLAYER1, COLOR_RED, COLOR_BLACK);
    init_pair(PLAYER2, COLOR_BLUE, COLOR_BLACK);
    init_pair(PLAYER3, COLOR_GREEN, COLOR_BLACK);
    init_pair(PLAYER4, COLOR_YELLOW, COLOR_BLACK);
    init_pair(PC1, COLOR_WHITE, COLOR_RED);
    init_pair(PC2, COLOR_WHITE, COLOR_BLUE);
    init_pair(PC3, COLOR_WHITE, COLOR_GREEN);
    init_pair(PC4, COLOR_WHITE, COLOR_YELLOW);
}

void init_map_color(cor_t *vm)
{
    int i = 0;
    int r = 0;

    vm->txt = malloc(sizeof(char) * (MEM_SIZE+1));
    for (; i < vm->nb_champ; i++) {
        r = MEM_SIZE/(5-i);
        for (int j = 2192; j < vm->champ[i].header.prog_size+2192; j++, r++) {
            if (i == 0)
                vm->txt[r] = 'r';
            if (i == 1)
                vm->txt[r] = 'b';
            if (i == 2)
                vm->txt[r] = 'g';
            if (i == 3)
                vm->txt[r] = 'y';
        }
    }
}