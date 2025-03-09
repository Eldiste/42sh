/*
** EPITECH PROJECT, 2022
** is_lower
** File description:
** d
*/

int my_str_islower(char const *str)
{
    for (int i = 0; i < str[i] != '\0'; i++) {
        if (str[i] < 97 || str[i] > 122) {
            return 0;
        }
    }
    return 1;
}
