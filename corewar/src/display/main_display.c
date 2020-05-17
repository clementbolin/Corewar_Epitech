/*
** EPITECH PROJECT, 2019
** CPE_corewar_2019
** File description:
** main_display.c
*/

#include "corewar.h"
#include <termios.h>

int my_getch(void)
{
    struct termios oldt;
    struct termios newt;
    int ch = 0;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~( ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return (ch);
}

void init_game(instance_t *inst)
{
    inst->sub_win = subwin(stdscr, (LINES - LINES / 5), COLS, 0, 0);
    inst->sub_info = subwin(stdscr, LINES / 5, COLS, LINES - (LINES / 5), 0);
}

void init_all_bonus(UNUSED cor_t *vm, instance_t *inst)
{
    initscr();
    noecho();
    cbreak();
    init_color_map();
    curs_set(0);
    timeout(10);
    inst->scene = 77;
    inst->window_status = TRUE;
    inst->select = 0;
    inst->menu = subwin(stdscr, LINES / 2, COLS, (LINES / 2) - LINES / 4 , 0);
    keypad(inst->menu, TRUE);
}

int intro(UNUSED cor_t *vm, UNUSED instance_t *inst, int y)
{
    clear();
    int x = (COLS / 2) - ( 67 / 2);
    attron(COLOR_PAIR(PLAYER4));
    mvprintw(y--, x++, ":......::::.......:::..:::::..::\
    :...::...:::..:::::..::..:::::..::");
    mvprintw(y--, x++, ". ######::. #######:: ##:::. ##:\
    . ###. ###:: ##:::: ##: ##:::. ##:");
    mvprintw(y--, x++, " ##:::..:: ##:::: ##: ##:::: ##:\
    ##: ##: ##::'##:. ##:: ##:::: ##:");
    mvprintw(y--, x++, " ##::::::: ##:::: ##: ########::\
    ##: ##: ##:'##:::. ##: ########::");
    mvprintw(y--, x++, " ##::::::: ##:::: ##: ##.. ##:::\
    ##: ##: ##: #########: ##.. ##:::");
    mvprintw(y--, x++, " ##::: ##: ##:::: ##: ##::. ##::\
    ##: ##: ##: ##.... ##: ##::. ##::");
    mvprintw(y--, x++, "'##... ##:'##.... ##: ##.... ##:\
    ##:'##: ##:::'## ##::: ##.... ##:");
    mvprintw(y--, x++, ":'######:::'#######::'########::\
    '##:::::'##::::'###::::'########::");
    attroff(COLOR_PAIR(PLAYER4));
    refresh();
    usleep(800000);
    return (y);
}

void bonus_display(cor_t *vm)
{
    instance_t *inst = malloc(sizeof(instance_t));
    int y = LINES;
    init_all_bonus(vm, inst);
    y = LINES;
    for (int c = 0; change_value_cycle(vm) == 0;) {
        if (inst->scene == 77) {
            y = intro(vm, inst, y);
            if (y < 0)
                inst->scene = NO_INIT;
        }
        if (inst->scene == NO_INIT)
            menu_bonus(vm ,inst);
        if (inst->scene == GAME) {
            display_map(vm, inst);
            recup_inst_pc(vm);
        }
        c = getch();
        if (c == 'q') break;
    }
    endwin();
}