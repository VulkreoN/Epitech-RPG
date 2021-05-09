/*
** EPITECH PROJECT, 2021
** find_furniture
** File description:
** rpg
*/

#include "taya.h"
#include "rpg.h"
#include <SFML/Graphics.h>
#include <stdlib.h>

void init_value(colone_t *cell, sfVector2f offset, sfIntRect *area,
char *path)
{
    if (offset.x != 0)
        area->left = offset.x;
    if (offset.y != 0)
        area->top = offset.y;
    fill_struct(sfFalse, path, cell);
}

void init_chair(colone_t *cell, sfVector2f offset, sfIntRect *area)
{
    if (offset.x != 0)
        area->left = offset.x;
    if (offset.y != 0)
        area->top = offset.y;
    fill_struct(sfTrue, "assets/map/little.png", cell);
}

void find_table_draco(enum house_furniture result, colone_t *cell,
sfIntRect *area)
{
    char *path = "assets/map/table.png";
    char *draco = "assets/map/dracofeu.png";

    if (result == TABLE_TL)
        init_value(cell, send_pos(0, 0), area, path);
    else if (result == TABLE_TR)
        init_value(cell, send_pos(16, 0), area, path);
    if (result == TABLE_BL)
        init_value(cell, send_pos(0, 16), area, path);
    else if (result == TABLE_BR)
        init_value(cell, send_pos(16, 16), area, path);
    if (result == DRACO_TL)
        init_value(cell, send_pos(0, 0), area, draco);
    else if (result == DRACO_TR)
        init_value(cell, send_pos(16, 0), area, draco);
    if (result == DRACO_BL)
        init_value(cell, send_pos(0, 16), area, draco);
    else if (result == DRACO_BR)
        init_value(cell, send_pos(16, 16), area, draco);
}

void find_desk_tr(enum house_furniture result, colone_t *cell,
sfIntRect *area)
{
    char *path = "assets/map/spritesheet.png";

    if (result == TREE_T)
        init_value(cell, send_pos(170, 123), area, path);
    else if (result == TREE_B)
        init_value(cell, send_pos(170, 139), area, path);
    if (result == DESK_T)
        init_value(cell, send_pos(85, 105), area, path);
    else if (result == DESK_M)
        init_value(cell, send_pos(85, 121), area, path);
    if (result == DESK_B)
        init_value(cell, send_pos(85, 137), area, path);
}