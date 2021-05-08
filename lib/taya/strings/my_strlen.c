/*
** EPITECH PROJECT, 2021
** lib_taya
** File description:
** my_strlen
*/

int my_strlen(char const *str)
{
    int len = 0;

    for (len = 0; str[len] != '\0'; len++);
    return (len);
}