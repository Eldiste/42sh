/*
** EPITECH PROJECT, 2023
** B-PSU-200-LYN-2-1-minishell1-dorian.senecot
** File description:
** menu_manage
*/

#include "../include/my.h"
#include "../include/mysh.h"

int cmd_manage_addon2(struct mysh *cmd, char **input, char *new_line)
{
    if (my_strcmp(input[0], "history") == 0) {
        if (lentabin(input) == 1)
            return history_print(cmd);
        if (lentabin(input) == 2)
            return history_print_nbr(cmd, my_getnbr(input[1]));
        else
            my_putstr("history: Too few arguments.\n");
        return 0;
    } if (my_strcmp(input[0], "echo") == 0) {
        if (lentabin(input) == 1) {
            my_putstr("\n");
            return 0;
        } return my_echo(cmd, input);
    } if (my_strcmp(input[0], "repeat") == 0) {
        return repeat(cmd, input, new_line);
    } return -1;
}

int cmd_manage_addon(struct mysh *cmd, char **input, char *new_line)
{
    if (my_strcmp(input[0], "setenv") == 0) {
        my_setenv(cmd, cmd->envp, input, new_line);
        return 0;
    } if (my_strcmp(input[0], "alias") == 0) {
        alias(cmd, input);
        return 0;
    } if (my_strcmp(input[0], "unsetenv") == 0) {
        cmd->envp = my_unsetenv(cmd, cmd->envp, input);
        return 0;
    } if (my_strcmp(input[0], "env") == 0) {
        if (lentabin(input) == 1)
            return cmd_envp(cmd);
        return 0;
    } if (my_strcmp(input[0], "term") == 0) {
        char *new_input[] = {"unsetenv", "TERM", NULL};
        cmd->envp = my_unsetenv(cmd, cmd->envp, new_input);
        return my_term(cmd, input, cmd->envp);
    } return -1;
}

int flags_manage(struct mysh *cmd, char **input, char *new_line)
{
    cmd->ireturn = 0;
    int j = 0;
    for (; input[j]; j++);
    for (int i = lentabin(input) - 1; i >= 0; i--) {
        if (i != 0 && (((my_strcmp(input[i - 1], ">") == 0)
        || ((my_strcmp(input[i - 1], "<")) == 0)))
        || (((my_strcmp(input[j - 1], ">") == 0)
        || ((my_strcmp(input[j - 1], "<")) == 0))))
            check_redirection(cmd, input, i);
        if (my_strcmp(input[i], ">") == 0)
            return red_out(cmd, input[i + 1], input, new_line);
        if (my_strcmp(input[i], ">>") == 0)
            return red_out_plus(cmd, input[i + 1], input, new_line);
        if (my_strcmp(input[i], "<") == 0)
            return red_in(cmd, input[i + 1], input, new_line);
        if (my_strcmp(input[i], "<<") == 0)
            return red_in_plus(cmd, input[i + 1], input, new_line);
        if (my_strcmp(input[i], "|") == 0)
            return clean_pipe(cmd, input, i, new_line);
    } return -1;
}

int cmd_manage(struct mysh *cmd, char **input, char *new_line)
{
    if (flags_manage(cmd, input, new_line) == 0)
        return 0;
    if (set_jobs_controls(cmd, input, new_line) == 0)
        return 0;
    if (my_strcmp(input[0], "exit") == 0) {
        if (lentabin(input) == 1)
            return cmd_exit(cmd);
        return 0;
    } if (my_strcmp(input[0], "cd") == 0) {
        if (lentabin(input) == 1)
            return cmd_cd(cmd, input[0]);
        if (lentabin(input) == 2)
            return cmd_cd(cmd, input[1]);
        else { cmd->ireturn = 1;
            return my_putstr("cd: too many arguments\n");
        }
    } if (cmd_manage_addon(cmd, input, new_line) != 0
    && cmd_manage_addon2(cmd, input, new_line) != 0
    && cmd_manage_input(cmd, input, new_line) != 0)
        execute_manage(cmd, input);
}

int menu_manage(struct mysh *cmd, char **argv)
{
    cmd->old = 0, cmd->tmp = 0, cmd->ireturn = 0;
    while (1) {
        prompt(cmd);
        get_pars(cmd);
        cmd->start = 1;
        for (int i = 0; cmd->parsing[i] != NULL; i++) {
            separator(cmd, cmd->parsing[i]);
            cmd->parsing[i] = change_pipe(cmd, cmd->parsing[i]);
            cmd->result = 0;
            separator_loop(cmd, i);
        }
    } free(cmd->parsing);
}
