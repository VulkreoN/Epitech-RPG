/*
** EPITECH PROJECT, 2021
** lib_taya
** File description:
** my_putnbr
*/

#include <limits.h>
#include <unistd.h>
#include "taya.h"

void my_dputnbr(int fd, int nb)
{
    if (nb == INT_MIN) {
        write(fd, "-2147483648", 11);
    }
    if (nb < 0) {
        my_dputchar(fd, '-');
        nb = -nb;
    }
    if (nb > 9) {
        my_dputnbr(fd, nb / 10);
        my_dputnbr(fd, nb % 10);
    } else {
        my_dputchar(fd, nb + '0');
    }
}