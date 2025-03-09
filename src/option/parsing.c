/*
** EPITECH PROJECT, 2023
** B-PSU-200-LYN-2-1-minishell2-dorian.senecot
** File description:
** parsing
*/

#include "../../include/my.h"
#include "../../include/mysh.h"

void my_strcat2(char *buffer, int *len, const char *src)
{
    int i = 0;
    for (; src[i] != '\0'; i++) {
        buffer[*len + i] = src[i];
    }
    *len += i;
    buffer[*len] = '\0';
}

char *parsing(char *input)
{
    int buffer_len = my_strlen(input) + 3;
    char *buffer = malloc(buffer_len * sizeof(char));
    int i, j = 0;
    for (i = 0; input[i] != '\0'; i++) {
        if (input[i] == ';' && input[i - 1] != ' ' && input[i + 1] == ' '
            && input[i - 1] != '\t' && input[i + 1] != '\t') {
            my_strcat2(buffer, &j, " ");
        } if (input[i] == ';' && input[i - 1] == ' ' && input[i + 1] != ' '
            && input[i - 1] != '\t' && input[i + 1] != '\t') {
            my_strcat2(buffer, &j, "; ");
            i++;
        } if (input[i] == ';' && input[i - 1] != ' ' && input[i + 1] != ' '
            && input[i - 1] != '\t' && input[i + 1] != '\t') {
            my_strcat2(buffer, &j, " ");
            my_strcat2(buffer, &j, "; ");
        } else
            buffer[j++] = input[i];
    } buffer[j] = '\0';
    return buffer;
}
