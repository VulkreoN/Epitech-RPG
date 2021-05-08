/*
** EPITECH PROJECT, 2021
** sort_list
** File description:
** sort linked list
*/

#include "../../../../include/taya.h"
#include "../../../../include/rpg.h"
#include "../../../../include/linked_list.h"

void inverse_struct(linked_list_t *list)
{
    char *tmp;
    int len1 = my_strlen(list->name);
    int len2 = my_strlen(list->next->name);

    tmp = malloc(sizeof(char) * (len1 + 1));
    for (int inc = 0; inc < len1; inc++)
        tmp[inc] = list->name[inc];
    tmp[len1] = '\0';
    free(list->name);
    list->name = NULL;
    list->name = malloc(sizeof(char) * (len2 + 1));
    for (int inc = 0; inc < len2; inc++)
        list->name[inc] = list->next->name[inc];
    list->name[len2] = '\0';
    free(list->next->name);
    list->next->name = malloc(sizeof(char) * (len1 + 1));
    for (int inc = 0; inc < len1; inc++)
        list->next->name[inc] = tmp[inc];
    list->next->name[len1] = '\0';
    free(tmp);
}

int make_bubble_sort_list(linked_list_t *list, int ok)
{
    while (list->next != NULL) {
        if (my_strcmp(list->name, list->next->name) > 0) {
            ok = 1;
            inverse_struct(list);
        } else if (list->next != NULL)
            list = list->next;
    } return (ok);
}

void sort_list(linked_list_t *list)
{
    int ok = 1;

    list = list->first;
    while (ok != 0) {
        ok = 0;
        list = list->first;
        ok = make_bubble_sort_list(list, ok);
        list = list->first;
    } list = list->first;
}