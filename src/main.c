/*
** EPITECH PROJECT, 2023
** B-PSU-200-LYN-2-1-minishell1-dorian.senecot
** File description:
** main
*/

#include "../include/my.h"
#include "../include/mysh.h"

void fill_stock(char *stock, int size, char *buffer)
{
    int x = 0;
    while (size--) {
        stock[x] = buffer[x];
        x++;
    } stock[x] = '\0';
}

void coding_style(char **copy, int i)
{
    if (copy[i] == NULL) {
        exit(1);
    }
}

char **dup_env(char **env)
{
    int size = 0;
    while (env[size] != NULL)
        size++;
    char **copy = NULL;
    copy = malloc(sizeof(char *) * size + 100);
    if (copy == NULL) {
        exit(1);
    } for (int i = 0; i < size; i++) {
        if (my_strncmp(env[i], "OLDPWD", 6) != 0) {
            int len = my_strlen(env[i]);
            copy[i] = malloc(sizeof(char) * len + 1);
            coding_style(copy, i);
            my_strcpy(copy[i], env[i]);
        }
    } return copy;
}

alias_t *init_alias(void)
{
    alias_t *alias = malloc(sizeof(alias_t));
    alias->cmd = NULL;
    alias->replace = NULL;
    return alias;
}

int main(int argc, char **argv, char **envp)
{
    mysh_t cmd;
    cmd.alias = init_alias();
    cmd.history = NULL;
    if (argc != 1)
        return 84;
    tmp_envp(&cmd, envp);
    cmd.envp = dup_env(envp);
    menu_manage(&cmd, argv);
    return 0;
}
