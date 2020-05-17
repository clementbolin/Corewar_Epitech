/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** fill_link
*/

#include "asm.h"

char *get_type_two(char *str, int i, char *res)
{
    for (i = 0; str[i] != ' ' && str[i]; i += 1);
    res = malloc(sizeof(*res) * (i + 1));
    res[i] = '\0';
    for (i = 0; str[i] != ' ' && str[i]; i += 1)
        res[i] = str[i];
    return (res);
}

char *get_type(char *str)
{
    int tmp = 0;
    char *res = NULL;
    int i = 0;

    for (i = 0; str[i]; i += 1)
        if (str[i] == ':' && str[i - 1] != '%') {
            tmp = 1;
            break;
        }
    if (tmp == 1) {
        i += 2;
        for (tmp = i; str[i] != ' ' && str[i]; i += 1);
        res = malloc(sizeof(*res) * (i + 1 - tmp));
        res[i - tmp] = '\0';
        for (i = 0; str[tmp + i] != ' ' && str[i]; i += 1)
            res[i] = str[tmp + i];
        return (res);
    }
    return (get_type_two(str, i, res));
}

int check_file_label(char *str)
{
    int i = 0;

    for (i = 0; str[i] != ':' && str[i]; i += 1);
    if (!str[i])
        return (1);
    return (0);
}

void create_link_inst(asm_t *f, link_t *l UNUSED)
{
    char *tmp = NULL;
    int i UNUSED = 0;

    for (int i = 0; f->file[i]; i += 1) {
        if (is_label(f->file[i]) == 1) {
            tmp = get_label(f->file[i]);
            (get_args(f->file[i]) == NULL) ? (i += 1) : (i += 0);
        } else
            tmp = NULL;
        if (my_strcmp_dot(".name\0", f->file[i]) == 0)
            put_header_node(only_get_name(f->file[i]), l, ".name\0", tmp);
        else if (my_strcmp_dot(".comment\0", f->file[i]) == 0)
            put_header_node(only_get_name(f->file[i]), l, ".comment\0", tmp);
        else
            (is_label(f->file[i]) == 0) ? (put_header_node(get_args(f->file[i])
            , l, get_type(f->file[i]), tmp)) : (is_label(f->file[i]) == 1 &&
            check_file_label(f->file[i]) == 0) ?
            (put_header_node(get_args(f->file[i]), l,
            get_type(f->file[i]), tmp)) : (i += 1);
    }
}