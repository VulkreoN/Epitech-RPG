/*
** EPITECH PROJECT, 2021
** B-MUL-200-TLS-2-1-myrpg-johann.sako
** File description:
** load_save
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "taya.h"
#include "rpg.h"

static const int NO_ERROR = 0;
static const int EPI_ERROR = 84;
static char const *filepath = ".save";

static void assign_save(char *str, int line, game_t *game)
{
    if (line == 0 && my_str_isnum(str) == 1)
        game->tmp.atk = my_atoi(str);
    if (line == 1 && my_str_isnum(str) == 1)
        game->tmp.def = my_atoi(str);
    if (line == 2 && my_str_isnum(str) == 1)
        game->tmp.money = my_atoi(str);
    if (line == 3 && my_str_isnum(str) == 1)
        game->tmp.lily = my_atoi(str);
    if (line == 4 && my_str_isnum(str) == 1)
        game->tmp.cell.x = my_atoi(str);
    if (line == 5 && my_str_isnum(str) == 1)
        game->tmp.cell.y = my_atoi(str);
    if (line == 6 && my_str_isnum(str) == 1)
        game->tmp.index = my_atoi(str);
}

static void assign_save_game(char *str, int line, game_t *game)
{
    if (line == 7 && my_str_isnum(str) == 1)
        game->adv.covid = my_atoi(str);
    if (line == 8 && my_str_isnum(str) == 1)
        game->adv.jerome = my_atoi(str);
    if (line == 9 && my_str_isnum(str) == 1)
        game->adv.maxence = my_atoi(str);
    if (line == 10 && my_str_isnum(str) == 1)
        game->adv.pops = my_atoi(str);
    if (line == 11 && my_str_isnum(str) == 1)
        game->adv.rondodu = my_atoi(str);
    if (line == 12 && my_str_isnum(str) == 1)
        game->adv.rondoudou = my_atoi(str);
    if (line == 13 && my_str_isnum(str) == 1)
        game->adv.wise = my_atoi(str);
    if (line == 14 && my_str_isnum(str) == 1)
        game->intro = my_atoi(str);
}

int load_save(game_t *game)
{
    FILE *save_file = fopen(filepath, "r");
    char *buffer = NULL;
    size_t size = 0;
    ssize_t line_size = 0;
    int line_count = 0;

    if (!save_file)
        return EPI_ERROR;
    line_size = getline(&buffer, &size, save_file);
    while (line_size >= 0) {
        if (line_count <= 6)
            assign_save(buffer, line_count, game);
        else
            assign_save_game(buffer, line_count, game);
        line_size = getline(&buffer, &size, save_file);
        line_count++;
    }
    fclose(save_file);
    free(buffer);
    return NO_ERROR;
}