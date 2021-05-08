/*
** EPITECH PROJECT, 2021
** lib_taya
** File description:
** my_revstr
*/

#include "taya.h"

char *my_revstr(char *str)
{
    char c;
    int len = my_strlen(str);

    for (int i = 0; i < len; i++, len--) {
        c = str[i];
        str[i] = str[len - 1];
        str[len - 1] = c;
    }
    return (str);
}