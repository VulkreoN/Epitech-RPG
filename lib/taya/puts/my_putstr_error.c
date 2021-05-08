/*
** EPITECH PROJECT, 2021
** lib_taya
** File description:
** my_putstr_error
*/

#include "taya.h"
#include <unistd.h>

int my_putstr_error(char const *str)
{
    return (write(2, str, my_strlen(str)));
}