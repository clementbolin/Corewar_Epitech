/*
** EPITECH PROJECT, 2019
** putstr_error
** File description:
** putstr_error
*/

#include <unistd.h>

void my_putchar_error(char c)
{
    write(2, &c, 1);
}

void putstr_error(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar_error(str[i]);
        i++;
    }
}