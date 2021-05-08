/*
** EPITECH PROJECT, 2021
** lib_taya
** File description:
** my_puthexa
*/

#include "taya.h"

void my_puthexa(int nb, int capital)
{
    if (nb < 0) {
        my_putchar('-');
        my_puthexa(nb * -1, capital);
    }
    if (nb >= 15)
        my_puthexa(nb / 16, capital);
    if (capital == 1)
        my_putchar("0123456789ABCDEF"[nb % 16]);
    else if (capital == 0)
        my_putchar("0123456789abcdef"[nb % 16]);
}