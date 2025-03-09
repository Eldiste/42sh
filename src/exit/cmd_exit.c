/*
** EPITECH PROJECT, 2023
** B-PSU-200-LYN-2-1-minishell1-dorian.senecot
** File description:
** cmd_exit
*/

#include "../../include/my.h"
#include "../../include/mysh.h"

int pass_space(char *str, int i)
{
    while (str[i] == ' ') {
        i++;
    } return i;
}

int cmd_exit(struct mysh *cmd)
{
    my_putstr("exit\n");
    exit(cmd->ireturn);
}
