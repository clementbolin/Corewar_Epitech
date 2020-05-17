/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** my_printf
*/

#include "./my.h"
#include "./my_printf.h"
#include <stdio.h>
#include <stdlib.h>

static array_ft function_ar[] = {
        {'d', my_number},
        {'s', my_str},
        {'i', my_number},
        {'c', my_char},
        {'o', my_base},
        {'x', my_hex_min},
        {'X', my_base_hex},
        {'u', my_unsigned_ten},
        {'b', my_bin},
};

static function_0 array_function_0[] = {
    {'d', my_number_0},
    {'i', my_number_0},
    {'o', my_oct_0},
    {'x', my_hex_min_0},
    {'X', my_hex_0},
};

static functionar_t arrayflag2_ft[] = {
    {'d', my_number_2},
    {'s', my_str_2},
};

static function_0 array_nb_ft[] = {
    {'d', my_number_nb},
    {'s', my_number_s},
};

void my_check(char c, va_list va)
{
    for (int i = 0; i < 10; i++) {
        if (c == function_ar[i].c)
            function_ar[i].ft(va);
    }

}

int my_check_arg0(char *str, int i, va_list va)
{
    int k = 0;
    char *recup = malloc(sizeof(char) * my_strlen(str) + 1);

    i += 2;
    for (int l = 0; str[i] >= '0' && str[i] <= '9'; l++) {
        recup[l] = str[i];
        i++;
        k++;
    }
    for (int r = 0; r < 5; r++) {
        if (str[i] == array_function_0[r].c)
            array_function_0[r].ft_2(va, recup);
    }
    return (k);
}

int my_check_arg2(char *str, int i, va_list va)
{
    i += 4;
    for (int r = 0; r < 2; r++) {
        if (str[i] == arrayflag2_ft[r].c)
            arrayflag2_ft[r].ft_3(va, str[i - 1]);
    }
    return (4);
}

int my_check_argnb(char *str, int i, va_list va)
{
    int k = 0;
    char *recup = malloc(sizeof(char) * my_strlen(str) + 1);

    i += 1;
    for (int l = 0; str[i] >= '0' && str[i] <= '9'; l++) {
        recup[l] = str[i];
        i++;
        k++;
    }
    for (int r = 0; r < 2; r++) {
        if (str[i] == array_nb_ft[r].c)
            array_nb_ft[r].ft_2(va, recup);
    }
    return (k + 1);
}

void my_printf(char *str, ...)
{
    va_list va;
    int size_nb = 0;

    va_start(va, str);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '%' && str[i + 1] == '%')
            my_putchar('%');
        if (str[i] != '%')
            my_putchar(str[i]);
        if (str[i] == '%' && str[i + 1] >= '1' && str[i + 1] <= '9') {
            size_nb = my_check_argnb(str, i, va);
            i += size_nb;
        }
        if (str[i] == '%' && str[i + 1] != '0' && str[i + 1] != '#') {
            my_check(str[i + 1], va);
            i++;
        }
    }
}