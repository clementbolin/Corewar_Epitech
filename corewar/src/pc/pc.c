/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** pc
*/

#include "corewar.h"

int check_special_val(char *mnemonique)
{
    char *tab[] = {"ldi", "sti", "fork", "lldi", "lfork", 0};

    for (int i = 0; tab[i]; i++) {
        if (my_strcmp(tab[i], mnemonique) == 0)
            return (1);
    }
    return (0);
}

int return_byte_read(char *mnemonique, char *cdg_bin UNUSED)
{
    char *str = malloc(sizeof(char) * 10);
    int j = 0;
    int res = 0;

    for (int i = 0; cdg_bin[i]; i++) {
        if (j == 2) {
            str[j] = '\0';
            res += increase_pc(str, mnemonique);
            free(str);
            str = malloc(sizeof(char) * 10);
            j = 0;
        }
        str[j] = cdg_bin[i];
        j += 1;
    }
    free(str);
    return (res+2);
}

void check_inst_type(int inst, champ_t *champ, int cdg_byte, cor_t *vm)
{
    int i = 0;
    char *cdg_bin = return_cdg_bin(cdg_byte);

    for (; op_tab[i].code != 0; i++) {
        if (op_tab[i].code == inst)
            break;
    }
    if (special_value(i, vm, champ) == 1) return;
    champ->last_pc = champ->pc;
    manage_instruction(vm, champ, cdg_bin, op_tab[i].mnemonique);
    if (champ->etat == 0) {
        champ->pc += return_byte_read(op_tab[i].mnemonique, cdg_bin);
    }
    free(cdg_bin);
}

void recup_inst_pc(cor_t *vm)
{
    int inst = 0;
    int cdg_byte = 0;

    for (int i = 0; i != vm->nb_champ; i++) {
        if (vm->champ[i].live < 0) continue;
        if (vm->champ[i].pc >= vm->champ[i].max_pc)
            vm->champ[i].pc = vm->champ[i].basic_pc;
        inst = 0x0FF & vm->map[vm->champ[i].pc];
        cdg_byte = 0x0FF & vm->map[vm->champ[i].pc+1];
        check_inst_type(inst, &vm->champ[i], cdg_byte, vm);
    }
}