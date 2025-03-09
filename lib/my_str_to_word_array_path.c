/*
** EPITECH PROJECT, 2022
** strtoword
** File description:
** strtoword
*/

#include "../include/my.h"

int len_y_d(const char *str)
{
    int i = 0;
    while (str[0] != ':' && str[0] != '\0') {
        i++;
        str++;
    }
    return i;
}

int lentab_d(char const *str)
{
    int i = 0, count = 1;
    for (i; str[i] != '\0'; i++) {
        if (str[i] == ':') {
            count++;
        }
    }
    return count;
}

char **my_str_to_word_array_path(char *str)
{
    int x = 0;
    int y = 0;
    int len = lentab_d(str);
    char **tab = malloc(sizeof(char *) * (len + 1));
    while (x < len) {
        int lentmp = len_y_d(str);
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
