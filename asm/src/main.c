/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** main
*/

#include "asm.h"

void delete_champ(asm_t *champ, link_t *link)
{
    for (int i = 0; champ->file[i]; i++)
        free(champ->file[i]);
    free(champ->name);
    destroy_link(link);
}

int main_asm(int ac UNUSED, char **av, asm_t *champ, link_t *link)
{
    int error = 0;

    for (int i = 1; i < ac; i += 1) {
        champ = malloc(sizeof(asm_t));
        link = malloc(sizeof(link_t));
        if (!champ || !link)
            return (84);
        if (main_init(av[i], champ, link) == 84) {
            error = 84;
            continue;
        }
        consolog(1);
        champ->name = cpy_name_file(av[i]);
        name_file_cor(champ->name);
        champ->name = my_strcat(champ->name, ".cor");
        champ->fd = create_file(champ->name);
        consolog(2);
        write_header(champ, link);
        consolog(3);
        write_binary(champ, link);
        consolog(4);
    }
    return (error);
}

int main(int ac, char **av)
{
    asm_t champ;
    link_t *link = NULL;
    if (ac < 2)
        return (84);
    return (main_asm(ac, av, &champ, link));
}