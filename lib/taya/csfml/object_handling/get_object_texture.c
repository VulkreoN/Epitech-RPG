/*
** EPITECH PROJECT, 2021
** get_object_texture
** File description:
** get object texture from file
*/

#include "../../../../include/taya.h"
#include "../../../../include/rpg.h"
#include "../../../../include/linked_list.h"

int check_if_file_is_png(char *file)
{
    int length = my_strlen(file);

    if (file[length - 1] == 'g' && file[length - 2] == 'n'
    && file[length - 3] == 'p')
        return (1);
    return (0);
}

int take_files_name(linked_list_t *list, int file_number, DIR *dd)
{
    struct dirent *dir;

    list->first = list;
    list->next = NULL;
    while ((dir = readdir(dd)) != NULL) {
        if (check_if_file_is_png(dir->d_name) == 1 && file_number == 0) {
            file_number += 1;
            make_list_file_name(list, dir->d_name);
        }
        else if (check_if_file_is_png(dir->d_name) == 1) {
            file_number += 1;
            create_new_list(list, dir->d_name);
            list = list->next;
        }
    }
    list = list->first;
    sort_list(list);
    list = list->first;
    return (file_number);
}

void make_file_path(char *path, char *start, char *file)
{
    int inc = 0;

    for (; inc < my_strlen(start); inc++)
        path[inc] = start[inc];
    path[my_strlen(start)] = '/';
    inc++;
    for (int to = 0; to < my_strlen(file); to++, inc++)
        path[inc] = file[to];
    path[inc] = '\0';
}

void give_path_to_texture(int file_number, linked_list_t *list,
char *start, object_t *object)
{
    char *path = NULL;

    for (int inc = 0; inc < file_number; inc++) {
        path = malloc(sizeof(char) *
        (my_strlen(start) + my_strlen(list->name) + 2));
        make_file_path(path, start, list->name);
        object->pixel[inc] = sfTexture_createFromFile(path, NULL);
        if (list->next != NULL) {
            list = list->next;
        }
        free(path);
    }
    object->img = file_number;
}

void make_object_texture(object_t *object, char *start)
{
    DIR *dd = opendir(start);
    int file_number = 0;
    linked_list_t *list;

    if (dd == 0)
        return;
    list = malloc(sizeof(linked_list_t));
    file_number = take_files_name(list, file_number, dd);
    object->pixel = malloc(sizeof(sfTexture *) * (file_number + 1));
    give_path_to_texture(file_number, list, start, object);
    if (file_number != 0)
        destroy_list(list);
    object->pixel[file_number] = NULL;
    closedir(dd);
}