/*
** EPITECH PROJECT, 2023
** B-PSU-200-LYN-2-1-minishell2-dorian.senecot
** File description:
** red_out
*/

#include "../../include/my.h"
#include "../../include/mysh.h"

void check_redirection(struct mysh *cmd, char **input, int i)
{
    if (input[i][0] == '>' || input[i][0] == '<') {
        my_putstr("Missing name for redirect.\n");
        cmd->ireturn = 1;
    }
}

char **remove_str_from_tab_int(char **tab, int c)
{
    int i = 0;
    int j = 0;
    for (; tab[j] != NULL; j++);
    if (j <= c || tab[c] == NULL)
        return tab;
    else
        free(tab[c]);
    for (int k = c; k < j; k++)
        tab[k] = tab[k + 1];
    tab[j - 1] = NULL;
    return tab;
}

char **remove_str_from_tab(char **tab, char *c)
{
    int i = 0;
    int j = 0;
    for (; tab[i] != NULL; i++) {
        if (my_strcmp(tab[i], c) == 0)
            break;
    }
    for (; tab[j] != NULL; j++);
    if (j <= i || tab[i] == NULL)
        return tab;
    else
        free(tab[i]);
    for (int k = i; k < j; k++)
        tab[k] = tab[k + 1];
    tab[j - 1] = NULL;
    return tab;
}

int red_out_plus(struct mysh *cmd, char *file, char **input, char *new_line)
{
    int fd = 0;
    int keep_fd = dup(STDOUT_FILENO);
    char **tmp;
    if (!file)
        return 0;
    if ((fd = open(file, O_CREAT | O_RDWR | O_APPEND, 00664)) == -1)
        return 1;
    tmp = remove_str_from_tab(input, ">>");
    tmp = remove_str_from_tab(input, file);
    if (dup2(fd, STDOUT_FILENO) == -1) {
        return 0;
    } cmd_manage(cmd, tmp, new_line);
    close(fd);
    if (dup2(keep_fd, STDOUT_FILENO) == -1) {
        return 0;
    } close(keep_fd);
    return 0;
}

int red_out(struct mysh *cmd, char *file, char **input, char *new_line)
{
    int fd = 0;
    int keep_fd = dup(STDOUT_FILENO);
    char **tmp;
    if (!file)
        return 0;
    if ((fd = open(file, O_CREAT | O_RDWR | O_TRUNC, 00664)) == -1)
        return 1;
    tmp = remove_str_from_tab(input, ">");
    tmp = remove_str_from_tab(input, file);
    if (dup2(fd, STDOUT_FILENO) == -1) {
        return 0;
    } cmd_manage(cmd, tmp, new_line);
    close(fd);
    if (dup2(keep_fd, STDOUT_FILENO) == -1) {
        return 0;
    } close(keep_fd);
    return 0;
}
