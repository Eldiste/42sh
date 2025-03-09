/*
** EPITECH PROJECT, 2022
** my_put_nbr
** File description:
** display the number given in a parameter
*/

#include "../include/my.h"

int my_put_nbr(int nb)
{
    int nbr2;

    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
    }
    if (nb >= 10) {
        nbr2 = nb % 10;
        nb = nb / 10;
        my_put_nbr(nb);
        my_putchar(nbr2 + 48);
    } else {
        my_putchar(nb + 48);
    }
    return 0;
}
