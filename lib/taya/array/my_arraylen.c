/*
** EPITECH PROJECT, 2021
** B-MUL-200-TLS-2-1-myrpg-johann.sako
** File description:
** my_arraylen
*/

#include <stddef.h>

size_t my_arraylen(char **array)
{
    size_t len = 0;

    for (; array[len] != NULL; len++);
    return len;
}