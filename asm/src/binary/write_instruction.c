/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** write_instruction
*/

#include "asm.h"

int get_size(char *str, link_t *link UNUSED)
{
    node_t *node = link->head;

    for (; node != NULL; node = node->next)
        if (my_strcmp(str, node->label) == 0)
            return (get_string_size_three(link, str));
    exit(84);
    return (0);
}

void write_arg(node_t *node, asm_t *file, link_t *link UNUSED)
{
    int pos_node = 0;
    int pos_rel = 0;

    for (int i = 0; node->arg[i] != NULL; i++) {
        if (node->arg[i][0] == '%' && node->arg[i][1] == ':') {
            pos_node = get_string_size(node, link);
            pos_rel = get_size(node->arg[i] + 2, link);
            pos_node = pos_rel - pos_node;
            write_dir_arg(node, file, i, pos_node);
        }
        if (node->arg[i][0] == 'r')
            write_reg_arg(node, file, i, 0);
        if (node->arg[i][0] == '%' && node->arg[i][1] != ':')
            write_dir_arg(node, file, i, 0);
        if (node->arg[i][0] != 'r' && node->arg[i][0] != '%')
            write_ind_arg(node, file, i, 0);
    }
}

int getNum(char ch)
{
    int num = 0;

    if (ch >= '0' && ch <= '9')
        num = ch - 0x30;
    if (ch == 'A' || ch == 'a')
        num = 10;
    if (ch == 'B' || ch == 'b')
        num = 11;
    if (ch == 'C' || ch == 'c')
        num = 12;
    if (ch == 'D' || ch == 'd')
        num = 13;
    if (ch == 'E' || ch == 'e')
        num = 14;
    if (ch == 'F' || ch == 'f')
        num = 15;
    return (num);
}

int check_arg_type_size(char *str)
{
    char *arr[] = {"zjmp", "fork", "lfork", "live", NULL};

    for (int i = 0; arr[i]; i += 1)
        if (my_strcmp(arr[i], str) == 0)
            return (0);
    return (1);
}

void write_binary(asm_t *file UNUSED, link_t *link UNUSED)
{
    node_t *node = link->head;
    char c = '0';
    char *hex = NULL;
    char *value UNUSED = NULL;

    for (; node != NULL; node = node->next) {
        if (my_strcmp(node->type, ".comment") == 0)
            break;
    }
    node = node->next;
    for (; node != NULL; node = node->next) {
        write_code_type(node, file);
        value = check_type_arg(node->arg);
        hex = binary_to_hex(value);
        c = getNum(hex[0]) * 16 + getNum(hex[1]);
        if (check_arg_type_size(node->type) == 1)
            write(file->fd, &c, sizeof(c));
        write_arg(node, file, link);
    }
}