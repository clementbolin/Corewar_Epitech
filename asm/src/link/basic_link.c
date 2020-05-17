/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** basic link
*/

#include "asm.h"

link_t *init_link(void)
{
    link_t *link = malloc(sizeof(link));

    if (!link)
        exit(84);
    link->head = NULL;
    return (link);
}

void delete_node(int size, link_t *link)
{
    node_t *current = link->head;
    node_t *prev = current;
    int i = 0;

    while (current != NULL) {
        if (i == size) {
            prev->next = current->next;
            (current == link->head) ? (link->head = current->next) :
            (link->head = link->head);
            free(current);
            return;
        }
        prev = current;
        current = current->next;
        i += 1;
    }
}

void destroy_link(link_t *link)
{
    node_t *current = link->head;
    node_t *next = current;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    free(link);
}