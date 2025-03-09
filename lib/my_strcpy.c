/*
** EPITECH PROJECT, 2022
** strcpy
** File description:
** d
*/

int my_strlen(char const *str);

char *my_strcpy(char *dest, char const *src)
{
    int len = my_strlen(src);

    for (int i = 0; i < len; i++) {
        dest[i] = src[i];
    }
    dest[len] = '\0';
    return dest;
}
