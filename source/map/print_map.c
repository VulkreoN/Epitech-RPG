/*
** EPITECH PROJECT, 2021
** print_map
** File description:
** handle map printing
*/

#include "rpg.h"

static const char *texture[] = {
    "assets/map/jardinjap.jpg",
    "assets/map/carrouf.jpg",
    "assets/map/etipech.jpg",
    "assets/map/601.jpg",
    "assets/map/pedago.jpg"
};

static int print_map_texture(game_t *game, sfVector2f pos, int index)
{
    sfTexture *pixel;
    sfSprite *spr;

    pixel = sfTexture_createFromFile(texture[index], NULL);
    if (pixel == NULL)
        return (put_game_error(game));
    spr = sfSprite_create();
    sfSprite_setTexture(spr, pixel, sfTrue);
    sfSprite_setPosition(spr, pos);
    sfRenderWindow_drawSprite(game->window, spr, NULL);
    sfTexture_destroy(pixel);
    sfSprite_destroy(spr);
    return (0);
}

void display_map(game_t *game, map_t *map)
{
    switch (map->indexScreen) {
        case 3:
            print_map_texture(game, send_pos(0, 0), 0);
            break;
        case 4:
            print_map_texture(game, send_pos(330, 262), 1);
            break;
        case 5:
            print_map_texture(game, send_pos(508, 0), 2);
            break;
        case 6:
            print_map_texture(game, send_pos(508, 216), 3);
            break;
        case 7:
            print_map_texture(game, send_pos(508, 216), 4);
            break;
        default:
            break;
    }
}