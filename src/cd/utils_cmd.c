/*
** EPITECH PROJECT, 2023
** B-PSU-200-LYN-2-1-minishell1-dorian.senecot
** File description:
** utils_cmd
*/

#include "../../include/my.h"
#include "../../include/mysh.h"

void erno_error(char **input)
{
    switch (errno) {
        case ENOEXEC:
            my_putstr(input[0]);
            my_putstr(": Exec format error. Wrong Architecture.\n");
            exit(1);
            break;
        default:
            exit(0);
            break;
    }
}

void getpwd(struct mysh *cmd, char *input)
{
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        cmd->str = cwd;
    }
}

void testpath(struct mysh *cmd, char *input)
{
    if (chdir(input) < 0) {
        cmd->ireturn = 1;
        my_putstr(input);
        my_putstr(": Not a directory.\n");
    } else {
        cmd->st = 1;
        envp_recup(cmd, "PWD=");
        cp_str(cmd);
        cmd->envp = old_pwd(cmd, cmd->oldpwd);
        getpwd(cmd, input);
        env_update(cmd, cmd->str);
    }
}
