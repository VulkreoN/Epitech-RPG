/*
** EPITECH PROJECT, 2021
** lib_taya
** File description:
** my_strncpy
*/

#include <string.h>

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    if (dest == NULL || src == NULL) {
        return (NULL);
    }
    for (i = 0; src[i] != '\0' && i < n; i++) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return (dest);
}