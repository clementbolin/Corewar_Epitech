/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** init_register
*/

#include "corewar.h"

void init_register_champ(champ_t *champ, int id)
{
    for (int i = 0; i < 16; i++)
        champ->reg[i] = 0;
    champ->reg[0] = id;
    champ->live = 0;
}