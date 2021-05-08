/*
** EPITECH PROJECT, 2020
** octal
** File description:
** c
*/

int octal(int a)
{
    int b = 0;
    int count = 0;
    int c = a;

    for (; c > 8;) {
        c = c % 8;
        count = a / 8;
    }
    b = a + (2 * count);
    return (b);
}
