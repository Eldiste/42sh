/*
** EPITECH PROJECT, 2023
** B-PSU-200-LYN-2-1-42sh-dorian.senecot
** File description:
** repeat
*/

#include "../../include/my.h"
#include "../../include/mysh.h"

char **stack_my_tab(char **tab)
{
    int nb_word = lentabin(tab) - 2;
    char **new = malloc(sizeof(char *) * (nb_word + 1));
    if (new == NULL) {
        return NULL;
    }
    for (int i = 2; i < lentabin(tab); i++) {
        new[i - 2] = my_strdup(tab[i]);
    }
    new[nb_word] = NULL;
    return new;
}

int error_handling_rep(mysh_t *cmd, char **input)
{
    if (lentabin(input) < 3) {
        my_putstr("Bad arguments.\n");
        cmd->ireturn = 1; return 1;
    } if (my_str_isnum(input[1]) == 1) {
        my_putstr("Please enter number.\n");
        cmd->ireturn = 1; return 1;
    }
    return 0;
}

int repeat(mysh_t *cmd, char **input, char *new_line)
{
    char **tmp;
    if (error_handling_rep(cmd, input) == 1)
        return 0;
    tmp = stack_my_tab(input);
    for (int i = 0; i < my_getnbr(input[1]); i++) {
        cmd_manage(cmd, tmp, new_line);
    }
    return 0;
}
