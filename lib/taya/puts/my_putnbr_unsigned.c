/*
** EPITECH PROJECT, 2021
** lib_taya
** File description:
** my_putnbr_unsigned
*/

#include <unistd.h>
#include "taya.h"

void my_putnbr_unsigned(unsigned int nb)
{
    if (nb > 9) {
        my_putnbr(nb / 10);
        my_putnbr(nb % 10);
    } else
        my_putchar(nb + '0');
}