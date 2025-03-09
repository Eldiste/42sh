/*
** EPITECH PROJECT, 2022
** strncpy
** File description:
** d
*/

int my_strlen(char const *str);

char *my_strncpy(char *dest, char const *src, int n)
{
    int len = my_strlen(src);

    for (int i = 0; i < n; i++) {
        dest[i] = src[i];
    }
    if (n > len) {
        dest[len] = '\0';
    }
    dest[n] = '\0';
    return dest;
}
