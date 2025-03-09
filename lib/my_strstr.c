/*
** EPITECH PROJECT, 2022
** strstr
** File description:
** c
*/

int addon(void);
int my_strncmp(char const *s1, char const *s2, int n);

char *my_strstr(char *str, char const *to_find)
{
    int i = 0;
    while (to_find[i]) {
        i++;
    }
    if (i == 0) {
        return str;
    }
    while (*str && my_strncmp(str, to_find, i)) {
        *str++;
    }
    if (*str) {
        return str;
    }
    return 0;
}
