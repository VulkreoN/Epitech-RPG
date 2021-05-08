/*
** EPITECH PROJECT, 2021
** lib_taya
** File description:
** my_strupcase
*/

char *my_strupcase(char *str)
{
    int i = 0;

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 'a' + 'A';
        }
    }
    return (str);
}