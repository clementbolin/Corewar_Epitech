/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** tool
*/

#include "corewar.h"

char *my_itoa(int nb, char *str)
{
    int rem = 0;
    int i = 0;

    if (nb == 0) {
        str[i++] = '0';
        str[i] = '\0';
        return (str);
    }
    while (nb != 0) {
        rem = nb % 10;
        str[i++] = (rem > 9)? (rem-10) + 'a' : rem + '0';
        nb = nb / 10;
    }
    str[i] = '\0';
    my_revstr(str);
    return (str);
}

char *dec_to_hex(int decimalnum)
{
    long quotient = 0;
    long remainder = 0;
    int i UNUSED = 0;
    int j = 0;
    char *hexadecimalnum = malloc(sizeof(char) * 100);

    quotient = decimalnum;
    while (quotient != 0)
    {
        remainder = quotient % 16;
        if (remainder < 10)
            hexadecimalnum[j++] = 48 + remainder;
        else
            hexadecimalnum[j++] = 55 + remainder;
        quotient = quotient / 16;
    }
    hexadecimalnum = my_revstr(hexadecimalnum);
    return (hexadecimalnum);
}