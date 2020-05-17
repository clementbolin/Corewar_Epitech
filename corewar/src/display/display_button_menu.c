/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** display_button_menu.c
*/

#include "corewar.h"

void display_button_menu(UNUSED cor_t *cr, instance_t *inst)
{
    int x = 0;
    int y = 2;

    for (int i = 0; i < ((COLS / 2) - 2); i++)
        mvwprintw(inst->menu, y, x++, " ");
    mvwprintw(inst->menu, y, x, "GAME");
    y += 2;
    x = 0;
    for (int i = 0; i < ((COLS / 2) - 4); i++)
        mvwprintw(inst->menu, y, x++, " ");
    mvwprintw(inst->menu, y, x, "OPTIONS");
    y += 2;
    x = 0;
    for (int i = 0; i < ((COLS / 2) - 4); i++)
        mvwprintw(inst->menu, y, x++, " ");
    mvwprintw(inst->menu, y, x, "CREDITS");
    y += 2;
    x = 0;
    for (int i = 0; i < ((COLS / 2) - 2); i++)
        mvwprintw(inst->menu, y, x++, " ");
    mvwprintw(inst->menu, y, x, "QUIT");
}

void destroy_menu(instance_t *inst)
{
    if (inst->select == 0)
        inst->scene = GAME;
    if (inst->select == 1)
        inst->scene = GAME;
    if (inst->select == 2)
        inst->scene = GAME;
    if (inst->select == 3) {
        endwin();
        exit (0);
    }
    delwin(inst->menu);
    init_game(inst);
}

void ask_to_user_interaction(instance_t *inst)
{
    int c = wgetch(inst->menu);
    switch (c) {
        case 10:
            destroy_menu(inst);
            break;
        case KEY_UP:
            if (inst->select > 0)
                inst->select--;
            break;
        case KEY_DOWN:
            if (inst->select < 3)
                inst->select++;
            break;
        default:
            break;
    }
}

void display_cursor(instance_t *inst, int select)
{
    int where_x = (COLS / 2) - 7;

    switch (select) {
        case 0:
            mvwprintw(inst->menu, 2, where_x, ">");
            break;
        case 1:
            mvwprintw(inst->menu, 4, where_x, ">");
            break;
        case 2:
            mvwprintw(inst->menu, 6, where_x, ">");
            break;
        case 3:
            mvwprintw(inst->menu, 8, where_x, ">");
            break;
        default:
            break;
    }
}

void menu_bonus(cor_t *vm, UNUSED instance_t *inst)
{
    display_button_menu(vm ,inst);
    display_cursor(inst, inst->select);
    box(inst->menu, ACS_VLINE, ACS_HLINE);
    ask_to_user_interaction(inst);
}