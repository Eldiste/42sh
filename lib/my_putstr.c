/*
** EPITECH PROJECT, 2022
** my_putstr
** File description:
** displays one-by-one the characters of a string
*/

#include "../include/my.h"

int my_putstr(char const *str)
{
    while (*str) {
        my_putchar(*str++);
    }
}
