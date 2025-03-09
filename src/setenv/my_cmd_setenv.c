/*
** EPITECH PROJECT, 2023
** my_cmd_setenv
** File description:
** my_cmd_setenv
*/

#include "../../include/my.h"
#include "../../include/mysh.h"

int setenv_error(struct mysh *cmd, char **input)
{
    for (int i = 0; input[1][i] != '\0'; i++) {
        if ((input[1][i] < 'A' || input[1][i] > 'Z') &&
        (input[1][i] < 'a' || input[1][i] > 'z') &&
        (input[1][i] < '0' || input[1][i] > '9') &&
        input[1][i] != ' ' && input[1][i] != '\n'
        && input[1][i] != '_') {
            my_putstr("setenv: Variable name must ");
            my_putstr("contain alphanumeric characters.\n");
            cmd->ireturn = 1;
            return 1;
        }
    } if (my_strlen(input[1]) >= 78) {
        my_putstr("setenv: Variable name too long.\n");
        cmd->ireturn = 1;
        return 1;
    } setenv_error_value(cmd, input);
    return 0;
}

void create_setenv(char *value, char *name, char **input, char **new_env)
{
    int i = 0, size = my_strlen(name) + my_strlen(value) + 2;
    char *comb = malloc(sizeof(char) * size);
    if (comb == NULL)
        exit(84);
    if (input[2] != NULL) {
        comb = my_strcat(my_strcat(name, "="), value);
    } else {
        comb = my_strcat(name, "=");
    } for (; new_env[i] != NULL; i++);
    new_env[i] = malloc(sizeof(char) * size);
    if (new_env[i] == NULL)
        exit(84);
    new_env[i] = my_strcpy(new_env[i], comb);
}

void create_value(char *line, char *value, int i)
{
    int b = 0;
    while (line[i] != '\0') {
        value[b] = line[i];
        i++;
        if (line[i] == ' ') {
            my_putstr("wrong syntax : setenv NAME VALUE\n");
            return;
        } b++;
    } b--;
    value[b + 1] = '\0';
}

void setenv_func(struct mysh *cmd, char **new_env,
char **input, char *new_line)
{
    int i = 6, end = 0, b = 0;
    char *name = malloc(sizeof(char) * my_strlen(new_line) + 1), *value;
    input[2] != NULL ? value = malloc(sizeof(char) *
    my_strlen(input[2]) + 1) : 0; i = pass_space(new_line, i);
    while (new_line[i] != '\0' && end == 0) {
        name[b] = new_line[i];
        if (new_line[i] != '\0')
            i++;
        if (new_line[i] == ' ') {
            i = pass_space(new_line, i);
            end = 1;
        } b++;
    } if (input[2] == NULL && new_line[i - 1] != ' ')
        b--;
    if (input[2] == NULL)
        name[b + 1] = '\0';
    else
        name[b] = '\0';
    create_value(new_line, value, i);
    create_setenv(value, name, input, new_env);
}

void my_setenv(struct mysh *cmd, char **new_env, char **input, char *new_line)
{
    if (input[1] != NULL && input[2] != NULL
    && input[3] != NULL) {
        cmd->ireturn = 1;
        my_putstr("setenv: Too many arguments.\n");
        return;
    } if (input[1] == NULL) {
        while (*new_env) {
            my_putstr(*new_env);
            my_putchar('\n');
            new_env++;
        } return;
    } if ((input[1][0] < 65 || input[1][0] > 90) &&
        (input[1][0] < 97 || input[1][0] > 122) && input[1][0] != '_') {
        my_putstr("setenv: Variable name must begin with a letter.\n");
        cmd->ireturn = 1;
        return;
    } if (setenv_error(cmd, input))
        return;
    setenv_func(cmd, new_env, input, new_line);
}
