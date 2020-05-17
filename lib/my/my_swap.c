/*
** EPITECH PROJECT, 2019
** my_swap
** File description:
** swap variable
*/

void my_swap(int *a, int *b)
{
    int tmp = 0;

    tmp = *a;
    *a = *b;
    *b =  tmp;
}
