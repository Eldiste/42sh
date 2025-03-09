/*
** EPITECH PROJECT, 2022
** isprintable
** File description:
** d
*/

int my_str_isprintable(char const *str)
{
    for (int i = 0; i < str[i] != '\0'; i++) {
        if (str[i] < 32 || str[i] > 127) {
            return 0;
        }
    }
    return 1;
}
