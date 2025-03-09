/*
** EPITECH PROJECT, 2023
** B-PSU-200-LYN-2-1-42sh-dorian.senecot
** File description:
** backticks
*/

#include "../../include/my.h"
#include "../../include/mysh.h"

char* array_to_string(char** array, int size)
{
    int total_length = 0;
    for (int i = 0; i < size; i++) {
        total_length += my_strlen(array[i]);
    }
    char* result = (char*) malloc(total_length + size);
    result[0] = '\0';
    for (int i = 0; i < size; i++) {
        result = my_strcat(result, array[i]);
        if (i < size - 1) result = my_strcat(result, " ");
    }
    return result;
}

char *var_print(struct mysh *cmd, char *input, wordexp_t exp, char *tmp)
{
    char *newstr = NULL;
    if (my_strcmp(input, "$?") == 0) {
        char *tmp = malloc(sizeof(char));
        tmp[0] = '\0'; free(input);
        tmp = my_strcat(my_int_to_strnum(cmd->ireturn), tmp);
        input = my_strdup(tmp);
        free(tmp);
    } if (input[0] == '$' && input[1] != '?') {
        newstr = malloc(sizeof(char) * (my_strlen(input) + 1));
        my_strcpy(newstr, input + 1);
        newstr = add_character(newstr, '=');
        envp_recup(cmd, newstr);
        cmd->status == 0 ? (my_putstr(my_strcpy(newstr, input + 1)),
        my_putstr(": Undefined variable.\n"), cmd->cancel = 1) :
        (wordexp(input, &exp, WRDE_SHOWERR | WRDE_UNDEF),
        free(input),
        tmp = array_to_string(exp.we_wordv, lentabin(exp.we_wordv)),
        input = my_strdup(tmp),
        free(tmp));
    } return input;
}

void backticks(struct mysh *cmd, char **input)
{
    wordexp_t exp;
    char *tmp = NULL;
    int count = 0;
    for (int i = 0; input[i]; i++) {
        for (int y = 0; input[i][y]; y++) {
            input[i][y] == '`' ? count++ : 0;
            input[i][y] == '$' ? count = 2 : 0;
        }
    } if (count != 2)
        return;
    for (int i = 0; input[i] != NULL; i++) {
        input[i] = my_strdup(var_print(cmd, input[i], exp, tmp));
        if (input[i][0] == '`' && input[i][my_strlen(input[i]) - 1] == '`') {
            wordexp(input[i], &exp, WRDE_SHOWERR | WRDE_UNDEF);
            free(input[i]);
            tmp = array_to_string(exp.we_wordv, lentabin(exp.we_wordv));
            input[i] = my_strdup(tmp);
            free(tmp);
        }
    }
}
