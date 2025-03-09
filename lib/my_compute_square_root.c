/*
** EPITECH PROJECT, 2022
** my_compute_square_root
** File description:
** returns the square root
*/

int my_compute_square_root(int nb)
{
    int res = 0;

    if (nb <= 0) {
        return 0;
    }
    while (res * res != nb) {
        res++;
        if (res > nb) {
            return 0;
        }
    }
    return res;
}
