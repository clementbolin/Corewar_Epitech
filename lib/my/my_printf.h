/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** my_printf
*/

#ifndef MY_PRINTF_H_
#define MY_PRINTF_H_

#include <stdarg.h>
#include <stdio.h>

void my_number(va_list va );
void my_str(va_list va);
void my_char(va_list va);
void my_base(va_list va);
void my_base_hex(va_list va);
void my_unsigned_ten(va_list va);
void my_hex_min(va_list va);
void my_number_0(va_list va, char *str);
void my_oct_0(va_list va, char *str);
void my_hex_min_0(va_list va, char *str);
void my_hex_0(va_list va, char *str);
void my_number_2(va_list va, char c);
void my_str_2(va_list va, char c);
void my_space(char *str, int *size, va_list va);
void bonus(va_list va);
void my_bin(va_list va);
int my_check_argnb(char *str, int i, va_list va);
void my_number_nb(va_list va, char *str);
void my_number_s(va_list va, char *str);
void my_printf(char *str, ...);
void my_check(char c, va_list va);

typedef struct function {
    char c;
    void (*ft)(va_list);
} array_ft;

typedef struct function_arg_0 {
    char c;
    void (*ft_2)(va_list, char *);
}function_0;

typedef struct function_arg {
    char c;
    void (*ft_3)(va_list, char);
}functionar_t;

#endif /* !MY_PRINTF_H_ */
