/*
** EPITECH PROJECT, 2021
** input
** File description:
** handle player moving input
*/

#include "rpg.h"

static void check_right(player_t *player, game_t *game, map_t *map)
{
    player->take.top = 87;
    if (map->line[(int)player->cell.y + 1].
    colone[(int)player->cell.x].isEmpty == sfTrue)
        move(player, game, 0, map->indexScreen);
    else if (map->indexScreen > 2)
        move(player, game, 0, map->indexScreen);
}

static void check_left(player_t *player, game_t *game, map_t *map)
{
    player->take.top = 30;
    if (map->line[(int)player->cell.y + 1].
    colone[(int)player->cell.x - 2].isEmpty == sfTrue)
        move(player, game, 1, map->indexScreen);
    else if (map->indexScreen > 2)
        move(player, game, 1, map->indexScreen);
}

static void check_up(player_t *player, game_t *game, map_t *map)
{
    player->take.top = 0;
    if (map->line[(int)player->cell.y].
    colone[(int)player->cell.x - 1].isEmpty == sfTrue)
        move(player, game, 3, map->indexScreen);
    else if (map->indexScreen > 2)
        move(player, game, 3, map->indexScreen);
}

static void check_down(player_t *player, game_t *game, map_t *map)
{
    player->take.top = 57;
    if (map->line[(int)player->cell.y + 2].
    colone[(int)player->cell.x - 1].isEmpty == sfTrue)
        move(player, game, 2, map->indexScreen);
    else if (map->indexScreen > 2)
        move(player, game, 2, map->indexScreen);
}

void check_input(player_t *player, game_t *game, map_t *map)
{
    void (*path[])(player_t *, game_t *, map_t *) =
    {check_left, check_right, check_up, check_down};

    player->isMoving = sfFalse;
    for (int inc = 71; inc < 75; inc++) {
        if (sfKeyboard_isKeyPressed(inc))
            path[inc - 71](player, game, map);
    }
}