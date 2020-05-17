/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** fill_link
*/

#include "asm.h"

char *only_get_name_two(char *str, int size, char *res)
{
    res = malloc(sizeof(char) * (size + 1));
    res[size] = '\0';
    for (int i = 0; str[i]; i += 1) {
        for (;str[i] != '"'; i += 1);
        i += 1;
        for (size = 0 ;str[i] != '"'; size += 1, i += 1)
            res[size] = str[i];
    }
    return (res);
}

char *only_get_name(char *str)
{
    int size = 0;
    char *res = NULL;

    for (int i = 0; str[i]; i += 1) {
        for (;str[i] != '"'; i += 1)
            if (str[i] == '\0')
                return (NULL);
        i += 1;
        for (size = 0 ;str[i] != '"'; size += 1, i += 1)
            if (str[i] == '\0')
                return (NULL);
    }
    return (only_get_name_two(str, size, res));
}

node_t *put_header_node_two(char *str, char *type, char *label)
{
    node_t *node = malloc(sizeof(*node));

    node->type = my_strcpy(node->type, type);
    node->arg = malloc(sizeof(char *) * 2);
    node->arg[0] = my_strcpy(node->arg[0], str);
    node->arg[1] = NULL;
    if (label != NULL)
        node->label = my_strcpy(node->label, label);
    else
        node->label = NULL;
    node->next = NULL;
    return (node);
}

void put_header_node(char *str, link_t *link, char *type, char *label)
{
    node_t *node = NULL;

    if (!link->head)
        link->head = put_header_node_two(str, type, label);
    else {
        node = link->head;
        for (; node->next != NULL; node = node->next);
        node->next = put_header_node_two(str, type, label);
    }
}

char *get_label(char *str)
{
    char *res = NULL;
    int i = 0;

    for (i = 0; str[i] != ':'; i += 1);
    res = malloc(sizeof(char) * (i + 1));
    res[i] = '\0';
    for (i = 0; str[i] != ':'; i += 1)
        res[i] = str[i];
    return (res);
}
