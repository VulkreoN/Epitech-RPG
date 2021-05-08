/*
** EPITECH PROJECT, 2021
** map
** File description:
** handle map
*/

#include "rpg.h"

void handle_map(game_t *game, player_t *player, map_t *map)
{
    travel_park_garden(player, map);
    travel_from_jap_garden(player, map);
    travel_to_jap_garden(player, map);
    travel_between_601(player, map);
    travel_between_pedago(player, map);
    remove_all_foot(player, map);
    display_map(game, map);
}

int check_collide(sfVector2f cell, sfVector2f pos1, sfVector2f pos2)
{
    if ((cell.x >= pos1.x && cell.x <= pos2.x)
    && (cell.y >= pos1.y && cell.y <= pos2.y))
        return (1);
    return (0);
}

static sfBool find_map_collision(int index, sfVector2f cell,
player_t *player, game_t *game)
{
    if (cell.x >= 9 && cell.x <= 17 && cell.y >= 10
    && cell.y <= 23 && index == 2 && game->adv.covid == 0)
        return (sfTrue);
    switch (index) {
        case 3:
            return (check_jap_garden_collision(cell));
        case 4:
            return (check_carrefour_collision(cell, player));
        case 5:
            return (check_etipech_collision(cell, player));
        case 6:
            return (check_601_collision(cell, game));
        case 7:
            return (check_pedago_collision(cell, game));
        default:
            break;
    }
    return (sfFalse);
}

sfBool check_map_collision(player_t *player, game_t *game,
int index, int direction)
{
    sfVector2f cell;

    cell.x = player->cell.x;
    cell.y = player->cell.y;
    switch (direction) {
        case 0:
            cell.x += 1;
            break;
        case 1:
            cell.x -= 1;
            break;
        case 2:
            cell.y += 1;
            break;
        case 3:
            cell.y -= 1;
            break;
        default:
            break;
    } return (find_map_collision(index, cell, player, game));
}