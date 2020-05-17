/*
** EPITECH PROJECT, 2019
** my
** File description:
** my_putnbr_base.c
*/

#include <unistd.h>
#include <stdlib.h>

char *my_revstr(char *str);

int my_putstr(char *str);

void my_putchar(char );

int my_strlen(char const *str);

char *my_putnbr_base(int nbr, char *base)
{
    int count = 0;
    char *str = malloc(sizeof(str) * 20);
    int i = 0;

    if (nbr < 0)
        nbr *= -1;
    for (; nbr > 0; i += 1) {
        count = nbr % my_strlen(base);
        str[i] = base[count];
        nbr /= my_strlen(base);
    }
    str[i] = '\0';
    my_revstr(str);
    return (str);
}