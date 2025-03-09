/*
** EPITECH PROJECT, 2022
** Epitech
** File description:
** which.c
*/

#include "mysh.h"

char *find_command_path(struct mysh *cmd, char *command)
{
    char *env_path = getenv("PATH");
    if (env_path == NULL) {
        my_putstr("Error: PATH variable not found.\n");
        cmd->ireturn = 1;
        return NULL;
    }
    char **paths = my_str_to_word_array_path(env_path);
    char *found_path = NULL;

    for (int i = 0; paths[i] != NULL; i++) {
        char *concatenated_path = concat_path(paths[i], command);
        if (access(concatenated_path, X_OK) == 0) {
            found_path = concatenated_path;
            break;
        }
        free(concatenated_path);
    }
    free_tab(paths);
    return found_path;
}

int cmd_which(struct mysh *cmd, char **input)
{
    for (int i = 1; input[i] != NULL; i++) {
        if (my_strcmp(input[i], "ls") == 0) {
            my_putstr("ls:\t aliased to ls --color=auto\n");
            continue;
        }
        char *path = find_command_path(cmd, input[i]);
        if (path != NULL) {
            my_putstr(path);
            my_putstr("\n");
            free(path);
        } else {
            my_putstr(input[i]);
            my_putstr(": Command not found.\n");
            cmd->ireturn = 1;
        }
    }
    return 0;
}
