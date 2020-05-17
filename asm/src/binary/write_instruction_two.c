/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** write_instruction
*/

#include "asm.h"

char *check_type_arg(char **arg)
{
    char *str = malloc(sizeof(int));
    int len = 0;

    str[0] = '\0';
    for (int i = 0; arg[i]; i++) {
        if (arg[i][0] == 'r')
            str = my_strcat(str, "01");
        else if (arg[i][0] == '%')
            str = my_strcat(str, "10");
        else
            str = my_strcat(str, "11");
    }
    if ((len = my_strlen(str)) != 8) {
        for (; len != 8; len++)
            str = my_strcat(str, "0");
    }
    return (str);
}

void write_code_type(node_t *node, asm_t *file)
{
    int i = 0;

    for (; op_tab[i].mnemonique != 0; i++) {
        if (my_strcmp(node->type, op_tab[i].mnemonique) == 0)
            break;
    }
    write(file->fd, &op_tab[i].code, sizeof(op_tab[i].code));
}

int check_node(node_t *temp, node_t *node)
{
    if (my_strcmp(node->type, temp->type) != 0 ||
    node->used == 1)
        return (0);
    for (int i = 0; node->arg[i]; i += 1)
        if (my_strcmp(node->arg[i], temp->arg[i]) != 0)
            return (0);
    node->used = 1;
    return (1);
}

int get_string_size(node_t *temp, link_t *link UNUSED)
{
    node_t *node = link->head;
    int prg_size = 0;

    for (; node != NULL; node = node->next)
        if (my_strcmp(node->type, ".comment") == 0)
            break;
    node = node->next;
    for (; node != NULL; node = node->next) {
        if (check_node(temp, node) == 1)
            return (prg_size + 1);
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

int get_string_size_three(link_t *link UNUSED, char *str)
{
    node_t *node = link->head;
    int prg_size = 0;

    for (; node != NULL; node = node->next)
        if (my_strcmp(node->type, ".comment") == 0)
            break;
    node = node->next;
    for (; node != NULL; node = node->next) {
        if (my_strcmp(str, node->label) == 0)
            return (prg_size + 1);
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