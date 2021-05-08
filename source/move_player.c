/*
** EPITECH PROJECT, 2021
** move_player
** File description:
** myRPG
*/

#include "../include/taya.h"
#include "../include/rpg.h"
#include <SFML/Graphics.h>
#include <stdlib.h>

void which_sprite(player_t *player_t)
{
    player_t->take.left = 0;
    player_t->take.width = 14;
    player_t->take.height = 22;
    for (int a = 0; a < player_t->whichSprite
    && player_t->isMoving == sfTrue; a++) {
        player_t->take.left += 29;
    }
}

void move_camera(player_t *player_t, map_t *map_t)
{
    if (map_t->indexScreen == 1 && player_t->cell.y == 30) {
        if (player_t->cell.x < 28 && player_t->cell.x > 23) {
            map_t->indexScreen += 1;
            init_screen(map_t);
            set_pos(&player_t->cell, 18.00, 7.00);
        }
    } else  if (map_t->indexScreen == 2) {
        if (player_t->cell.x == 18.00 && player_t->cell.y == 6.00) {
            map_t->indexScreen -= 1;
            init_screen(map_t);
            set_pos(&player_t->cell, 25.00, 29.00);
        }
    }
}

void move(player_t *player_t, game_t *game, int check, int index)
{
    if (check_map_collision(player_t, game, index, check))
        return;
    player_t->isMoving = sfTrue;
    player_t->direction = check;
    player_t->last_cell = player_t->cell;
}

void move_player(player_t *player_t, game_t *game,
t_timeManager *timeManager, map_t *map)
{
    if (player_t->isMoving == sfTrue) {
        player_t->lastUpdate += timeManager->i_deltaTime;
        if (player_t->lastUpdate > SPRITEUPDATEPERIOD) {
                player_t->whichSprite = (player_t->whichSprite + 1) % 9;
                player_t->lastUpdate = 0;
        }
    }
    if (player_t->isMoving == sfFalse)
        check_input(player_t, game, map);
    else {
        calcul_move(player_t, timeManager);
    }
    which_sprite(player_t);
}