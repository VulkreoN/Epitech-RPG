/*
** EPITECH PROJECT, 2020
** undefined
** File description:
** my_atoi.c
*/

int my_atoi(char *str)
{
    int nb = 0;
    for (; *str && (*str >= '0' && *str <= '9'); ++str) {
        nb *= 10;
        nb += *str - '0';
    }
    return nb;
}
