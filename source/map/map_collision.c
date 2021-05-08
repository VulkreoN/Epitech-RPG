/*
** EPITECH PROJECT, 2021
** map_collision
** File description:
** handle map_collision
*/

#include "rpg.h"

sfBool check_pedago_collision(sfVector2f cell, game_t *game)
{
    int value = 0;

    value = check_collide(cell, send_pos(13, 6), send_pos(36, 6));
    value += check_collide(cell, send_pos(36, 6), send_pos(37, 15));
    value += check_collide(cell, send_pos(36, 20), send_pos(38, 29));
    value += check_collide(cell, send_pos(13, 29), send_pos(36, 29));
    value += check_collide(cell, send_pos(13, 6), send_pos(13, 29));
    value += check_collide(cell, send_pos(14, 14), send_pos(31, 21));
    if (game->adv.jerome != 1)
        value += check_collide(cell, send_pos(15, 9), send_pos(15, 11));
    if (value != 0)
        return (sfTrue);
    return (sfFalse);
}

sfBool check_601_collision(sfVector2f cell, game_t *game)
{
    int value = 0;

    value = check_collide(cell, send_pos(13, 5), send_pos(23, 11));
    value += check_collide(cell, send_pos(23, 6), send_pos(26, 6));
    value += check_collide(cell, send_pos(26, 6), send_pos(35, 11));
    value += check_collide(cell, send_pos(36, 11), send_pos(37, 15));
    value += check_collide(cell, send_pos(13, 6), send_pos(13, 29));
    value += check_collide(cell, send_pos(14, 29), send_pos(36, 29));
    value += check_collide(cell, send_pos(35, 20), send_pos(38, 29));
    value += check_collide(cell, send_pos(14, 20), send_pos(23, 24));
    value += check_collide(cell, send_pos(26, 20), send_pos(35, 24));
    if (game->adv.rondodu != 1)
        value += check_collide(cell, send_pos(14, 14), send_pos(17, 19));
    else if (game->adv.rondodu == 1 && game->adv.rondoudou == 0)
        value += check_collide(cell, send_pos(14, 15), send_pos(15, 17));
    if (value != 0)
        return (sfTrue);
    return (sfFalse);
}

sfBool check_etipech_collision(sfVector2f cell, player_t *player)
{
    int value = 0;

    value = check_collide(cell, send_pos(34, 0), send_pos(37, 16));
    value += check_collide(cell, send_pos(34, 19), send_pos(34, 34));
    value += check_collide(cell, send_pos(14, 31), send_pos(15, 34));
    value += check_collide(cell, send_pos(14, 8), send_pos(15, 26));
    value += check_collide(cell, send_pos(14, 0), send_pos(15, 3));
    value += check_collide(cell, send_pos(15, 0), send_pos(33, 0));
    value += check_lily_collision(cell, player);
    if (value != 0)
        return (sfTrue);
    return (sfFalse);
}

sfBool check_carrefour_collision(sfVector2f cell, player_t *player)
{
    int value = 0;

    value = check_collide(cell, send_pos(9, 23), send_pos(24, 25));
    value += check_collide(cell, send_pos(9, 18), send_pos(17, 20));
    value += check_collide(cell, send_pos(9, 8), send_pos(10, 18));
    value += check_collide(cell, send_pos(9, 8), send_pos(25, 13));
    value += check_collide(cell, send_pos(16, 13), send_pos(22, 15));
    value += check_collide(cell, send_pos(24, 14), send_pos(25, 20));
    value += check_collide(cell, send_pos(26, 24), send_pos(42, 25));
    value += check_collide(cell, send_pos(30, 23), send_pos(31, 25));
    value += check_collide(cell, send_pos(38, 38), send_pos(23, 25));
    value += check_collide(cell, send_pos(25, 8), send_pos(26, 18));
    value += check_collide(cell, send_pos(27, 14), send_pos(28, 15));
    value += check_collide(cell, send_pos(29, 13), send_pos(40, 19));
    value += check_collide(cell, send_pos(40, 13), send_pos(42, 15));
    value += check_collide(cell, send_pos(9, 0), send_pos(9, 25));
    value += check_collide(cell, send_pos(42, 0), send_pos(42, 25));
    value += check_guard_collision(cell, player);
    if (value != 0)
        return (sfTrue);
    return (sfFalse);
}

sfBool check_jap_garden_collision(sfVector2f cell)
{
    if (((cell.x >= 2 && cell.x <= 20) && (cell.y >= 0 && cell.y <= 13))
    || ((cell.x >= 30 && cell.x <= 47) && (cell.y >= 0 && cell.y <= 14))
    || ((cell.x == 29) && (cell.y == 10 || cell.y == 11)))
        return (sfTrue);
    else if (cell.y >= 21)
        return (sfTrue);
    return (sfFalse);
}