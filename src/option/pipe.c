/*
** EPITECH PROJECT, 2023
** B-PSU-200-LYN-2-1-minishell2-dorian.senecot
** File description:
** pipe
*/

#include "../../include/my.h"
#include "../../include/mysh.h"

int lentabin(char **input)
{
    int i = 0;
    for (i; input[i] != NULL; i++);
    return i;
}

char **cp_tab(char **input)
{
    int i = 0, y = 0;
    char **tmp;
    for (i; input[i] != NULL; i++);
    tmp = malloc(sizeof(char *) * i + 1);
    for (y; y != i; y++) {
        tmp[y] = malloc(sizeof(char) * my_strlen(input[y]));
        for (int x = 0; input[y][x] != '\0'; x++)
            tmp[y][x] = input[y][x];
    }
    tmp[y] = NULL;
    return tmp;
}

int pipe_manage(struct mysh *cmd, char **input, int i, char *new_line)
{
    int fd[2], status; pipe(fd); pid_t pid1 = fork();
    if (pid1 == 0) {
        close(fd[0]); dup2(fd[1], STDOUT_FILENO);
        close(fd[1]); input[i] = NULL;
        cmd_manage(cmd, input, new_line);
        exit(cmd->ireturn);
    } pid_t pid2 = fork();
    if (pid2 == 0) {
        close(fd[1]); dup2(fd[0], STDIN_FILENO);
        close(fd[0]); int j = 0;
        for (i += 1; input[i]; i++)
            input[j++] = input[i];
        input[j] = NULL;
        cmd_manage(cmd, input, new_line);
        exit(cmd->ireturn);
    }
    close(fd[0]); close(fd[1]);
    waitpid(pid1, &status, 0);
    waitpid(pid2, &status, 0);
    return 0;
}

int clean_pipe(struct mysh *cmd, char **input, int i, char *new_line)
{
    if (input[0][0] == '|') {
        my_putstr("Invalid null command.\n");
        cmd->ireturn = 1;
        return 0;
    } return (pipe_manage(cmd, input, i, new_line));
}

char **start_change_tab(int *i, int j, char **tab, char **cpy_tab)
{
    for (*i = 0; *i <= j; (*i)++) {
        cpy_tab[*i] = malloc(sizeof(char) * (my_strlen(tab[*i]) + 1));
        cpy_tab[*i] = tab[*i];
    } return cpy_tab;
}
