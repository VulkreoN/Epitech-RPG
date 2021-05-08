/*
** EPITECH PROJECT, 2020
** main
** File description:
** my_printf
*/

#include <stdarg.h>
#include <stdlib.h>
#include "../../../include/taya.h"

int octal(int a);

char *no_printable(char *str)
{
    char *result = malloc(sizeof(char) * my_strlen(str) + 4);
    int b = 0;
    int c = 0;

    for (int a = 0; str[a] != '\0'; a++, b++) {
        if (str[a] < 32 || str[a] >= 127) {
            result[b] = '\\';
            b++;
            c = str[a];
            c = octal(c);
            result[b] = '0';
            b++;
            result[b] = c / 10 + '0';
            b++;
            result[b] = c % 10 + '0';
        } else {
            result[b] = str[a];
        }
    }
    return (result);
}

void binary(int nb)
{
    int count = 1;
    int div = 0;
    int b = nb;
    char *result = malloc(sizeof(char) * nb);

    while (b > 1) {
        b = b / 2;
        count++;
    }
    for (int a = 2; nb >= 1;) {
        div = nb % a;
        nb = nb / 2;
        count--;
        result[count] = div + '0';
    }
    my_putstr(result);
}

int disp_stdarg1(int place , char *s, ...)
{
    va_list list;
    int g = 0;
    int a = 0;

    va_start(list, s);
    for (a = place; s[a] != '\0'; a++) {
        if (s[a] == '%' && s[a + 1] == 's') {
            my_putstr(va_arg(list, char *));
            return (a + 1);
        } else if (s[a] == '%' && s[a + 1] == 'i') {
            my_putnbr(va_arg(list, int));
            return (a + 1);
        }
        if (s[a] == '%' && s[a + 1] == 'c') {
            my_putchar(va_arg(list, int));
            return (a + 1);
        } else if (s[a] == '%' && s[a + 1] == 'b') {
            g = va_arg(list, int);
            binary(g);
            return (a + 1);
        }
    }
    return (a);
}

void other(int a, int b, char *str, va_list list)
{
    if (str[a] == '%' && str[a + 1] == 'S') {
        my_putstr(no_printable(va_arg(list, char *)));
    }
    if (str[a] == '%' && str[a + 1] == 'b') {
        b = va_arg(list, int);
        a = disp_stdarg1(a, str, b);
    } else if (str[a] != '%' && str[a - 1] != '%') {
        my_putchar(str[a]);
    }
}

void my_printf(char *str, ...)
{
    va_list list;
    char *d = 0;
    int b = 0;
    char c = 0;

    va_start(list, str);
    for (int a = 0; str[a] != '\0'; a++) {
        if (str[a] == '%' && str[a + 1] == 's') {
            d = va_arg(list, char *);
            a = disp_stdarg1(a, str, d);
        } else if (str[a] == '%' && str[a + 1] == 'i') {
            b = va_arg(list, int);
            a = disp_stdarg1(a, str, b);
        }
        if (str[a] == '%' && str[a + 1] == 'c') {
            c = va_arg(list, int);
            a = disp_stdarg1(a, str, c);
        }
        other(a, b, str, list);
    }
}
