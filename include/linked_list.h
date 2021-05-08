/*
** EPITECH PROJECT, 2021
** linked_list
** File description:
** linked list header
*/

#ifndef LINKED_LIST_H_
    #define LINKED_LIST_H_

    typedef struct linked_list_s {
        struct linked_list_s *first;
        struct linked_list_s *next;
        char *name;
    } linked_list_t;

    void create_new_list(linked_list_t *list, char *name);

    void destroy_list(linked_list_t *list);

    void make_list_file_name(linked_list_t *list, char *name);

    void sort_list(linked_list_t *list);
#endif
