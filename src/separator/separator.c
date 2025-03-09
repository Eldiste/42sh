/*
** EPITECH PROJECT, 2023
** separator
** File description:
** separator
*/

#include "../../include/my.h"
#include "../../include/mysh.h"

char **tabcop(char **tab)
{
    int i = 0;
    char **tmp = NULL;
    for (; tab[i]; i++);
    tmp = malloc(sizeof(char *) * (i + 1));
    int y = 0;
    for (y = 0; y < i; y++) {
        tmp[y] = my_strdup(tab[y]);
    } tmp[y + 1] = NULL;
    return tmp;
}

void test_door(struct mysh *cmd, int status, int *door, int *dot)
{
    if (status >= cmd->statu && cmd->door == 0 && *dot == 0) {
        *door = 1;
        *dot = 1;
    }
}

char **change_parsing(struct mysh *cmd, char **input)
{
    int i = 0, j = 0, status = 0, b = 0, dot = 0;
    cmd->and_door = 0; cmd->or_door = 0; cmd->door = 0;
    while (cmd->cpy_tab[i] != NULL) {
        if (cmd->cpy_tab[i][0] == '&' && cmd->cpy_tab[i][1] == '&'
        && cmd->cpy_tab[i][2] == '\0') {
            status++;
            test_door(cmd, status, &cmd->and_door, &dot);
            i++;
        } if (cmd->cpy_tab[i][0] == '|' && cmd->cpy_tab[i][1] == '|'
        && cmd->cpy_tab[i][2] == '\0') {
            status++;
            test_door(cmd, status, &cmd->or_door, &dot);
            i++;
        } if (status == cmd->statu && cmd->separator >= 0) {
            input[b] = cmd->cpy_tab[i];
            b++;
        } i++;
    } input[b] = NULL;
    cmd->statu++;
    return input;
}

void separator(struct mysh *cmd, char **input)
{
    int i = 0, j = 0;
    cmd->separator = 0;
    cmd->is_separator = 0;
    cmd->statu = 0;
    while (input[i] != NULL) {
        if (input[i][0] == '&' && input[i][1] == '&' && input[i][2] == '\0') {
            cmd->separator++;
        } if (input[i][0] == '|' && input[i][1] == '|' && input[i][2] == '\0') {
            cmd->separator++;
        } i++;
    } if (cmd->separator > 0) {
        cmd->cpy_tab = tabcop(input);
        cmd->is_separator = 1;
    }
}

void separator_loop(struct mysh *cmd, int i)
{
    while (cmd->separator >= 0) {
        if (cmd->is_separator == 1)
            cmd->parsing[i] = change_parsing(cmd, cmd->parsing[i]);
        cmd->separator--;
        if (cmd->ireturn != 0 && cmd->and_door == 1 && cmd->or_door == 0)
            cmd->result = 1;
        if (cmd->ireturn == 0 && cmd->or_door == 1 && cmd->and_door == 0)
            cmd->result = 1;
        if (cmd->result == 0 || cmd->start == 1) {
            alias_search(cmd, i);
            backticks(cmd, cmd->parsing[i]);
            cmd_manage(cmd, cmd->parsing[i], cmd->tab_line[i]);
        } cmd->result = 0;
        if (cmd->is_separator == 1)
            cmd->parsing[i] = tabcop(cmd->cpy_tab);
        cmd->start = 0;
    }
}
