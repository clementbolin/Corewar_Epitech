/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** basic_link
*/

#include "corewar.h"

linkv_t *init_list_inst(void)
{
    linkv_t *link = malloc(sizeof(link));

    if (!link)
        exit(84);
    link->head = NULL;
    return (link);
}

void delete_node_inst(int size, linkv_t *link)
{
    nodev_t *current = link->head;
    nodev_t *prev = current;
    int i = 0;

    while (current != NULL) {
        if (i == size) {
            prev->next = current->next;
            if (current == link->head)
                link->head = current->next;
            free(current);
            return;
        }
        prev = current;
        current = current->next;
        i += 1;
    }
}

void destroy_link_inst(linkv_t *link)
{
    nodev_t *current = link->head;
    nodev_t *next = current;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    free(link);
}