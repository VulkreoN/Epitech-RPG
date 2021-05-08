/*
** EPITECH PROJECT, 2021
** lib_taya
** File description:
** my_strdup
*/

#include <stdlib.h>
#include <taya.h>

char *my_strdup(char const *str)
{
    char *dup_str = NULL;

    dup_str = malloc(sizeof(char) * (my_strlen(str) + 1));
    my_strcpy(dup_str, str);
    return dup_str;
}