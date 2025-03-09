/*
** EPITECH PROJECT, 2023
** B-PSU-200-LYN-2-1-minishell1-dorian.senecot
** File description:
** utils_st
*/

#include "../include/my.h"
#include "../include/mysh.h"

void free_tab(char **input)
{
    for (int i = 0; input[i]; i++) {
        free(input[i]);
    }
    free(input);
}

int count_wrd(char **input, size_t x)
{
    int tmp = 0;
    while (input[x + tmp] && my_strcmp(input[x + tmp], ";") != 0) {
        tmp++;
    }
    return tmp;
}

int final_pars(struct mysh *cmd, char **input)
{
    size_t c = 1, x = 0, i = 0;
    for (; input[i]; i++) {
        if (my_strcmp(input[i], ";") == 0)
            c++;
    }
    if (my_strcmp(input[i - 1], ";") == 0)
        c--;
    cmd->parsing = malloc(sizeof(char **) * (c + 1));
    for (size_t index = 0; index < c; index++) {
        cmd->parsing[index] = malloc(sizeof(char *) *
        (count_wrd(input, x) + 1));
        for (int k = 0; k < count_wrd(input, x); k++) {
            cmd->parsing[index][k] = my_strdup(input[x + k]);
        }
        cmd->parsing[index][count_wrd(input, x)] = NULL;
        x += count_wrd(input, x) + 1;
    }
    free_tab(input);
    cmd->parsing[c] = NULL;
    return 0;
}

void get_pars(struct mysh *cmd)
{
    size_t size = 0;
    char *input = 0, *input2 = 0;
    if (getline(&input, &size, stdin) == EOF) {
        isatty(0) == 1 ? my_putstr("\nexit\n") : 0;
        exit(cmd->ireturn);
    }
    input[size] = '\0';

    int i = 0;
    if (browse_input(input, &i)) {
        input = inhibitors(input, i);
    }

    input2 = cleanstr(my_strdup(input));
    set_history(cmd, input2);
    input = parsing(cleanstr(input));
    char **tab = my_str_to_word_array(input);
    cmd->tab_line = my_str_to_word_arrays(input, ':');
    free(input);
    final_pars(cmd, tab);
}

void prompt(struct mysh *cmd)
{
    if (isatty(0) == 1) {
        my_putstr("[");
        envp_recup(cmd, "USER=");
        my_putstr(cmd->str);
        my_putstr("@");
        envp_recup(cmd, "PWD=");
        my_putstr(cmd->str);
        my_putstr("]$ ");
    }
}
