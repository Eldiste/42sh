/*
** EPITECH PROJECT, 2023
** utils
** File description:
** utils_ts
*/

#include "../include/my.h"
#include "../include/mysh.h"

int manage_exec(char **input, char *tmp, struct mysh *cmd, char **path)
{
    for (int i = 0; path[i] != NULL; i++) {
        tmp = my_strcat(path[i], "/");
        tmp = my_strcat(tmp, input[0]);
        if (access(tmp, X_OK) == 0) {
            input[0] = tmp;
            cmd_execute(cmd, input);
            return 1;
        }
    } return 0;
}

int end_loop(pid_t pid, char *new_line)
{
    if (pid > 0)
        return add_bg_process(pid, new_line);
    else
        return 1;
}
