/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** fill_link_inst
*/

#include "corewar.h"

int fill_value_link(info_t info,linkv_t *l, char *mnemo, cor_t *vm)
{
    if (my_strcmp(info.str, "01") == 0) {
        add_node_inst(recup_value_one_arg(vm->map, info.tmp, 1), REG, l);
        info.tmp += 1;
    }
    if (my_strcmp(info.str, "11") == 0) {
        add_node_inst(recup_value_one_arg(vm->map, info.tmp, 2), IND, l);
        info.tmp += 2;
    }
    if (my_strcmp(info.str, "10") == 0) {
        if (check_special_val(mnemo) == 1) {
            add_node_inst(recup_value_one_arg(vm->map, info.tmp, 2), DIR, l);
            info.tmp += 2;
        } else {
            add_node_inst(recup_value_one_arg(vm->map, info.tmp, 4), DIR, l);
            info.tmp += 4;
        }
    }
    return (info.tmp);
}