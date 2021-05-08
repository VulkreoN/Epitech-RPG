/*
** EPITECH PROJECT, 2021
** wind_effect
** File description:
** handle wind effect
*/

#include "rpg.h"

static const char *texture[] = {
    "assets/wind/wind1.png",
    "assets/wind/wind2.png",
    "assets/wind/wind3.png",
    "assets/wind/wind4.png",
    "assets/wind/wind5.png",
    "assets/wind/wind6.png",
    "assets/wind/wind7.png",
    "assets/wind/wind8.png",
    "assets/wind/wind9.png",
    "assets/wind/wind10.png",
    "assets/wind/wind11.png",
    "assets/wind/wind12.png",
    "assets/wind/wind13.png",
    "assets/wind/wind14.png",
    "assets/wind/wind15.png",
    "assets/wind/wind16.png"
};

void create_wind_effect(map_t *map, sfRenderWindow *window)
{
    sfTexture *pixel = NULL;
    sfSprite *spr = NULL;

    if (map->wind % 17 == 0 && rand() % 50 == 1) {
        map->wind += 1;
        map->wind_pos.x = rand() % 1800;
        map->wind_pos.y = rand() % 900;
    }
    else if (map->wind % 17 != 0) {
        pixel = sfTexture_createFromFile(texture[(map->wind % 17) - 1], NULL);
        spr = sfSprite_create();
        sfSprite_setTexture(spr, pixel, sfTrue);
        sfSprite_setPosition(spr, map->wind_pos);
        sfRenderWindow_drawSprite(window, spr, NULL);
        sfTexture_destroy(pixel);
        sfSprite_destroy(spr);
        map->wind += 1;
    }
}