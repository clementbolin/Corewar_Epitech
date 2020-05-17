/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** bonus.h
*/

#ifndef COREWAR_BONUS_NCURSE_H
#define COREWAR_BONUS_NCURSE_H

#include "struct.h"
#include <ncurses.h>

typedef int my_bool;

#define true 1
#define false 0
#define NO_INIT -1
#define NUMBER_REG_PRINT 16

typedef enum {
    MENU,
    GAME,
    CREDITS,
    OPTIONS,
} scene_t;

typedef struct instance_bonus_s {
    my_bool window_status;
    int scene;
    int select;
    int player_actu;
    WINDOW *menu;
    WINDOW *sub_win;
    WINDOW *sub_info;
} instance_t;

void display_map_color(cor_t *vm, int i, instance_t *inst);
void bonus_display(cor_t *vm);
void destroy_menu(instance_t *inst);
void init_game(instance_t *inst);
void display_map(cor_t *vm, instance_t *inst);
void menu_bonus(cor_t *vm, UNUSED instance_t *inst);
void and(cor_t *vm UNUSED, champ_t *champ, linkv_t *link);

#endif /* COREWAR_BONUS_NCURSE_H */