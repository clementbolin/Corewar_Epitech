/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** tool_inst
*/

#include "corewar.h"

int recup_value_reg(champ_t *champ, int id)
{
    if (id > 16)
        return (0);
    return (champ->reg[id]);
}

void write_color_in_map(champ_t *champ, cor_t *vm, int id)
{
    if (champ->color == 1)
        vm->txt[id] = 'r';
    if (champ->color == 2)
        vm->txt[id] = 'b';
    if (champ->color == 3)
        vm->txt[id] = 'g';
    if (champ->color == 4)
        vm->txt[id] = 'y';
}