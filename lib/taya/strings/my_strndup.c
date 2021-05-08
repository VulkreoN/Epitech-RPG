/*
** EPITECH PROJECT, 2021
** lib_taya
** File description:
** my_strndup
*/

#include <taya.h>
#include <stdlib.h>

char *my_strndup(char const *str, int n)
{
    char *dup_str = NULL;

    dup_str = malloc(sizeof(char) * (n + 1));
    my_strncpy(dup_str, str, n);
    return dup_str;
}