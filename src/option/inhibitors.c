/*
** EPITECH PROJECT, 2023
** inhibitors
** File description:
** inhibitors
*/

#include "../../include/my.h"
#include "../../include/mysh.h"

void clean_inhibitors(char *input, int size)
{
    int i = 0, b = 0;
    while (input[i] != '\0') {
        if (input[i] != 92) {
            input[b] = input[i];
            b++;
        } else {
            size++;
        } if (size == 2) {
            input[b] = ' ';
            input[b + 1] = '\0';
            return;
        } i++;
    } input[b] = ' ';
    input[b + 1] = '\0';
}

int browse_input(char *input, int *i)
{
    while (input[*i] != '\0') {
        if (input[*i] == 92) {
            return 1;
        } (*i)++;
    } return 0;
}

char *inhibitors(char *input, int i)
{
    i++;
    while (input[i] != '\0') {
        if (input[i] != ' ' && input[i] != '\n' && input[i] != '\0') {
            clean_inhibitors(input, 0);
            return input;
        } i++;
    }
    clean_inhibitors(input, 1);
    my_putstr("? ");
    size_t size = 0;
    char *my_input = 0;
    getline(&my_input, &size, stdin);
    my_input[size] = '\0';
    input = my_strcat(input, my_input);
    i = 0;
    if (browse_input(input, &i)) {
        input = inhibitors(input, i);
    }
    return input;
}
