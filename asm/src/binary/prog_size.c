/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** prog_size
*/

#include "asm.h"

int	convert_littleend_to_bigend_int(int nb)
{
    int res = 0;

    res = (nb & 0xFF000000) >> 24;
    res |= ((nb & 0x00FF0000) >> 8);
    res |= ((nb & 0x0000FF00) << 8);
    res |= ((nb & 0x000000FF) << 24);
    return (res);
}

int check_arg_type(char *str)
{
    char *arr[] = {"zjmp", "ldi", "sti", "fork", "lldi", "lfork", NULL};

    for (int i = 0; arr[i]; i += 1)
        if (my_strcmp(arr[i], str) == 0)
            return (0);
    return (1);
}

int recup_value_prog_size(link_t *link)
{
    node_t *node = link->head;
    int prg_size = 0;

    for (; node != NULL; node = node->next)
        if (my_strcmp(node->type, ".comment") == 0)
            break;
    node = node->next;
    for (; node; node = node->next) {
        prg_size += check_arg_type_one(node->type);
        for (int i = 0; node->arg[i]; i++)
            if (node->arg[i][0] == 'r')
                prg_size += 1;
            else if (node->arg[i][0] == '%')
                prg_size += check_arg_type_two(node->type);
            else
                prg_size += IND_SIZE;
    }
    return (prg_size);
}

char *decimal_to_hex(int nb)
{
    char *hex = malloc(sizeof(char) * 100);
    int i = 0;

    for (int temp = 0; nb != 0; nb /= 16) {
        temp = nb % 16;
        (temp < 10) ? (hex[i++] = temp + 48) :
        (hex[i++] = temp + 55);
    }
    return (hex);
}

void write_prog_size(asm_t *file UNUSED, link_t *link)
{
    int prog_size UNUSED = recup_value_prog_size(link);

    file->size = prog_size;
    prog_size = convert_littleend_to_bigend_int(prog_size);
    write(file->fd, &prog_size, sizeof(int));
}