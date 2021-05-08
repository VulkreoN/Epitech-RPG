/*
** EPITECH PROJECT, 2021
** lib_taya
** File description:
** my_putchar
*/

#include <unistd.h>

void my_dputchar(int fd, char c)
{
    write(fd, &c, 1);
}