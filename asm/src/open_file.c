/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** open file
*/

#include "asm.h"

int create_file(char const *path)
{
    int fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0677);

    if (fd < 0) {
        write(2, "ERROR: we can't create binary file\n", 36);
        return (84);
    }
    return (fd);
}