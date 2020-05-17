/*
** EPITECH PROJECT, 2019
** my_revstr
** File description:
** rev str
*/

char *my_revstr(char *str)
{
    int i = 0;
    int j = 0;
    char c = '\0';

    while (str[j] != '\0')
        j++;
    j--;

    while (i <= j) {
        c = str[i];
        str[i] = str[j];
        str[j] = c;
        i++;
        j--;
    }
    return (str);
}
