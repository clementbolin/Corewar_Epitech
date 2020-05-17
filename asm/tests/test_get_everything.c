/*
** EPITECH PROJECT, 2019
** test_hiden_p
** File description:
** testing my hiden_p
*/

#include "asm.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(test_get_everything, working)
{
    char *tmp = "ld %%0, r3\0";

    cr_assert_str_eq("ld\0", get_type(tmp));
    cr_assert_str_eq("%%0, r3\0", get_args(tmp));
    cr_assert_eq(0, is_label(tmp));
}

Test(test_get_everything, error_1)
{
    char *tmp = "hello: ld %%0, r3\0";

    cr_assert_str_eq("ld\0", get_type(tmp));
    cr_assert_str_eq("%%0, r3\0", get_args(tmp));
    cr_assert_str_eq("hello\0", get_label(tmp));
    cr_assert_eq(1, is_label(tmp));
}

Test(test_get_everything, error_2)
{
    char *tmp = "hello: ld %%0\0";

    cr_assert_str_eq("ld\0", get_type(tmp));
    cr_assert_str_eq("%%0\0", get_args(tmp));
    cr_assert_str_eq("hello\0", get_label(tmp));
    cr_assert_eq(1, is_label(tmp));
}

Test(test_get_everything, error_3)
{
    char *tmp = "ld %%0\0";

    cr_assert_str_eq("ld\0", get_type(tmp));
    cr_assert_str_eq("%%0\0", get_args(tmp));
    cr_assert_eq(0, is_label(tmp));
}