/*
** EPITECH PROJECT, 2022
** my_getnbr
** File description:
** returns a number
*/

#include <stdbool.h>
#include <stdio.h>

int sign(char const *str, int i)
{
    int s = 1;

    for (; str[i] == '+' || str[i] == '-'; i++) {
        if (str[i] == '-') {
            s *= -1;
        }
    }
    return s;
}

int my_getnbr(char const *str, char **line)
{
    int i = 0;
    int s = sign(str, i);
    int nb = 0;
    while (str[i] == ' ')
        i++;
    if (str[i] > '9' || str[i] < '0')
        return 0;
    nb += str[i++] - '0';
    for (i; str[i] <= '9' && str[i] >= '0'; i++) {
        nb *= 10;
        nb += str[i] - '0';
    }
    nb *= s;
    return nb;
}
