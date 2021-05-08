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

void make_furniture(map_t *map_t, int a, int b, char *string)
{
    sfIntRect area = {0, 0, 16, 16};
    colone_t *cell = &map_t->line[a].colone[b];
    sfBool find_object = sfTrue;

    switch (check_enum(string)) {
        case(CANAPE_TL):
            fill_struct(sfFalse, "assets/map/canap.png", cell);
            break;
        case(CANAPE_TM):
            area.left = 16;
            fill_struct(sfFalse, "assets/map/canap.png", cell);
            break;
        case(CANAPE_TR):
            area.left = 32;
            fill_struct(sfFalse, "assets/map/canap.png", cell);
            break;
        case(CANAPE_BL):
            area.top = 16;
            fill_struct(sfFalse, "assets/map/canap.png", cell);
            break;
        case(CANAPE_BM):
            area.left = 16;
            area.top = 16;
            fill_struct(sfFalse, "assets/map/canap.png", cell);
            break;
        case(CANAPE_BR):
            area.left = 32;
            area.top = 16;
            fill_struct(sfFalse, "assets/map/canap.png", cell);
            break;
        case(CARPET1_TL):
            fill_struct(sfTrue, "assets/map/carpet2.png", cell);
            break;
        case(CARPET1_TM):
            area.left = 32;
            fill_struct(sfTrue, "assets/map/carpet2.png", cell);
            break;
        case(CARPET1_TR):
            area.left = 64;
            fill_struct(sfTrue, "assets/map/carpet2.png", cell);
            break;
        case(CARPET1_BL):
            area.top = 64;
            fill_struct(sfTrue, "assets/map/carpet2.png", cell);
            break;
        case(CARPET1_BM):
            area.left = 32;
            area.top = 64;
            fill_struct(sfTrue, "assets/map/carpet2.png", cell);
            break;
        case(CARPET1_BR):
            area.left = 64;
            area.top = 64;
            fill_struct(sfTrue, "assets/map/carpet2.png", cell);
            break;
        case(CARPET1_ML):
            area.top = 32;
            fill_struct(sfTrue, "assets/map/carpet2.png", cell);
            break;
        case(CARPET1_MM):
            area.left = 32;
            area.top = 32;
            fill_struct(sfTrue, "assets/map/carpet2.png", cell);
            break;
        case(CARPET1_MR):
            area.left = 64;
            area.top = 32;
            fill_struct(sfTrue, "assets/map/carpet2.png", cell);
            break;
        case(TABLE_TL):
            fill_struct(sfFalse, "assets/map/table.png", cell);
            break;
        case(TABLE_TR):
            area.left = 16;
            fill_struct(sfFalse, "assets/map/table.png", cell);
            break;
        case(TABLE_BL):
            area.top = 16;
            fill_struct(sfFalse, "assets/map/table.png", cell);
            break;
        case(TABLE_BR):
            area.left = 16;
            area.top = 16;
            fill_struct(sfFalse, "assets/map/table.png", cell);
            break;
        case(CHAIR):
            fill_struct(sfTrue, "assets/map/little.png", cell);
            break;
        case(DRACO_TL):
            fill_struct(sfFalse, "assets/map/dracofeu.png", cell);
            break;
        case(DRACO_TR):
            area.left = 16;
            fill_struct(sfFalse, "assets/map/dracofeu.png", cell);
            break;
        case(DRACO_BL):
            area.top = 16;
            fill_struct(sfFalse, "assets/map/dracofeu.png", cell);
            break;
        case(DRACO_BR):
            area.left = 16;
            area.top = 16;
            fill_struct(sfFalse, "assets/map/dracofeu.png", cell);
            break;
        case(TREE_T):
            area.top = 123;
            area.left = 170;
            fill_struct(sfFalse, "assets/map/spritesheet.png", cell);
            break;
        case(TREE_B):
            area.top = 139;
            area.left = 170;
            fill_struct(sfFalse, "assets/map/spritesheet.png", cell);
            break;
        case(DESK_T):
            area.top = 105;
            area.left = 85;
            fill_struct(sfFalse, "assets/map/spritesheet.png", cell);
            break;
        case(DESK_M):
            area.top = 120;
            area.left = 85;
            fill_struct(sfFalse, "assets/map/spritesheet.png", cell);
            break;
        case(DESK_B):
            area.top = 136;
            area.left = 85;
            fill_struct(sfFalse, "assets/map/spritesheet.png", cell);
            break;
        default:
            find_object = sfFalse;
            break;
    }
    if (find_object == sfTrue)
        fill_cell(a, b, map_t, &area);
}