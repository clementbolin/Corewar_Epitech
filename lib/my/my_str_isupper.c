/*
** EPITECH PROJECT, 2019
** my_str_isupper
** File description:
** lib
*/

int my_str_isupper(char const *str)
{
    int garbage = 1;
    int count = 0;

    while (str[count] != '\0') {
        if ((str[count] < 65) || (str[count] > 90)) {
            garbage = 0;
            break;
        }
        count += 1;
    }
    if (garbage == 0)
        return (0);
    else
        return (1);
}