/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** main
*/

#include "asm.h"

int open_file(char *path)
{
    int fd = open(path, O_RDONLY);

    if (fd < 0) {
        write(2, "ERROR: we can't open file\n", 27);
        return (84);
    }
    return (fd);
}

int read_file(char *path, asm_t *champ)
{
    int fd = open_file(path);
    int a = 0;
    struct stat file;

    if (fd == 84 || stat(path, &file) < 0)
        return (84);
    champ->contents = malloc(sizeof(char) * (file.st_size + 1));
    a = read(fd, champ->contents, file.st_size);
    if (a <= 0) {
        write(2, "ERROR: we can't read file.\n", 27);
        return (84);
    }
    champ->contents[file.st_size] = '\0';
    close(fd);
    return (0);
}

int init_champ2(asm_t *champ)
{
    int tmp = 2;

    for (int i = 0; champ->file[i]; i++) {
        if (my_strcmp_dot(".name\0", champ->file[i]) == 0 ||
        my_strcmp_dot(".comment\0", champ->file[i]) == 0)
            for (int j = 0; champ->file[i][j]; j++) {
                if (champ->file[i][j] == '"')
                    tmp -= 1;
                if (tmp == 0)
                    for (j += 1; champ->file[i][j]; j += 1)
                        if (champ->file[i][j] != ' ' && champ->file[i][j])
                            return (84);
            }
        tmp = 2;
    }
    return (0);
}

int init_champ(char *path, asm_t *champ UNUSED)
{
    int size = 0;
    int tmp = 0;

    if (read_file(path, champ) == 84)
        return (84);
    for (size = 0; path[size]; size += 1);
    if (path[size - 1] != 's' || path[size - 2] != '.')
        return (84);
    champ->file = str_to_array(champ->contents, '\n');
    champ->file = clean_array(champ->file);
    for (int i = 0; champ->file[i]; i++)
        if (my_strcmp_dot(".name\0", champ->file[i]) == 0 ||
        my_strcmp_dot(".comment\0", champ->file[i]) == 0)
            tmp += 1;
    if (tmp != 2)
        return (84);
    return (init_champ2(champ));
}