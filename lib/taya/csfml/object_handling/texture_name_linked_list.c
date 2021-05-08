/*
** EPITECH PROJECT, 2021
** texture_name_linked_list
** File description:
** linked list for texture's names
*/

#include "../../../../include/taya.h"
#include "../../../../include/rpg.h"
#include "../../../../include/linked_list.h"

void destroy_list(linked_list_t *list)
{
    linked_list_t *prev;

    list = list->first;
    while (list->next != NULL) {
        prev = list;
        list = list->next;
        free(prev->name);
        free(prev);
    }
}

void make_list_file_name(linked_list_t *list, char *name)
{
    list->name = malloc(sizeof(char) * (my_strlen(name) + 1));
    for (int inc = 0; inc < my_strlen(name); inc++)
        list->name[inc] = name[inc];
    list->name[my_strlen(name)] = '\0';
}

void create_new_list(linked_list_t *list, char *name)
{
    list->next = malloc(sizeof(linked_list_t));
    if (list->next == NULL)
        return;
    make_list_file_name(list->next, name);
    list->next->first = list->first;
    list->next->next = NULL;
}