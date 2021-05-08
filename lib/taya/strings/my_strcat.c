/*
** EPITECH PROJECT, 2020
** my_strcat
** File description:
** cat two strings
*/

int my_strlen(char const *str);

char *my_strcat(char *dest, char const *src)
{
    dest += my_strlen(dest);
    for (;*src;)
        *dest++ = *src++;
    *dest++ = '\0';
    return (dest);
}
