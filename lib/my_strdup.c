/*
** EPITECH PROJECT, 2022
** strdup
** File description:
** dup str
*/

#include <stdlib.h>
int my_strlen(char const *str);

char *my_strdup(char const *src)
{
    int len = my_strlen(src);
    char *str = malloc(sizeof(char) * (len + 1));

    for (int i = 0; i < len; i++) {
        str[i] = src[i];
    }
    str[len] = '\0';
    return str;
}
