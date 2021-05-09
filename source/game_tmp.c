/*
** EPITECH PROJECT, 2021
** game_tmp
** File description:
** handle game tmp
*/

#include "rpg.h"

void initialise_game_tmp(game_t *game)
{
    game->tmp.atk = 10;
    game->tmp.def = 10;
    game->tmp.money = 100;
    game->tmp.lily = 0;
    game->tmp.cell.x = 18;
    game->tmp.cell.y = 12;
    game->tmp.index = 1;
}

void give_tmp(game_t *game, map_t *map, player_t *player)
{
    map->indexScreen = game->tmp.index;
    player->cell = game->tmp.cell;
    player->attack = game->tmp.atk;
    player->defense = game->tmp.def;
    player->money = game->tmp.money;
    player->lily = game->tmp.lily;
}

void get_tmp(game_t *game, map_t *map, player_t *player)
{
    game->tmp.index = map->indexScreen;
    game->tmp.cell = player->cell;
    game->tmp.atk = player->attack;
    game->tmp.def = player->defense;
    game->tmp.money = player->money;
    game->tmp.lily = player->lily;
}