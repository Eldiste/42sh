/*
** EPITECH PROJECT, 2023
** my_unsetenv_cmd
** File description:
** cmd_unsetenv2
*/

#include "../../include/my.h"
#include "../../include/mysh.h"

int env_check(char *str, char **env, int k)
{
    for (int j = 0; j < my_strlen(str); j++)
        if (str[j] != env[k][j] || str[j] == '=')
            return (-1);
    return (k);
}

char **remove_env(char **env, int i)
{
    int k = 0;
    char **new_env = NULL;
    for (; env[k] != NULL; k++);
    new_env = malloc(sizeof(char *) * (k + 10));
    new_env[k] = NULL;
    k = 0;
    for (int x = 0; env[x]; x++) {
        if (x != i) {
            new_env[k] = env[x];
            k++;
        }
    } return (new_env);
}

char **cheking_delete(char **tab, char **env, int k, int x)
{
    int i = 0;
    if ((i = env_check(tab[x], env, k)) != -1) {
        env = remove_env(env, i);
    } return env;
}

char **continue_for(char **env, char **tab, int x, int k)
{
    int len = 0;
    while (env[k][len] != '=') {
        len++;
    } if (my_strlen(tab[x]) == len)
        env = cheking_delete(tab, env, k, x);
    return env;
}

char **my_unsetenv(struct mysh *cmd, char **env, char **input)
{
    if (input[1] == NULL) {
        my_putstr("unsetenv: Too few arguments.\n");
        cmd->ireturn = 1;
        return env;
    }
    for (int x = 1; input[x]; x++) {
        for (int k = 0; env[k]; k++) {
            env = continue_for(env, input, x, k);
        }
    } return env;
}
