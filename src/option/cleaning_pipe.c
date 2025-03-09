/*
** EPITECH PROJECT, 2023
** cleaning_pipe
** File description:
** cleaning_pipe
*/

#include "../../include/my.h"
#include "../../include/mysh.h"

char *retake_string(char **tab, int j, int x, int *size)
{
    char *cpy = malloc(sizeof(char) * my_strlen(tab[j] + 1));
    int c = 0;
    for (int b = x + 1; tab[j][b] != '\0'; b++) {
        cpy[c] = tab[j][b];
        c++;
    } *size = 3;
    return cpy;
}

char **change_tab(char **tab, int len, int j, int x)
{
    char **cpy_tab = malloc(sizeof(char *) * (len + 3));
    int i, size = 0;
    cpy_tab = start_change_tab(&i, j, tab, cpy_tab);
    if (x != 0 && tab[j][x + 1] != '\0') {
        cpy_tab[j] = malloc(sizeof(char) + (my_strlen(tab[j]) + 1));
        cpy_tab[j] = my_strncpy(cpy_tab[j], tab[j], x);
        cpy_tab[j + 1] = malloc(sizeof(char) + (my_strlen(tab[j]) + 1));
        cpy_tab[j + 1] = "|";
        cpy_tab[j + 2] = malloc(sizeof(char) + (my_strlen(tab[j]) + 1));
        cpy_tab[j + 2] = retake_string(tab, j, x, &size);
        len++;
    } if (x != 0 && tab[j][x + 1] == '\0') {
        cpy_tab[j] = malloc(sizeof(char) + (my_strlen(tab[j]) + 1));
        cpy_tab[j] = my_strncpy(cpy_tab[j], tab[j], x);
        cpy_tab[j + 1] = malloc(sizeof(char) + (my_strlen(tab[j]) + 1));
        cpy_tab[j + 1] = "|"; size = 2;
    } for (i = j + size; i <= len; i++, j++) {
        cpy_tab[i] = malloc(sizeof(char) * (my_strlen(tab[j + 1]) + 1));
        cpy_tab[i] = tab[j + 1];
    } return cpy_tab;
}

char **change_tab_2(char **tab, int len, int j, int x)
{
    char **cpy_tab = malloc(sizeof(char *) * (len + 3));
    int i, size = 0;
    cpy_tab = start_change_tab(&i, j, tab, cpy_tab);
    if (tab[j][x + 1] != '\0') {
        cpy_tab[j] = malloc(sizeof(char) + (my_strlen(tab[j]) + 1));
        cpy_tab[j] = "|";
        cpy_tab[j + 1] = malloc(sizeof(char) + (my_strlen(tab[j]) + 1));
        char *cpy = malloc(sizeof(char) * my_strlen(tab[j] + 1));
        int c = 0;
        for (int b = 1; tab[j][b] != '\0'; b++) {
            cpy[c] = tab[j][b];
            c++;
        } cpy_tab[j + 1] = cpy;
        size = 2;
    } for (i = j + size; i <= len; i++) {
        cpy_tab[i] = malloc(sizeof(char) * (my_strlen(tab[j + 1]) + 1));
        cpy_tab[i] = tab[j + 1];
        j++;
    } return cpy_tab;
}

char **error_pipe(struct mysh *cmd, char **input, int j, int *x)
{
    if (input[j][*x - 1] == '|' && input[j][*x] == '|') {
        (*x)++;
    } if (input[j][*x] == '|' && *x != 0 && input[j][*x + 1] != '|') {
        int len = 0;
        for (; input[len] != NULL; len++);
        input = change_tab(input, len, j, *x);
    } if (input[j][*x] == '|' && *x == 0
    && input[j][*x + 1] != '|' && input[j][*x + 1] != '\0') {
        int len = 0;
        for (; input[len] != NULL; len++);
        input = change_tab_2(input, len, j, *x);
    } return input;
}

char **change_pipe(struct mysh *cmd, char **input)
{
    cmd->pipe = 0;
    for (int j = 0; input[j]; j++) {
        for (int x = 0; input[j][x] != '\0'; x++) {
            input = error_pipe(cmd, input, j, &x);
        }
    } return input;
}
