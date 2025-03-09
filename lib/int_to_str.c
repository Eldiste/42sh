/*
** EPITECH PROJECT, 2023
** B-MUL-100-LYN-1-1-myradar-dorian.senecot
** File description:
** int_to_str
*/

#include "../include/my.h"

int intlen(int nb)
{
    int len = 1;

    if (nb == 0)
        return len;
    while (nb != 0) {
        len++;
        nb /= 10;
    }
    return len;
}

char *my_int_to_strnum(int nb)
{
    char *strnum = malloc(sizeof(char) * (intlen(nb) + 2));
    int i = 0;
    if (nb == 0) {
        return ("0");
    }
    while (nb != 0) {
        strnum[i++] = nb % 10 + '0';
        nb = nb / 10;
    }
    strnum[i] = '\0';
    return (my_revstr(strnum));
}
