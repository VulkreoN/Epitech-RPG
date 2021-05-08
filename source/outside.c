/*
** EPITECH PROJECT, 2021
** ouside
** File description:
** my_rpg
*/

#include "taya.h"
#include "rpg.h"
#include <SFML/Graphics.h>
#include <stdlib.h>

enum outside enum_outside(char *string)
{
    enum outside cell = 84;

    if (my_strcmp(string, "0h") == 0)
        cell = HOUSE;
    if (my_strcmp(string, "08") == 0)
        cell = GRASS;
    if (my_strcmp(string, "09") == 0)
        cell = FLOWERS;
    return (cell);
}

void built_house(colone_t *cell, int a, int b, map_t *map_t)
{
    sfIntRect area = {148, 0, 64, 80};

    fill_struct(sfFalse, "assets/map/sprite.png", cell);
    set_pos(&cell->pos, (WIDTH * (b - 3)) *
    2.4, (HEIGHT * (a - 4)) * 1.8);
    cell->texture =
    sfTexture_createFromFile(cell->path, &area);
    for (int i = a - 4; i <= a; i++) {
        for (int j = b - 3; j <= b; j++) {
            map_t->line[i].colone[j].isEmpty = sfFalse;
            if (i == a && j == b - 2)
                map_t->line[i].colone[j].isEmpty = sfTrue;
        }
    }
}