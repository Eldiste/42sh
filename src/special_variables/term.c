/*
** EPITECH PROJECT, 2023
** term
** File description:
** term
*/

#include "../../include/my.h"
#include "../../include/mysh.h"

void change_term(char *value, char *name, char **input, char **new_env)
{
    int i = 0, size = my_strlen(name) + my_strlen(value) + 2;
    char *comb = malloc(sizeof(char) * size);
    if (comb == NULL)
        exit(84);
    if (input[1] != NULL) {
        comb = my_strcat(my_strcat(name, "="), value);
    } else {
        comb = my_strcat(name, "=");
    }
    for (; new_env[i] != NULL; i++);
    new_env[i] = malloc(sizeof(char) * size);
    if (new_env[i] == NULL)
        exit(84);
    new_env[i] = my_strcpy(new_env[i], comb);
}

int my_term(struct mysh *cmd, char **input, char **new_env)
{
    change_term(input[1], "TERM", input, new_env);
    return 0;
}
