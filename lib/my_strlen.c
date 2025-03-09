/*
** EPITECH PROJECT, 2022
** my_strlen
** File description:
** counts and returns the number of characters
*/

int countc(char *str, char c)
{
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c) {
            count++;
        }
    }
    return count;
}

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return i;
}
