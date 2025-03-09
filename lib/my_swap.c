/*
** EPITECH PROJECT, 2022
** my_swap
** File description:
** swaps the content of two integers
*/

void my_swap(int *a, int *b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}
