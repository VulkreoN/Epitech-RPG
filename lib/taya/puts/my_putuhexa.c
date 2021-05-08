/*
** EPITECH PROJECT, 2021
** lib_taya
** File description:
** my_putuhexa
*/

#include "taya.h"

void my_putuhexa(unsigned int nb, int capital)
{
    if (nb >= 15)
        my_putuhexa(nb / 16, capital);
    if (capital == 1)
        my_putchar("0123456789ABCDEF"[nb % 16]);
    else if (capital == 0)
        my_putchar("0123456789abcdef"[nb % 16]);
}