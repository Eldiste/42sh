/*
** EPITECH PROJECT, 2022
** isupper
** File description:
** d
*/

int my_str_isupper(char const *str)
{
    for (int i = 0; i < str[i] != '\0'; i++) {
        if (str[i] < 65 || str[i] > 90) {
            return 0;
        }
    }
    return 1;
}
