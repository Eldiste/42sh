/*
** EPITECH PROJECT, 2023
** B-PSU-200-LYN-2-1-42sh-dorian.senecot
** File description:
** check_pid
*/

#include "../../include/mysh.h"
#include "../../include/my.h"

int check_pid(char **input, char *new_line, int i)
{
    input[i] = NULL;
    pid_t pid = launch_process(input, new_line);
    if (pid > 0)
        return add_bg_process(pid, new_line);
    else
        return 1;
}
