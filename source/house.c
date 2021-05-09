/*
** EPITECH PROJECT, 2021
** house
** File description:
** rpg
*/

#include "taya.h"
#include "rpg.h"
#include <SFML/Graphics.h>
#include <stdlib.h>

void init_couch(colone_t *cell, sfVector2f offset, sfIntRect *area)
{
    if (offset.x != 0)
        area->left = offset.x;
    if (offset.y != 0)
        area->top = offset.y;
    fill_struct(sfFalse, "assets/map/canap.png", cell);
}

void find_couch(enum house_furniture result, colone_t *cell, sfIntRect *area)
{
    if (result == CANAPE_TL)
        init_couch(cell, send_pos(0, 0), area);
    if (result == CANAPE_TM)
        init_couch(cell, send_pos(16, 0), area);
    else if (result == CANAPE_TR)
        init_couch(cell, send_pos(32, 0), area);
    if (result == CANAPE_BL)
        init_couch(cell, send_pos(0, 16), area);
    else if (result == CANAPE_BM)
        init_couch(cell, send_pos(16, 16), area);
    if (result == CANAPE_BR)
        init_couch(cell, send_pos(32, 16), area);
}

void init_carpet(colone_t *cell, sfVector2f offset, sfIntRect *area)
{
    if (offset.x != 0)
        area->left = offset.x;
    if (offset.y != 0)
        area->top = offset.y;
    fill_struct(sfTrue, "assets/map/carpet2.png", cell);
}

void find_carpet(enum house_furniture result, colone_t *cell, sfIntRect *area)
{
    if (result == CARPET1_TL)
        init_carpet(cell, send_pos(0, 0), area);
    else if (result == CARPET1_TM)
        init_carpet(cell, send_pos(32, 0), area);
    if (result == CARPET1_TR)
        init_carpet(cell, send_pos(64, 0), area);
    else if (result == CARPET1_BL)
        init_carpet(cell, send_pos(0, 64), area);
    if (result == CARPET1_BM)
        init_carpet(cell, send_pos(32, 64), area);
    else if (result == CARPET1_BR)
        init_carpet(cell, send_pos(64, 64), area);
    if (result == CARPET1_ML)
        init_carpet(cell, send_pos(0, 32), area);
    else if (result == CARPET1_MM)
        init_carpet(cell, send_pos(32, 32), area);
    if (result == CARPET1_MR)
        init_carpet(cell, send_pos(64, 32), area);
}

void make_furniture(map_t *map_t, int a, int b, char *string)
{
    sfIntRect area = {0, 0, 16, 16};
    colone_t *cell = &map_t->line[a].colone[b];
    enum house_furniture result = check_enum(string);

    if (result < 6) {
        find_couch(result, cell, &area);
        fill_cell(a, b, map_t, &area);
    } else if (result >= 6 && result < 15) {
        find_carpet(result, cell, &area);
        fill_cell(a, b, map_t, &area);
    }
    if (result == CHAIR) {
        init_chair(cell, send_pos(0, 0), &area);
        fill_cell(a, b, map_t, &area);
    }
    if (result >= 15 && result < 24 && result != 19) {
        find_table_draco(result, cell, &area);
        fill_cell(a, b, map_t, &area);
    } else if (result >= 24) {
        find_desk_tr(result, cell, &area);
        fill_cell(a, b, map_t, &area);
    }
}