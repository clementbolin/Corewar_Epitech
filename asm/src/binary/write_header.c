/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** test_write
*/

#include "asm.h"

char *value_str_header(char *str, int size)
{
    char *value = malloc(sizeof(char) * size);
    int j = 0;
    int i = 1;

    if (str[0] == '\0')
        return (NULL);
    for (int a = 0; a < size; a++)
        value[a] = '\0';
    for (; str[i] != '"'; i++, j++)
        value[j] = str[i];
    value[j] = '\0';
    return (value);
}

char *value_node_header(link_t *link, char *search)
{
    node_t *node = link->head;

    for (; node != NULL; node = node->next)
        if (my_strcmp(node->type, search) == 0)
            break;
    if (my_strcmp(search, ".comment") == 0) {
        for (int i = 1; node->arg[i]; i++) {
            node->arg[0] = my_strcat(node->arg[0], " ");
            node->arg[0] = my_strcat(node->arg[0], node->arg[i]);
        }
        return (value_str_header(node->arg[0], COMMENT_LENGTH));
    }
    return (value_str_header(node->arg[0], PROG_NAME_LENGTH));
}

void write_comment(asm_t *file, link_t *link)
{
    char *str = malloc(sizeof(char) * COMMENT_LENGTH);
    int tmp UNUSED = 0;
    int len = COMMENT_LENGTH;

    for (node_t *node = link->head; node; node = node->next)
        if (my_strcmp_dot(".comment\0", node->type) == 0) {
            for (int i = 0; i < COMMENT_LENGTH; i += 1)
                str[i] = '\0';
            for (int i = 0; node->arg[0][i]; i += 1)
                str[i] = node->arg[0][i];
        }
    write(file->fd, str, my_strlen(str));
    len -= my_strlen(str);
    free(str);
    for (int i = 0; i < len; i++)
        write(file->fd, "\0", 1);
    write(file->fd, &tmp, sizeof(tmp));
}

void write_header_two(asm_t *file, link_t *link, int len)
{
    int tmp UNUSED = 0;

    for (int i = 0; i < len; i++)
        write(file->fd, "\0", 1);
    write(file->fd, &tmp, sizeof(tmp));
    write_prog_size(file, link);
    write_comment(file, link);
}

void write_header(asm_t *file, link_t *link UNUSED)
{
    char *str = malloc(sizeof(char) * PROG_NAME_LENGTH);
    int magic = COREWAR_EXEC_MAGIC;
    int len = PROG_NAME_LENGTH;

    magic = convert_littleend_to_bigend_int(magic);
    write(file->fd, &magic, sizeof(magic));
    for (node_t *node = link->head; node; node = node->next)
        if (my_strcmp_dot(".name\0", node->type) == 0) {
            for (int i = 0; i < PROG_NAME_LENGTH; i += 1)
                str[i] = '\0';
            for (int i = 0; node->arg[0][i]; i += 1)
                str[i] = node->arg[0][i];
        }
    write(file->fd, str, my_strlen(str));
    len -= my_strlen(str);
    free(str);
    write_header_two(file, link, len);
}