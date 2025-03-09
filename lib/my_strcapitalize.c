/*
** EPITECH PROJECT, 2022
** strcap
** File description:
** d
*/

char *sup_case(char *str)
{
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] >= 65 && str[i] <= 90) {
            str[i] = str[i] + 32;
        }
        i++;
    }
    return (str);
}

char *my_strcapitalize(char *str)
{
    int i = 1;
    str = sup_case(str);
    if (str[i] >= 97 && str[i] <= 122) {
        str[0] -= 32;
    }
    while (str[i] != '\0') {
        if (str[i - 1] > 31 && str[i - 1] < 48 && str[i] > 96
            && str[i] < 123) {
            str[i] -= 32;
        }
        i++;
    }
}
