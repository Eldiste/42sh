/*
** EPITECH PROJECT, 2022
** strcmp
** File description:
** f
*/

#include "../include/my.h"

int my_strcmp(char const *s1, char const *s2)
{
    int len1 = my_strlen(s1);
    int len2 = my_strlen(s2);
    if (len1 != len2) {
        return -1;
    }
    for (int i = 0; i < len1; i++) {
        if (s1[i] != s2[i]) {
            return -1;
        }
    }
    return 0;
}
