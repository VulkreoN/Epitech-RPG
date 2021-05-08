/*
** EPITECH PROJECT, 2021
** lib_taya
** File description:
** my_putnbr
*/

#include <limits.h>
#include <unistd.h>
#include "taya.h"

void my_putnbr(int nb)
{
    if (nb == INT_MIN) {
        write(1, "-2147483648", 11);
    }
    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    if (nb > 9) {
        my_putnbr(nb / 10);
        my_putnbr(nb % 10);
    } else {
        my_putchar(nb + '0');
    }
}