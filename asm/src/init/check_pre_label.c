/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** main
*/

#include "asm.h"

void check_pre_label_three(char *str, int *pos, link_t *link, int *error)
{
    for (node_t *tmp = link->head; tmp; tmp = tmp->next)
        if (my_strcmp(tmp->label, str + 2) == 0)
            *pos = -1;
    if (*pos != -1)
        *error = 84;
    *pos = 0;
}

void check_pre_label_two(char *str, int *pos, link_t *link, int *error)
{
    for (int j = 0; str[j]; j++)
        if (str[0] == '%' && str[1] == ':')
            check_pre_label_three(str, pos, link, error);
}

int check_pre_label(link_t *link)
{
    int pos = 0;
    int error = 0;

    for (node_t *node = link->head; node; node = node->next) {
        pos = 0;
        for (int i = 0; node->arg[i]; i++)
            check_pre_label_two(node->arg[i], &pos, link, &error);
    }
    return (error);
}