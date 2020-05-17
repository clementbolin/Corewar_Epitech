/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** fill_champ
*/

#include "corewar.h"

int big_to_litlle(int nb)
{
    nb = (((nb << 8) & 0xFF00FF00) | ((nb >> 8) &  0xFF00FF));
    nb = (nb << 16) | ((nb >> 16) & 0xFFFF);
    return (nb);
}

void recup_header_champ(champ_t *champ, char *path)
{
    int fd = open_file_champ(path);

    if (read(fd, &champ->header, sizeof(champ->header)) < 0) {
        putstr_error("ERROR: We can't read header champ\n");
        exit(84);
    }
    champ->header.prog_size = big_to_litlle(champ->header.prog_size);
    close(fd);
}

void recup_instruction_champ(champ_t *champ, char *path)
{
    int fd = open_file_champ(path);

    champ->inst = malloc(sizeof(char) * (champ->header.prog_size + 1 + 2192));
    if (read(fd, champ->inst, champ->header.prog_size + 2192) < 0) {
        putstr_error("ERROR: we can't recup inst for champ\n");
        exit(84);
    }
    champ->inst[champ->header.prog_size + 2192] = '\0';
    for (int i = 2192; i < champ->header.prog_size + 2192; i++)
        printf("inst[%d] = %02x\n", i, champ->inst[i]);
    close(fd);
}
