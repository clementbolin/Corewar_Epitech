/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** bin_to_hexa
*/

#include "asm.h"

long long char_to_long_long(char *str)
{
    long long nb = 0;

    for (int i = 0; str[i]; i += 1) {
        nb *= 10;
        nb += str[i] - '0';
    }
    return (nb);
}

char *binary_to_hex(char *str)
{
    int hexConstant[] = {0, 1, 10, 11, 100, 101, 110, 111, 1000,
    1001, 1010, 1011, 1100, 1101, 1110, 1111};
    long long binary = char_to_long_long(str);
    char *hex = malloc(sizeof(char) * 20);
    int index = 0;

    for (long long tempBinary = binary; tempBinary != 0; tempBinary /= 10000)
        for (int i = 0; i < 16; i++)
            if (hexConstant[i] == tempBinary % 10000) {
                (i<10) ? (hex[index] = (char)(i + 48)) :
                (hex[index] = (char)(i - 10 + 65));
                index++;
                break;
            }
    hex[index] = '\0';
    my_revstr(hex);
    return (hex);
}