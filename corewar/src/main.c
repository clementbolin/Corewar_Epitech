/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** main
*/

#include "corewar.h"

void help(void)
{
    my_printf("USAGE\n");
    my_printf("./corewar [-dump nbr_cycle] [[-n prog_number] ");
    my_printf("[-a load_address] prog_name] ...\nDESCRIPTION\n");
    my_printf("-dump nbr_cycle dumps the memory after the nbr_cycle execut");
    my_printf("ion (if the round isn’t\nalready over) ");
    my_printf("with the following format: 32 bytes/line\n");
    my_printf("in hexadecimal (A0BCDEFE1DD3...)\n");
    my_printf("-n prog_number sets the next program’s number. By default");
    my_printf(", the first free number\nin the parameter order\n");
    my_printf("-a load_address sets the next program’s loading address. ");
    my_printf("When no address\nis specified, optimize the addresses so that");
    my_printf(" the processes are as far\n");
    my_printf("away from each other as possible. The addresses are ");
    my_printf("MEM_SIZE modulo.\n");
}

int main(int ac UNUSED, char **av)
{
    cor_t vm;
    int bonus = bonus_flag(av);

    init_arena(&vm, av);
    if (vm.nb_champ > 4) {
        my_printf("Max champ is 4\n");
        return (84);
    }
    if (bonus == 1)
        bonus_display(&vm);
    else {
        while (1) {
            change_value_cycle(&vm);
            recup_inst_pc(&vm);
        }
    }
    return (0);
}