/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** flags2
*/

#include "./my.h"
#include "./my_printf.h"

void my_unsigned_ten(va_list va)
{
    int nb = va_arg(va, int);
    if (nb < 0)
        nb = nb * -1;
    my_put_nbr(nb);
}

void my_hex_min(va_list va)
{
    int nb = va_arg(va, int);
    if (nb < 0)
        nb = nb * -1;
    my_putnbr_base(nb, "0123456789abcdef");
}

void my_number_0(va_list va, char *str)
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
    my_put_nbr(nb);
}

void my_oct_0(va_list va, char *str)
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
    my_putnbr_base(nb, "01234567");
}

void my_hex_min_0(va_list va, char *str)
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
    my_putnbr_base(nb, "0123456789abcdef");
}