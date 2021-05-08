/*
** EPITECH PROJECT, 2021
** lib_taya
** File description:
** my_putstr
*/

#include <unistd.h>
#include "taya.h"

int my_dputstr(int fd, char const *str)
{
    return (write(fd, str, my_strlen(str)));
}