/*
** EPITECH PROJECT, 2023
** B-PSU-200-LYN-2-1-minishell1-dorian.senecot
** File description:
** exec_manage
*/

#include "../include/my.h"
#include "../include/mysh.h"

void errorexec(struct mysh *cmd, int tmp)
{
    int sig = WTERMSIG(tmp);
    cmd->ireturn = WEXITSTATUS(tmp);
    if (!WIFSIGNALED(tmp))
        return;
    if (sig == SIGSEGV)
        my_putstr("Segmentation fault");
    if (sig == SIGFPE)
        my_putstr("Floating exception");
    my_putstr("\n");
}

int errorhandling(struct mysh *cmd, char **input)
{
    DIR *tmp = NULL;
    getlinevar(cmd, "PATH=");
    if (cmd->linevar == -1)
        return -1;
    if (input[0] == NULL)
        return -1;
    if ((tmp = opendir(input[0])) != NULL) {
        my_putstr(input[0]);
        my_putstr(": Permission denied.\n");
        cmd->ireturn = 1;
        closedir(tmp);
        return -2;
    }
    closedir(tmp);
    return 0;
}

void cmdnotfound(struct mysh *cmd, char **input)
{
    my_putstr(input[0]);
    my_putstr(": Command not found.\n");
    cmd->ireturn = 1;
}

void cmd_execute(struct mysh *cmd, char **input)
{
    pid_t pid = 0;
    int tmp = 0, erno = 0;;
    if ((pid = fork()) == 0) {
        if (execve(input[0], input, cmd->envp) == -1)
            erno_error(input);
    } else {
        waitpid(pid, &tmp, 0);
        errorexec(cmd, tmp);
    }
}

void execute_manage(struct mysh *cmd, char **input)
{
    cmd->ireturn = 0;
    int error = errorhandling(cmd, input);
    char **path;
    char *tmp = NULL;
    char *default_path = "/usr/local/bin:/usr/bsd:/bin:/usr/bin:.";
    if (access(input[0], X_OK) == 0) {
        cmd_execute(cmd, input);
        return;
    } if (cmd->linevar == -1) {
        path = my_str_to_word_array_path(default_path);
        if (manage_exec(input, tmp, cmd, path))
            return;
    } if (error != -2) {
        envp_recup(cmd, "PATH=");
        path = my_str_to_word_array_path(cmd->str);
        if (manage_exec(input, tmp, cmd, path))
            return;
    }
    if ((error == -1 || error == 0) && cmd->cancel != 1)
        cmdnotfound(cmd, input);
}
