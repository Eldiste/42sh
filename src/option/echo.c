/*
** EPITECH PROJECT, 2023
** B-PSU-200-LYN-2-1-42sh-dorian.senecot
** File description:
** echo
*/

#include "../../include/my.h"
#include "../../include/mysh.h"

void print_withoutc(char *input)
{
    for (int y = 0; input[y] != '\0'; y++) {
        if (input[y] != 39 && input[y] != '"')
        my_putchar(input[y]);
    }
}

char *add_character(char* chaine, char caractere)
{
    size_t longueur_chaine = my_strlen(chaine);
    char* nouvelle_chaine = malloc(sizeof(char) * ( my_strlen(chaine) + 2));
    my_strcpy(nouvelle_chaine, chaine);
    nouvelle_chaine[longueur_chaine] = caractere;
    nouvelle_chaine[longueur_chaine + 1] = '\0';
    free(chaine);
    return nouvelle_chaine;
}

int echo_print_var2(mysh_t *cmd, char **input, int status, int i)
{
    char *newstr;
    if (my_strcmp(input[i], "$?") == 0) {
        my_put_nbr(cmd->ireturn);
        status == 0 ? my_putstr("\n") : 0;
    } else {
        newstr = malloc(sizeof(char) * (my_strlen(input[i]) + 1));
        my_strcpy(newstr, input[i] + 1);
        newstr = add_character(newstr, '=');
        envp_recup(cmd, newstr);
        cmd->status == 0 ? (cmd->ireturn = 1) :
        (my_putstr(cmd->str),
        status == 0 ? my_putstr("\n") : 0,
        free(newstr));
    } return 0;
}

int echo_print_var(mysh_t *cmd, char **input, int status, int tmp)
{
    char *newstr;
    int i = tmp;
    for (; input[i + 1] != NULL; i++) {
        if (my_strcmp(input[i], "$?") == 0) {
            my_put_nbr(cmd->ireturn);
            my_putstr(" ");
        } else {
            newstr = malloc(sizeof(char) * (my_strlen(input[i]) + 1));
            my_strcpy(newstr, input[i] + 1);
            newstr = add_character(newstr, '=');
            envp_recup(cmd, newstr);
            cmd->status == 0 ? (cmd->ireturn = 1) :
            (my_putstr(cmd->str),
            free(newstr),
            my_putstr(" "));
        }
    } return echo_print_var2(cmd, input, status, i);
}

int my_echo(mysh_t *cmd, char **input)
{
    int i = 1;
    int status = 0;
    if (my_strcmp(input[1], "-n") == 0) {
        if (input[2] == NULL) {
            return 0;
        } status = 1;
    }
    if (status == 1)
        i = 2;
    if (input[i][0] == '$') {
        return echo_print_var(cmd, input, status, i);
    } for (; input[i + 1] != NULL; i++) {
        print_withoutc(input[i]);
        my_putstr(" ");
    } print_withoutc(input[i]);
    status == 0 ? my_putstr("\n") : 0;
    return 0;
}
