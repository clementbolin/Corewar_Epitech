/*
** EPITECH PROJECT, 2019
** put_nbr
** File description:
** nothing special
*/

#include <unistd.h>

void my_putchar(char );

int my_put_nbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
    }
    if (nb >= 10)
        my_put_nbr(nb / 10);

    my_putchar(nb % 10 + '0');

    return (0);
}