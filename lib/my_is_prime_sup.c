/*
** EPITECH PROJECT, 2022
** my_find_prime_sup
** File description:
** returns the smallest prime number that is > or = to the number given
*/

int my_is_prime(int nb);

int my_find_prime_sup(int nb)
{
    while (my_is_prime(nb) == 0) {
        nb++;
    }
    return nb;
}
