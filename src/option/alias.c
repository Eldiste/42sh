/*
** EPITECH PROJECT, 2023
** B-PSU-200-LYN-2-1-42sh-dorian.senecot
** File description:
** alias
*/

#include "../../include/my.h"
#include "../../include/mysh.h"

int print_alias(mysh_t *cmd)
{
    if (!(cmd->alias->replace && cmd->alias->cmd)) {
        return 0;
    } for (int i = 0; (cmd->alias->replace[i] && cmd->alias->cmd[i]); i++) {
        my_putstr(cmd->alias->replace[i]);
        my_putstr(" == ");
        my_putstr(cmd->alias->cmd[i]);
        my_putstr("\n");
    } return 0;
}

char **my_realloc_tab(char **tab, char *var)
{
    int nb_line = lentabin(tab);
    char **tmp = malloc(sizeof(char *) * (nb_line + 2));
    int i = 0;
    while (tab[i]) {
        tmp[i] = my_strdup(tab[i]);
        i++;
    } tmp[i] = my_strdup(var);
    tmp[i + 1] = NULL;
    free_tab(tab);
    return tmp;
}

int add_alias(mysh_t *cmd, char **input)
{
    if (!cmd->alias->replace) {
        cmd->alias->replace = malloc(sizeof(char *));
        cmd->alias->replace[0] = my_strdup(input[2]);
        cmd->alias->cmd = malloc(sizeof(char *));
        cmd->alias->cmd[0] = my_strdup(input[1]);
        return 0;
    } for (int i = 0; cmd->alias->replace[i]; i++) {
        if (my_strcmp(cmd->alias->replace[i], input[2]) == 0) {
            free(cmd->alias->cmd[i]);
            cmd->alias->cmd[i] = my_strdup(input[1]);
            return 0;
        }
    }
    cmd->alias->replace = my_realloc_tab(cmd->alias->replace, input[1]);
    cmd->alias->cmd = my_realloc_tab(cmd->alias->cmd, input[1]);
    return 0;
}

int alias(mysh_t *cmd, char **input)
{
    if (!input[1] || !input[2]) {
        print_alias(cmd);
        return 0;
    } add_alias(cmd, input);
    return 0;
}
