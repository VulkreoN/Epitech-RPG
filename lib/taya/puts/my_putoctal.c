/*
** EPITECH PROJECT, 2021
** lib_taya
** File description:
** my_putoctal
*/

#include "taya.h"

void my_putoctal(int nb)
{
    int result = 0;

    for (int i = 1; nb != 0; i *= 10) {
        result += i * (nb % 8);
        nb = nb / 8;
    }
    my_putnbr(result);
}