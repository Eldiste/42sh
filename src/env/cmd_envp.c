/*
** EPITECH PROJECT, 2023
** B-PSU-200-LYN-2-1-minishell1-dorian.senecot
** File description:
** cmd_envp
*/

#include "../../include/my.h"
#include "../../include/mysh.h"

void old_pwd_addon2(struct mysh *cmd, char *tmp, char **envp)
{
    char *envp2 = malloc(sizeof(char *) * my_strlen(tmp) + 7);
    envp2[0] = 'O', envp2[1] = 'L', envp2[2] = 'D', envp2[3] = 'P',
    envp2[4] = 'W', envp2[5] = 'D', envp2[6] = '=';
    int x = 7;
    for (int i = 0; i < my_strlen(tmp); i++, x++) {
        envp2[x] += tmp[i];
    }
    envp2[x] = '\0';
    envp[cmd->oldplace] = envp2;
}

void old_pwd_addon(struct mysh *cmd, char *tmp, char **envp, int y)
{
    cmd->tmp = 1;
    cmd->oldplace = y;
    envp[y] = malloc(sizeof(char *) * my_strlen(tmp) + 7);
    envp[y][0] = 'O', envp[y][1] = 'L', envp[y][2] = 'D', envp[y][3] = 'P',
    envp[y][4] = 'W', envp[y][5] = 'D', envp[y][6] = '=';
    int x = 7;
    for (int i = 0; i < my_strlen(tmp); i++, x++) {
        envp[y][x] += tmp[i];
    }
}

char **old_pwd(struct mysh *cmd, char *tmp)
{
    int i = 0, y = 0;
    char **envp;
    for (i; cmd->envp[i] != NULL; i++);
    envp = malloc(sizeof(char *) * i + 1);
    for (y = 0; y != i; y++) {
        envp[y] = malloc(sizeof(char) * my_strlen(cmd->envp[y]));
        for (int x = 0; cmd->envp[y][x] != '\0'; x++)
            envp[y][x] = cmd->envp[y][x];
    }
    if (cmd->tmp == 0) {
        old_pwd_addon(cmd, tmp, envp, y);
    } else {
        old_pwd_addon2(cmd, tmp, envp);
    }
    envp[y] = NULL;
    return envp;
}

int cmd_envp(struct mysh *cmd)
{
    cmd->ireturn = 0;
    for (int i = 0; cmd->envp[i] != NULL; i++) {
        my_putstr(cmd->envp[i]);
        my_putstr("\n");
    }
}
