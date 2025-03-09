/*
** EPITECH PROJECT, 2023
** B-PSU-200-LYN-2-1-minishell1-dorian.senecot
** File description:
** cmd_unsetenv
*/

#include "../../include/my.h"
#include "../../include/mysh.h"

int getlinevar_addon(struct mysh *cmd, char *info, int *c, int i)
{
    for (int y = 0; cmd->envp[i][y] != '\0'; y++) {
        if (my_strncmp(cmd->envp[i], info, my_strlen(info)) == 0) {
            cmd->linevar = i;
        }
    }
}

int getlinevar(struct mysh *cmd, char *info)
{
    int c = 0;
    cmd->linevar = -1;
    for (int i = 0; cmd->envp[i] != NULL; i++) {
        c = 0;
        getlinevar_addon(cmd, info, &c, i);
    }
}

char **cmd_unenv(struct mysh *cmd, char *var)
{
    char **envp;
    cmd->ireturn = 0;
    getlinevar(cmd, var);
    if (cmd->linevar == -1) {
        return cmd->envp;
    }
    envp = remove_str_from_tab_int(cmd->envp, cmd->linevar);
    return envp;
}
