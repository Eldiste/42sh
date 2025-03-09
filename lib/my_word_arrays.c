/*
** EPITECH PROJECT, 2022
** strtoword
** File description:
** strtoword
*/

#include "../include/my.h"

int len_ys(const char *str, char separation)
{
    int i = 0;
    if (separation == ':') {
        while (str[0] != ':' && str[0] != '\0') {
            i++;
            str++;
        }
    } else {
        while (str[0] != ' ' && str[0] != '\0' && str[0] != '\t') {
            i++;
            str++;
        }
    } return i;
}

int lentabs(char const *str)
{
    int i = 0, count = 1;
    for (i; str[i] != '\0'; i++) {
        if (str[i] == ' ' || str[i] == 9) {
            count++;
        }
    }
    return count;
}

char **my_str_to_word_arrays(char *str, char separation)
{
    int x = 0;
    int y = 0;
    int len = lentabs(str);
    char **tab = malloc(sizeof(char *) * (len + 1));
    while (x < len) {
        int lentmp = len_ys(str, separation);
        if ((tab[x] = malloc(sizeof(char) * (lentmp + 1))) == NULL)
            exit(0);
        y = 0;
        while (y < lentmp)
            tab[x][y++] = *str++;
        tab[x][y] = '\0';
        str++;
        x++;
    } tab[x] = NULL;
    return tab;
}
