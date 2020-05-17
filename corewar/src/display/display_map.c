/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** display_map
*/

#include "corewar.h"

int number_digits(int nbr)
{
    int n = 1;
    int po = 10;

    if (nbr < 0)
        nbr = -nbr;
    while (nbr >= po) {
        n++;
        if (po > 214748364)
            break;
        po *= 10;
    }
    return (n);
}

char *my_itc(int nbr)
{
    int len = number_digits(nbr);
    char *result;

    result = malloc(sizeof(char) * (len + 1));
    result[len] = '\0';
    while (len--) {
        result[len] = nbr % 10 + '0';
        nbr /= 10;
    }
    return (result);
}

void display_info_reg(instance_t *inst, cor_t *vm, int x, int y)
{
    int color = 0;

    if (inst->player_actu > vm->nb_champ)
        return;
    for (int i = 0; i < NUMBER_REG_PRINT; i++) {
        color = vm->champ[inst->player_actu - 1].color;
        wattron(inst->sub_info, COLOR_PAIR(color));
        mvwprintw(inst->sub_info, y, x, "%02hhx",
        vm->champ[inst->player_actu - 1].reg[i]);
        wattroff(inst->sub_info, COLOR_PAIR(color));
        x += 3;
    }
    inst->player_actu++;
}

void display_info(instance_t *inst, cor_t *vm)
{
    int x = 2;
    int y = 2;
    int diff = COLS / 3;
    inst->player_actu = 1;
    mvwprintw(inst->sub_info, y, x, "Cycle To Die: %d", vm->cycle_die);
    display_info_reg(inst, vm, x + diff, y++);
    mvwprintw(inst->sub_info, y, x, "Cycle Deltat : %d", vm->cycle_delta);
    display_info_reg(inst, vm, x + diff, y++);
    mvwprintw(inst->sub_info, y, x, "Nbr Live : %d", vm->nbr_live);
    display_info_reg(inst, vm, x + diff, y++);
    mvwprintw(inst->sub_info, y, x, "Nbr_Champs : %d", vm->nb_champ);
    display_info_reg(inst, vm, x + diff, y++);
}

void display_map(cor_t *vm, instance_t *inst)
{
    noecho();
    wclear(inst->sub_win);
    for (int i = 0; i < MEM_SIZE; i++)
        display_map_color(vm, i, inst);
    display_info(inst, vm);
    wattron(inst->sub_info, COLOR_PAIR(1));
    box(inst->sub_info, ACS_VLINE, ACS_HLINE);
    wattroff(inst->sub_info, COLOR_PAIR(1));
    wattron(inst->sub_win, COLOR_PAIR(2));
    box(inst->sub_win, ACS_VLINE, ACS_HLINE);
    wattroff(inst->sub_win, COLOR_PAIR(2));
    usleep(8000);
    wrefresh(inst->sub_info);
    wrefresh(inst->sub_win);
    refresh();
    usleep(8000);
}