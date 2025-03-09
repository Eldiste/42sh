/*
** EPITECH PROJECT, 2023
** B-PSU-200-LYN-2-1-minishell1-dorian.senecot
** File description:
** cmd_setenv
*/

#include "../../include/my.h"
#include "../../include/mysh.h"

int setenv_error_value(struct mysh *cmd, char **input)
{
    if (input[2] == NULL)
        return 0;
    for (int i = 0; input[2][i] != '\0'; i++) {
        if ((input[2][i] < 'A' || input[2][i] > 'Z') &&
        (input[2][i] < 'a' || input[2][i] > 'z') &&
        (input[2][i] < '0' || input[2][i] > '9') &&
        input[2][i] != ' ' && input[2][i] != '\n'
        && input[2][i] != '_') {
            my_putstr("setenv: Variable name must ");
            my_putstr("contain alphanumeric characters.\n");
            cmd->ireturn = 1;
            return 1;
        }
    } return 0;
}

int error_handling(struct mysh *cmd, char *str, char *str2)
{
    cmd->linevar = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] < 'A' || str[i] > 'Z')
            && (str[i] < 'a' || str[i] > 'z')
            && (str[i] < '0' || str[i] > '9') && str[i] != ' '
            && str[i] != '\n' && str[i] != '_') {
            cmd->linevar = 1;
            return 84;
        }
    }
    for (int i = 0; str2[i] != '\0'; i++) {
        if ((str2[i] < 'A' || str2[i] > 'Z')
            && (str2[i] < 'a' || str2[i] > 'z')
            && (str2[i] < '0' || str2[i] > '9') && str2[i] != ' '
            && str2[i] != '\n' && str2[i] != '_') {
            cmd->linevar = 1;
            return 84;
        }
    }
    return 0;
}

char *cleanstr_addon(char *str)
{
    char *tmp = malloc(sizeof(char *) * my_strlen(str) + 1);
    int c = 0;
    int tmpi = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[tmpi] == ' ' || str[tmpi] == '\t') {
            tmpi++;
        } else {
            tmp[c] += str[i];
            c++;
        }
    }
    return tmp;
}

char *cleanstr(char *str)
{
    char *tmp = malloc(sizeof(char *) * my_strlen(str) + 1);
    int c = 0;
    char prev_char = '\0';
    for (int i = 0; str[i] != '\n'; i++) {
        if (str[i] != ' ' && str[i] != '\t' || prev_char != ' '
            && prev_char != '\t') {
            tmp[c] = str[i];
            c++;
        }
        prev_char = str[i];
    }
    if (tmp[c - 1] == ' ' || tmp[c - 1] == '\t') {
        tmp[c - 1] = '\0';
    } else
        tmp[c] = '\0';
    tmp = cleanstr_addon(tmp);
    return tmp;
}

char **new_env(struct mysh *cmd, char *var, char *value)
{
    return cmd->envp;
}
