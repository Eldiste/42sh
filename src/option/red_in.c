/*
** EPITECH PROJECT, 2023
** B-PSU-200-LYN-2-1-minishell2-dorian.senecot
** File description:
** red_in
*/

#include "../../include/my.h"
#include "../../include/mysh.h"

int red_in_plus(struct mysh *cmd, char *file, char **input, char *new_line)
{
    int fd = 0;
    int keep_fd = dup(STDIN_FILENO);
    char **tmp;
    if (!file)
        return 0;
    if ((fd = open(file, O_RDONLY)) == -1)
        return 0;
    tmp = remove_str_from_tab(input, "<<");
    tmp = remove_str_from_tab(tmp, file);
    if (dup2(fd, STDIN_FILENO) == -1) {
        return 0;
    } cmd_manage(cmd, tmp, new_line);
    close(fd);
    if (dup2(keep_fd, STDIN_FILENO) == -1) {
        return 0;
    } close(keep_fd);
    return 0;
}

int red_in(struct mysh *cmd, char *file, char **input, char *new_line)
{
    int fd = 0;
    int keep_fd = dup(STDIN_FILENO);
    char **tmp;
    if (!file)
        return 0;
    if ((fd = open(file, O_RDONLY)) == -1)
        return 0;
    tmp = remove_str_from_tab(input, "<");
    tmp = remove_str_from_tab(tmp, file);
    if (dup2(fd, STDIN_FILENO) == -1) {
        return 0;
    } cmd_manage(cmd, tmp, new_line);
    close(fd);
    if (dup2(keep_fd, STDIN_FILENO) == -1) {
        return 0;
    } close(keep_fd);
    return 0;
}
