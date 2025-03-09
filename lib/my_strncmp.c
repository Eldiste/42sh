/*
** EPITECH PROJECT, 2022
** strncmp
** File description:
** f
*/

int my_strlen(char const *str);
char *my_strncpy(char *dest, char const *src, int n);
int my_strcmp(char const *s1, char const *s2);

int my_strncmp(char const *s1, char const *s2, int n)
{
    int len1 = my_strlen(s1);
    int len2 = my_strlen(s2);
    char var1[len1];
    char var2[len2];
    my_strncpy(var1, s1, n);
    my_strncpy(var2, s2, n);
    return my_strcmp(var1, var2);
}
