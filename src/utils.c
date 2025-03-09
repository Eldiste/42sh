/*
** EPITECH PROJECT, 2023
** B-PSU-200-LYN-2-1-minishell1-dorian.senecot
** File description:
** utils
*/

#include "../include/my.h"
#include "../include/mysh.h"

int print_envp(struct mysh *cmd, char *info, int i)
{
    if (my_strlen(info) == cmd->count) {
        cmd->str = malloc(sizeof(char) * my_strlen(cmd->envp[i]));
        cmd->str = cmd->envp[i];
        for (int i = 0; i < my_strlen(info); i++, *cmd->str++);
        cmd->status = 1;
    }
}

int envp_recup_adon(struct mysh *cmd, char *info, int i)
{
    if (cmd->status == 1)
        return 0;
    for (int y = 0; cmd->envp[i][y] != '\0'; y++) {
        if (my_strncmp(info, cmd->envp[i], 4) == 0) {
            cmd->count++;
            print_envp(cmd, info, i);
        }
    }
}

int envp_recup(struct mysh *cmd, char *info)
{
    cmd->str = my_strdup(info);
    cmd->count = 0;
    cmd->status = 0;
    if (cmd->status == 1)
        return 0;
    for (int i = 0; cmd->envp[i] != NULL; i++) {
        cmd->count = 0;
        envp_recup_adon(cmd, info, i);
    }
}

int tmp_envp(struct mysh *cmd, char **envp)
{
    int i = 0;
    for (; envp[i]; i++);
    cmd->lenenv = i;
    return 0;
}

void env_update(struct mysh *cmd, char *tmp)
{
    if (chdir(tmp) < 0 && cmd->st == 0) {
        my_putstr(tmp);
        my_putstr(": Not a directory.\n");
        return;
    }
    char *newpwd = malloc(sizeof(char *) * my_strlen(tmp) + 4);
    newpwd[0] = 'P', newpwd[1] = 'W', newpwd[2] = 'D', newpwd[3] = '=';
    int y = 4;
    for (int i = 0; i < my_strlen(tmp); i++, y++) {
        newpwd[y] += tmp[i];
    }
    newpwd[y] = '\0';
    cmd->envp[getlinevar(cmd, "PWD=")] = newpwd;
}
