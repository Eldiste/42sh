/*
** EPITECH PROJECT, 2023
** B-PSU-200-LYN-2-1-42sh-dorian.senecot
** File description:
** history
*/

#include "../../include/my.h"
#include "../../include/mysh.h"

int history_print_nbr(mysh_t *cmd, int nb)
{
    int i, n = 0;
    for (i = 0; cmd->history[i]; i++);
    if (nb > i)
        nb = i;
    i -= nb;
    for (; cmd->history[i]; i++) {
        my_put_nbr(i + 1);
        my_putstr("  ");
        my_putstr(cmd->history[i]);
        my_putstr("\n");
    }
    return 0;
}

int history_print(mysh_t *cmd)
{
    for (int i = 0; cmd->history[i]; i++) {
        my_put_nbr(i + 1);
        my_putstr("  ");
        my_putstr(cmd->history[i]);
        my_putstr("\n");
    } return 0;
}

void set_history(mysh_t *cmd, char *tmp)
{
    if (tmp[0] == '\0')
        return;
    int i;
    char **new_history;
    if (cmd->history == NULL) {
        new_history = malloc(sizeof(char *) * 2);
        new_history[0] = my_strdup(tmp);
        new_history[1] = NULL;
        cmd->history = new_history;
        return;
    }
    for (i = 0; cmd->history[i] != NULL; i++);
    new_history = realloc(cmd->history, sizeof(char *) * (i + 2));
    cmd->history = new_history;
    cmd->history[i] = my_strdup(tmp);
    cmd->history[i + 1] = NULL;
}
