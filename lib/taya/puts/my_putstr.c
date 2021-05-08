/*
** EPITECH PROJECT, 2021
** lib_taya
** File description:
** my_putstr
*/

#include <unistd.h>
#include "taya.h"

int my_putstr(char const *str)
{
    return (write(1, str, my_strlen(str)));
}