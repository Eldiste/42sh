/*
** EPITECH PROJECT, 2023
** B-CPE-110-LYN-1-1-antman-dorian.senecot
** File description:
** fs_open_file
*/

#include "../include/my.h"

int errorfile(int fd, int stat)
{
    if (fd == -1) {
        close(fd);
        return 84;
    }
    if (stat == -1)
        return 84;
    return 0;
}

int fs_open_file(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char *buffer;
    if (errorfile(fd, 31) == 84)
        return 84;
    buffer = malloc(sizeof(char) * 31 + 1);
    read(fd, buffer, 31);
    close(fd);
    buffer[31] = '\0';
    my_str_to_word_array(buffer);
    free(buffer);
    return 0;
}
