/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** log
*/

#include "asm.h"

void consolog(int etat)
{
    if (etat == 1) {
        my_printf("\033[1;32mStart Compilation\n");
        my_printf("\033[1;33m|\n ->Start Create File .cor\n");
        my_printf("\033[0m");
    }
    if (etat == 2) {
        my_printf("\033[1;32m-> File Project create Done\n\n");
        my_printf("\033[1;33m|\n ->Start write Header\n");
        my_printf("\033[0m");
    }
    if (etat == 3) {
        my_printf("\033[1;32m-> Header Write Done\n\n");
        my_printf("\033[1;33m|\n ->Start Write Binary\n");
        my_printf("\033[0m");
    }
    if (etat == 4) {
        my_printf("\033[1;32mThe Compil is a succes\n");
        my_printf("\033[0m");
    }
}