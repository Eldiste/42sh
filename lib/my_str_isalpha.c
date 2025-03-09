/*
** EPITECH PROJECT, 2022
** my_str_isalpha
** File description:
** alpha
*/

int my_str_isalpha(char const *str, char c)
{
    for (int i = 0; i < str[i] != '\0'; i++) {
        if ((c < 97 || c > 122) && (c < 65 || c > 90)) {
            return 0;
        }
    }
    return 1;
}
