/*
** EPITECH PROJECT, 2022
** Epitech
** File description:
** manage_input.c
*/

#include "mysh.h"

int cmd_manage_input(struct mysh *cmd, char **input, char *new_line)
{
    if (my_strcmp(input[0], "which") == 0) {
        if (lentabin(input) > 1) {
            cmd_which(cmd, input);
            return 0;
        } else {
            my_putstr("which: Too few arguments.\n");
            cmd->ireturn = 1;
            return 0;
        }
    } if (my_strcmp(input[0], "where") == 0) {
        if (lentabin(input) > 1) {
            return cmd_where(cmd, input);
        } else {
            my_putstr("where: Too few arguments.\n");
            cmd->ireturn = 1;
            return 0;
        }
    }
}
