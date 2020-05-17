/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** main
*/

#include "asm.h"

int check_type(link_t *link)
{
    int pos = -1;
    int size = 0;

    for (node_t *node = link->head; node; node = node->next) {
        if (my_strcmp_dot(".comment\0", node->type) == 0 ||
        my_strcmp_dot(".name\0", node->type) == 0)
            continue;
        for (int i = 0; op_tab[i].mnemonique != 0; i++)
            (my_strcmp(op_tab[i].mnemonique, node->type) == 0) ? (pos = i) :
            (size = 0);
        if (pos == -1)
            return (84);
        for (int i = 0; node->arg[i]; i++)
            (node->arg[i][0] == '\0') ? (size += 0) : (size += 1);
        if (op_tab[pos].nbr_args != size)
            return (84);
        pos = -1;
    }
    return (0);
}

int check_comment_name(link_t *link)
{
    node_t *node = link->head;

    if (my_strcmp_dot(".name\0", node->type) != 0 ||
    my_strcmp_dot(".comment\0", node->next->type) != 0)
        return (84);
    for (int i = 0; node != NULL; node = node->next, i += 1)
        if (i < 2)
            continue;
        else if (my_strcmp_dot(".name\0", node->type) == 0 ||
        my_strcmp_dot(".comment\0", node->type) == 0)
            return (84);
    for (node = link->head; node != NULL; node = node->next)
        if ((my_strcmp_dot(".comment\0", node->type) == 0 &&
        my_strlen(node->arg[0]) > COMMENT_LENGTH) ||
        (my_strcmp_dot(".name\0", node->type) == 0 &&
        my_strlen(node->arg[0]) > PROG_NAME_LENGTH))
            return (84);
    return (0);
}

int main_init(char *av, asm_t *champ, link_t *link UNUSED)
{
    if (init_champ(av, champ) == 84)
        return (84);
    link->head = NULL;
    create_link_inst(champ, link);
    for (node_t *node = link->head; node; node = node->next)
        if (my_strcmp_dot(".comment", node->type) != 0 &&
        my_strcmp_dot(".name", node->type) != 0)
            node->arg = str_to_array(node->arg[0], ' ');
    if (check_type(link) == 84 || check_pre_label(link) == 84 ||
    check_comment_name(link) == 84)
        return (84);
    return (0);
}
