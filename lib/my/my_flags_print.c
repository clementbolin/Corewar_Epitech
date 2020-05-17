/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** flags my_printf
*/

#include "my.h"
#include "my_printf.h"

void my_number(va_list va)
{
    my_put_nbr(va_arg(va, int));
}

void my_str(va_list va)
{
    my_putstr(va_arg(va, char *));
}

void my_char(va_list va)
{
    my_putchar(va_arg(va, int));
}

void my_base(va_list va)
{
    int nb = va_arg(va, int);
    if (nb < 0)
        nb = nb * -1;
    my_putnbr_base(nb, "01234567");
}

void my_base_hex(va_list va)
{
    int nb = va_arg(va, int);
    if (nb < 0)
        nb = nb * -1;
    my_putnbr_base(nb, "0123456789ABCDEF");
}