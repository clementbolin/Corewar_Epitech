/*
** EPITECH PROJECT, 2019
** my_strncat
** File description:
** lib
*/

char *my_strncat(char *dest, char const *src, int nb)
{
    int i = 0;
    int size = 0;

    for (; dest[size] != '\0'; size++);

    while (src[i] != src[nb]) {
        dest[size + i] = src[i];
        i++;
    }
    dest[size + i] = '\0';
    return (dest);
}