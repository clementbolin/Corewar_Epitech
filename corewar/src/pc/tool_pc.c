/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** tool_pc
*/

#include "corewar.h"

char *return_cdg_bin(int cdg_byte)
{
    char *tmp = 0;
    char *cdg_bin = my_putnbr_base(cdg_byte, "01");
    int j = 1;

    if (my_strlen(cdg_bin) == 7) {
        tmp = my_strcpy(tmp, cdg_bin);
        cdg_bin[0] = '0';
        for (int i = 0; tmp[i]; i++, j++)
            cdg_bin[j] = tmp[i];
        cdg_bin[j] = '\0';
    }
    return (cdg_bin);
}