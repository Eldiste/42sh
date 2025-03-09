/*
** EPITECH PROJECT, 2022
** my_is_prime
** File description:
**  returns 1 if the number is prime and 0 if not
*/

int my_is_prime(int nb)
{
    if (nb <= 1) {
        return 0;
    }
    int prime = 2;
    while (nb != prime) {
        if (nb % prime == 0) {
            return 0;
        }
        prime++;
    }
    return 1;
}
