/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** files for my_flags3
*/

#include "./my.h"
#include "./my_printf.h"
#include <stdlib.h>

void my_hex_0(va_list va, char *str)
{
    int nb = va_arg(va, int);
    int size0 = my_getnbr(str);
    int tmp = nb;
    int icr = 0;

    if (nb < 0)
        nb = nb * -1;
    while (tmp != 0) {
        icr++;
        tmp = tmp / 10;
    }
    while (icr < size0) {
        my_putchar('0');
        icr++;
    }
    my_putnbr_base(nb, "0123456789ABCDEF");
}

void my_number_2(va_list va, char c)
{
    my_putchar('0');
    if (c == 'x')
        my_putchar('x');
    if (c == 'X')
        my_putchar('X');
    my_put_nbr(va_arg(va, int));
}

void my_str_2(va_list va, char c)
{
    my_putchar('0');
    if (c == 'x')
        my_putchar('x');
    if (c == 'X')
        my_putchar('X');
    my_putstr(va_arg(va, char *));
}

void my_bin(va_list va)
{
    my_putnbr_base(va_arg(va, int), "01");
}

void bonus(va_list va)
{
    int c_array = 0;
    char **array = malloc(sizeof(va_arg(va, char ** )) + 1);

    array = va_arg(va, char **);
    for (int i = 0; array[i] != NULL; i++) {
        my_putstr("in case ");
        my_put_nbr(c_array);
        my_putchar('[');
        for (int c = 0; array[i][c] != '\0'; c++)
            my_putchar(array[i][c]);
        my_putchar(']');
        my_putchar(10);
    }
}