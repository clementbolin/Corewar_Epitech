/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** init_champ
*/

#include "corewar.h"

int open_file_champ(char const *path)
{
    int fd = open(path, O_RDONLY);

    if (fd < 0) {
        putstr_error("ERROR: we can't open file champ file");
        exit(84);
    }
    return (fd);
}

int check_str_cor(char *str)
{
    if (str[my_strlen(str) - 1] == 'r' &&
    str[my_strlen(str) - 2] == 'o' &&
    str[my_strlen(str) - 3] == 'c' &&
    str[my_strlen(str) - 4] == '.')
        return (1);
    return (0);
}

int nb_champ(char **av)
{
    int nb = 0;

    for (int i = 0; av[i]; i++)
        if (check_str_cor(av[i]))
            nb += 1;
    return (nb);
}

champ_t *init_champion(char **av)
{
    int number_champ = nb_champ(av);
    champ_t *champ = malloc(sizeof(champ_t) * number_champ);
    int color = 1;

    for (int i = 0, j = 0; av[i]; i++) {
        if (check_str_cor(av[i]) == 0)
            continue;
        recup_header_champ(&champ[j], av[i]);
        recup_instruction_champ(&champ[j], av[i]);
        init_register_champ(&champ[j], j);
        champ[j].last_pc = 0;
        champ[j].arg = NULL;
        champ[j].basic_pc = 0;
        champ[j].color = color;
        champ[j].cycle = 0;
        champ[j].etat = 0;
        color += 1;
        j += 1;
    }
    return (champ);
}