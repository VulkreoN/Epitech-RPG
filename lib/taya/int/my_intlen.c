/*
** EPITECH PROJECT, 2020
** int_len
** File description:
** count the length of an int
*/

int my_intlen(int nb)
{
    int length = 0;

    if (nb < 0) {
        nb = -nb;
        length = length + 1;
    }
    for (; nb > 9; length++)
        nb = nb / 10;
    return (length + 1);
}
