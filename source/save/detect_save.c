/*
** EPITECH PROJECT, 2021
** B-MUL-200-TLS-2-1-myrpg-johann.sako
** File description:
** detect_save
*/

#include "rpg.h"
#include <stdio.h>
#include <unistd.h>

static const int NO_ERROR = 1;
static const int EPI_ERROR = 0;

int detect_save(void)
{
    char const *filepath = ".save";
    FILE *save_file = fopen(filepath, "r");
    char *save = NULL;
    size_t save_len = 0;

    if (!save_file)
        return EPI_ERROR;
    getline(&save, &save_len, save_file);
    if (!save) {
        fclose(save_file);
        return EPI_ERROR;
    }
    if (my_str_isnum(save) == 0){
        fclose(save_file);
        free(save);
        return EPI_ERROR;
    }
    fclose(save_file);
    return NO_ERROR;
}