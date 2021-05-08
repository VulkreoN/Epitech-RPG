/*
** EPITECH PROJECT, 2021
** B-CPE-210-TLS-2-1-stumper2-hakim.redjem
** File description:
** my_lprintf
*/

#include "taya.h"
#include <stdarg.h>
#include <unistd.h>

int check_flag(int fd, char *format, int index, va_list vargs)
{
    if (format[index] == '%') {
        switch (format[index + 1]) {
            case 'd':
                my_dputnbr(fd, va_arg(vargs, int));
                break;
            case 's':
                my_dputstr(fd, va_arg(vargs, char *));
                break;
            case 'c':
                my_dputchar(fd, va_arg(vargs, int));
                break;
        }
        index++;
        }
    else
        write(fd, &format[index], 1);
    return index;
}

void my_ldprintf(int fd, char *format, ...)
{
    va_list vargs;

    if (!format)
        write(1, NULL, 0);
    va_start(vargs, format);
    for (int i = 0; format[i] != '\0'; i++){
        i = check_flag(fd, format, i, vargs);
    }
    va_end(vargs);
}