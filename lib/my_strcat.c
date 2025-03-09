/*
** EPITECH PROJECT, 2022
** strcat
** File description:
** strcat
*/

#include "../include/my.h"

char *my_strcat(char *dest, char const *src)
{
    char *str = malloc(sizeof(char) * my_strlen(dest) + my_strlen(src) + 1);
    int i = 0;
    int j = 0;
    for (; dest[i] != '\0'; i++) {
        str[i] = dest[i];
    }
    for (; src[j] != '\0'; j++) {
        str[i + j] = src[j];
    }
    str[i + j] = '\0';
    return str;
}
