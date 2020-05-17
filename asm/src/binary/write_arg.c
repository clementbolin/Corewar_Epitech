/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** write_arg
*/

#include "asm.h"

void write_reg_arg(node_t *node, asm_t *file, int i, int offset)
{
    int res = 0;
    char *str = malloc(sizeof(char) * 100);
    int ind = 0;

    for (int j = 1; node->arg[i][j]; j++, ind++)
        str[ind] = node->arg[i][j];
    str[ind] = '\0';
    if (offset < 0)
        offset = 256 + offset;
    res = my_getnbr(str);
    write(file->fd, &res, 1);
    free(str);
}

void write_dir_arg_two(asm_t *file, int offset, int res)
{
    if (offset == 0) {
        res = SWAP_INT_TO_WRITE(res);
        res = (res << 16) | (res >> 16);
        write(file->fd, &res, IND_SIZE);
    } else {
        offset = SWAP_INT_TO_WRITE(offset);
        offset = (offset << 16) | (offset >> 16);
        write(file->fd, &offset, IND_SIZE);
    }
}

void write_dir_arg_four(asm_t *file, int offset, int res)
{
    if (offset == 0) {
        res = SWAP_INT_TO_WRITE(res);
        write(file->fd, &res, DIR_SIZE);
    } else {
        offset = SWAP_INT_TO_WRITE(offset);
        write(file->fd, &offset, DIR_SIZE);
    }
}

void write_dir_arg(node_t *node, asm_t *file, int i, int offset)
{
    int res = 0;
    char *str = malloc(sizeof(char) * 100);
    int ind = 0;

    for (int j = 1; node->arg[i][j]; j++, ind++)
        str[ind] = node->arg[i][j];
    str[ind] = '\0';
    res = 0;
    res = my_getnbr(str);
    if (check_arg_type(node->type) == 0)
        write_dir_arg_two(file, offset, res);
    else
        write_dir_arg_four(file, offset, res);
    free(str);
}

void write_ind_arg(node_t *node, asm_t *file, int i, int offset)
{
    int res = 0;
    char *str = malloc(sizeof(char) * 100);
    int ind = 0;

    for (int j = 0; node->arg[i][j]; j++, ind++)
        str[ind] = node->arg[i][j];
    str[ind] = '\0';
    if (offset < 0)
        offset = 256 + offset;
    res = my_getnbr(str);
    res = SWAP_INT_TO_WRITE(res);
    res = (res << 16) | (res >> 16);
    write(file->fd, &res, IND_SIZE);
    free(str);
}
