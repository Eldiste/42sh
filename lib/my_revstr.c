/*
** EPITECH PROJECT, 2022
** my_revstr
** File description:
** d
*/

int my_strlen(char const *str);
char *my_strcpy(char *dest, char const *src);

char *my_revstr(char *str)
{
    int len = my_strlen(str);
    char rev[len];

    my_strcpy(rev, str);
    for (int i = 0; i < len; i++) {
        str[i] = rev[len - i - 1];
    }
    str[len] = '\0';
    return str;
}
