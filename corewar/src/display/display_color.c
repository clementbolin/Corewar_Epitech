/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** display_color
*/

#include "corewar.h"

void display_map_color2(cor_t *vm, int i, instance_t *inst)
{
    if (vm->txt[i] == 'g') {
        wattron(inst->sub_win, COLOR_PAIR(PLAYER3));
        wprintw(inst->sub_win, "%02hhx", vm->map[i]);
        wattroff(inst->sub_win, COLOR_PAIR(PLAYER3));
    }
    if (vm->txt[i] == 'y') {
        wattron(inst->sub_win, COLOR_PAIR(PLAYER4));
        wprintw(inst->sub_win, "%02hhx", vm->map[i]);
        wattroff(inst->sub_win, COLOR_PAIR(PLAYER4));
    }
    if (vm->txt[i] != 'r' && vm->txt[i] != 'y' && \
    vm->txt[i] != 'g' && vm->txt[i] != 'b')
    wprintw(inst->sub_win, "%02hhx", vm->map[i]);
}

void display_map_color(cor_t *vm, int i, instance_t *inst)
{
    for (int j = 0; j < vm->nb_champ; j++) {
        if (i == vm->champ[j].pc) {
            wattron(inst->sub_win, COLOR_PAIR(vm->txt[i] == 'r' ? 1 :
            (vm->txt[i] == 'b' ? 2 : (vm->txt[i] == 'g' ? 3 : 4))));
            wattron(inst->sub_win, A_BOLD);
            wprintw(inst->sub_win, "%02hhx", vm->map[i]);
            wattroff(inst->sub_win, A_BOLD);
            wattroff(inst->sub_win, COLOR_PAIR(vm->txt[i] == 'r' ? 1 :
            (vm->txt[i] == 'b' ? 2 : (vm->txt[i] == 'g' ? 3 : 4))));
            return;
        }
    }
    if (vm->txt[i] == 'r') {
        wattron(inst->sub_win, COLOR_PAIR(PLAYER1));
        wprintw(inst->sub_win, "%02hhx", vm->map[i]);
        wattroff(inst->sub_win, COLOR_PAIR(PLAYER1));
    }
    if (vm->txt[i] == 'b') {
        wattron(inst->sub_win, COLOR_PAIR(PLAYER2));
        wprintw(inst->sub_win, "%02hhx", vm->map[i]);
        wattroff(inst->sub_win, COLOR_PAIR(PLAYER2));
    }
    display_map_color2(vm, i, inst);
}

void display_pc_player(cor_t *vm)
{
    if (vm->nb_champ == 1) {
        attron(COLOR_PAIR(PC1));
        printw("%02hhx", vm->map[vm->champ[0].pc]);
        attroff(COLOR_PAIR(PC1));
    }
    if (vm->nb_champ <= 2) {
        attron(COLOR_PAIR(PC2));
        printw("%02hhx", vm->map[vm->champ[1].pc]);
        attroff(COLOR_PAIR(PC2));
    }
    if (vm->nb_champ <= 3) {
        attron(COLOR_PAIR(PC3));
        printw("%02hhx", vm->map[vm->champ[2].pc]);
        attroff(COLOR_PAIR(PC3));
    }
    if (vm->nb_champ <= 4) {
        attron(COLOR_PAIR(PC4));
        printw("%02hhx", vm->map[vm->champ[3].pc]);
        attroff(COLOR_PAIR(PC4));
    }
}