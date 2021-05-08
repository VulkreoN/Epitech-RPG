/*
** EPITECH PROJECT, 2021
** map_travel
** File description:
** travel from map to map
*/

#include "rpg.h"

void travel_park_garden(player_t *player, map_t *map)
{
    if ((player->cell.x >= 21 && player->cell.x <= 29)
    && player->cell.y >= 33 && map->indexScreen == 2) {
        map->indexScreen = 3;
        player->cell.y = 1;
        player->isMoving = sfFalse;
    }
    else if ((player->cell.x >= 21 && player->cell.x <= 29)
    && player->cell.y == 0 && map->indexScreen == 3) {
        map->indexScreen = 2;
        player->cell.y = 29;
        player->isMoving = sfFalse;
    }
}

void travel_from_jap_garden(player_t *player, map_t *map)
{
    if ((player->cell.y >= 16 && player->cell.y <= 19)
    && player->cell.x >= 50 && map->indexScreen == 3) {
        map->indexScreen = 4;
        player->cell.x = 25;
        player->cell.y = 24;
        player->isMoving = sfFalse;
    }
    else if ((player->cell.y >= 15 && player->cell.y <= 19)
    && player->cell.x == 0 && map->indexScreen == 3) {
        player->cell.x = 33;
        map->indexScreen = 5;
        player->isMoving = sfFalse;
    }
}

void travel_to_jap_garden(player_t *player, map_t *map)
{
    if ((player->cell.x >= 24 && player->cell.x <= 26)
    && player->cell.y == 26 && map->indexScreen == 4) {
        map->indexScreen = 3;
        player->cell.x = 45;
        player->cell.y = 17;
        player->isMoving = sfFalse;
    }
    else if ((player->pos.y >= 480 && player->pos.y + 30 <= 587)
    && player->cell.x == 35 && map->indexScreen == 5) {
        player->cell.x = 3;
        map->indexScreen = 3;
        player->isMoving = sfFalse;
    }
}

void travel_between_601(player_t *player, map_t *map)
{
    if ((player->cell.y >= 4 && player->cell.y <= 7)
    && player->cell.x == 14 && map->indexScreen == 5) {
        map->indexScreen = 6;
        player->cell.x = 35;
        player->cell.y = 17;
        player->isMoving = sfFalse;
    }
    else if ((player->cell.y >= 16 && player->cell.y <= 19)
    && player->cell.x == 37 && map->indexScreen == 6) {
        player->cell.x = 16;
        player->cell.y = 5;
        map->indexScreen = 5;
        player->isMoving = sfFalse;
    }
}

void travel_between_pedago(player_t *player, map_t *map)
{
    if ((player->cell.y >= 26 && player->cell.y <= 30)
    && player->cell.x == 14 && map->indexScreen == 5) {
        map->indexScreen = 7;
        player->cell.x = 35;
        player->cell.y = 17;
        player->isMoving = sfFalse;
    }
    else if ((player->cell.y >= 16 && player->cell.y <= 19)
    && player->cell.x == 37 && map->indexScreen == 7) {
        player->cell.x = 16;
        player->cell.y = 27;
        map->indexScreen = 5;
        player->isMoving = sfFalse;
    }
}