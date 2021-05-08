/*
** EPITECH PROJECT, 2021
** lib_taya
** File description:
** my_putchar
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}