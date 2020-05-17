/*
** EPITECH PROJECT, 2019
** my_putstr
** File description:
** display string
*/

#include <unistd.h>

void my_putchar(char );

int my_putstr(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
    return (0);
}