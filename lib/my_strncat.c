/*
** EPITECH PROJECT, 2022
** strncat
** File description:
** strncat
*/

int my_strlen(char const *str);

char *my_strncat(char *dest, char const *src, int nb)
{
    int len1 = my_strlen(dest);
    int len2 = my_strlen(src);

    for (int i = 0; i < len2 && i < nb; i++) {
        dest[len1 + i] = src[i];
    }
    dest[len1 + len2] = '\0';
    return dest;
}
