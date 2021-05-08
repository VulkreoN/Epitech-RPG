/*
** EPITECH PROJECT, 2021
** calcul_move
** File description:
** my_rpg
*/

#include "../include/taya.h"
#include "../include/rpg.h"
#include <SFML/Graphics.h>
#include <stdlib.h>

void move_horizontally(player_t *player_t, float range)
{
    if (player_t->direction == 0) {
        if (player_t->cell.x + range < player_t->last_cell.x + 1.00) {
            player_t->cell.x += range;
        } else {
            player_t->cell.x = player_t->last_cell.x + 1.00;
            player_t->isMoving = sfFalse;
        }
    }
    if (player_t->direction == 1) {
        if (player_t->cell.x - range > player_t->last_cell.x - 1.00)
            player_t->cell.x -= range;
        else {
            player_t->cell.x = player_t->last_cell.x - 1.00;
            player_t->isMoving = sfFalse;
        }
    }
}

void move_vertically(player_t *player_t, float range)
{
    if (player_t->direction == 2) {
        if (player_t->cell.y + range < player_t->last_cell.y + 1.00) {
            player_t->cell.y += range;
        } else {
            player_t->cell.y = player_t->last_cell.y + 1.00;
            player_t->isMoving = sfFalse;
        }
    }
    if (player_t->direction == 3) {
        if (player_t->cell.y - range > player_t->last_cell.y - 1.00)
            player_t->cell.y -= range;
        else {
            player_t->cell.y = player_t->last_cell.y - 1.00;
            player_t->isMoving = sfFalse;
        }
    }
}

void calcul_move(player_t *player_t, t_timeManager *timeManger)
{
    float range = (SPEEDPLAYER * timeManger->i_deltaTime) * 0.001;

    if (timeManger->i_deltaTime == 33)
        make_foot_effect(player_t);
    if (player_t->direction < 2)
        move_horizontally(player_t, range);
    else
        move_vertically(player_t, range);
}