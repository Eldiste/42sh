/*
** EPITECH PROJECT, 2023
** B-PSU-200-LYN-2-1-42sh-dorian.senecot
** File description:
** alias_addon
*/

#include "../../include/my.h"
#include "../../include/mysh.h"

int alias_replace_addon(mysh_t *cmd, int i, int y, int x)
{
    if (my_strcmp(cmd->parsing[i][y], cmd->alias->replace[x]) == 0) {
        free(cmd->parsing[i][y]);
        cmd->parsing[i][y] = my_strdup(cmd->alias->cmd[x]);
    }
}

int alias_replace(mysh_t *cmd, int i)
{
    for (int y = 0; cmd->parsing[i][y] != NULL; y++) {
        for (int x = 0; cmd->alias->replace[x] != NULL; x++) {
            alias_replace_addon(cmd, i, y, x);
        }
    } return 0;
}

void alias_search(mysh_t *cmd, int i)
{
    if (cmd->alias->replace)
        alias_replace(cmd, i);
}
