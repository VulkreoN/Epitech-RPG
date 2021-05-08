/*
** EPITECH PROJECT, 2021
** lib_taya
** File description:
** my_str_to_word_array
*/

#include <stdlib.h>
#include <taya.h>

int my_wordlen(char *str, int i, char c)
{
    int index = i;

    for (; str[i] != c && str[i] != '\0' ; i++);
    return i - index;
}

int my_skip(char *str, int i, char c)
{
    for (; str[i] == c; i++);
    return i;
}

int my_occurence(char *str, char c)
{
    int occurence = 0;
    int i = my_skip(str, 0, c);

    while (str[i] != '\0') {
        if (str[i] == c) {
            occurence++;
            i = my_skip(str, i, c);
        }
        else
            i++;
    }
    return occurence;
}

char **my_str_to_word_array(char *str, char c)
{
    char **array = NULL;
    int occurence = my_occurence(str, c);
    int i = my_skip(str, 0, c);
    int j = 0;
    int k = 0;

    array = malloc(sizeof(char *) * (occurence + 2));
    while (str[i] != '\0') {
        i = my_skip(str, i, c);
        if (str[i] == '\0')
            break;
        k = my_wordlen(str, i, c);
        array[j] = my_strndup(str + i, k);
        i += k;
        j++;
    }
    array[j] = NULL;
    return array;
}