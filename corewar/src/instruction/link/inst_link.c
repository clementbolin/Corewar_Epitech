/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** inst_link
*/

#include "corewar.h"

nodev_t *create_node_inst(int value, type_e type)
{
    nodev_t *node = malloc(sizeof(*node));

    if (!node)
        exit(84);
    node->value = value;
    node->type = type;
    node->next = NULL;
    return (node);
}

void add_node_inst(int value, type_e type, linkv_t *link)
{
    nodev_t *node = NULL;

    if (link->head == NULL)
        link->head = create_node_inst(value, type);
    else {
        node = link->head;
        for (; node->next != NULL; node = node->next);
        node->next = create_node_inst(value, type);
    }
}

void display_link_instruction(linkv_t *link)
{
    nodev_t *node = link->head;

    if (node == NULL)
        my_printf("Link is NULL\n");
    for (int i = 0; node != NULL; node = node->next) {
        printf("id: %d [DATA]-> value: %d type: %d\n", i, node->value, \
        node->type);
    }
}