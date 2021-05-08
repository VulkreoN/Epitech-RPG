/*
** EPITECH PROJECT, 2021
** lib_taya
** File description:
** my_strcmp
*/

int my_strcmp(char const *s1, char const *s2)
{
    for (int i = 0; s1[i] != '\0' && s2[i] != '\0'; i++) {
        if (s1[i] > s2[i]) {
            return (s1[i] - s2[i]);
        }
        else if (s2[i] > s1[i]) {
            return (s1[i] - s2[i]);
        }
    }
    return (0);
}