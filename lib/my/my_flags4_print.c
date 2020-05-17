/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** files flags 4
*/

#include "./my.h"
#include "./my_printf.h"
#include <stdio.h>

void my_number_nb(va_list va, char *str)
{
    int nb = va_arg(va, int);
    int size0 = my_getnbr(str);
    int tmp = nb;
    int icr = 0;

    while (tmp != 0) {
        icr++;
        tmp = tmp / 10;
    }
    while (icr < size0) {
        my_putchar(' ');
        icr++;
    }
    my_put_nbr(nb);
}

void my_number_s(va_list va, char *str)
{
    char *str2 = va_arg(va, char *);
    int nb = my_strlen(str2);
    int size0 = my_getnbr(str);

    while (nb < size0) {
        my_putchar(' ');
        nb++;
    }
    my_putstr(str2);
}