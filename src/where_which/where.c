/*
** EPITECH PROJECT, 2022
** Epitech
** File description:
** where.c
*/

#include "mysh.h"

char *concat_path(char *dir_path, char *command)
{
    size_t dir_path_len = my_strlen(dir_path);
    size_t command_len = my_strlen(command);
    char *concatenated_path = malloc(dir_path_len + 1 + command_len + 1);
    my_strcpy(concatenated_path, dir_path);
    concatenated_path[dir_path_len] = '/';
    my_strcpy(concatenated_path + dir_path_len + 1, command);

    return concatenated_path;
}

void print_found_paths(char **paths, char **input, int i)
{
    for (int j = 0; paths[j] != NULL; j++) {
        char *concatenated_path = concat_path(paths[j], input[i]);
        if (access(concatenated_path, X_OK) == 0) {
            my_putstr(concatenated_path);
            my_putstr("\n");
        }
        free(concatenated_path);
    }
    free_tab(paths);
}

int cmd_where(struct mysh *cmd, char **input)
{
    for (int i = 1; input[i] != NULL; i++) {
        if (my_strcmp(input[i], "ls") == 0) {
            my_putstr("ls is aliased to ls --color=auto\n");
        }
        char *env_path = getenv("PATH");
        if (env_path == NULL) {
            my_putstr("Error: PATH variable not found.\n");
            cmd->ireturn = 1;
        }
        char **paths = my_str_to_word_array_path(env_path);
        print_found_paths(paths, input, i);
    }
    return 0;
}
