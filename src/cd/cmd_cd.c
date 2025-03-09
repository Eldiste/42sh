/*
** EPITECH PROJECT, 2023
** B-PSU-200-LYN-2-1-minishell1-dorian.senecot
** File description:
** cmd_cd
*/

#include "../../include/my.h"
#include "../../include/mysh.h"

int validinput(char *slash)
{
    int c = 0;
    for (int i = 0; slash[i] != '\0'; i++) {
        if (slash[i] == '.') {
            c++;
            continue;
        }
        if (slash[i] == '/' && c == 2) {
            c = 0;
        } else {
            return 84;
        }
    }
    return 0;
}

void cp_str(struct mysh *cmd)
{
    int i = 0;
    cmd->oldpwd = malloc(sizeof(char *) * my_strlen(cmd->str) + 1);
    for (i; i < my_strlen(cmd->str); i++) {
        cmd->oldpwd[i] += cmd->str[i];
    }
    cmd->oldpwd[i] = '\0';
    cmd->old = 1;
}

int cd_home(struct mysh *cmd, char *input)
{
    envp_recup(cmd, "PWD=");
    cp_str(cmd);
    cmd->envp = old_pwd(cmd, cmd->oldpwd);
    envp_recup(cmd, "HOME=");
    env_update(cmd, cmd->str);
    return 0;
}

int cmd_cd(struct mysh *cmd, char *input)
{
    cmd->st = 0;
    if (my_strcmp(input, "cd") == 0)
        return (cd_home(cmd, input));
    if (my_strcmp(input, "-") == 0) {
        if (cmd->old != 0) {
            my_putstr(cmd->oldpwd);
            my_putstr("\n");
            env_update(cmd, cmd->oldpwd);
            cp_str(cmd);
            cmd->envp = old_pwd(cmd, cmd->oldpwd);
        } else {
            my_putstr("OLDPWD dosen't exist\n");
            cmd->ireturn = 1;
        }
    } else if (validinput(input)) {
        testpath(cmd, input);
    } else {
        testpath(cmd, input);
    }
}
