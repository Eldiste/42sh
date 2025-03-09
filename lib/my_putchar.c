/*
** EPITECH PROJECT, 2022
** myputchar
** File description:
** putchar
*/

#include "../include/my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}
