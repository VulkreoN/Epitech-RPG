/*
** EPITECH PROJECT, 2021
** pause_inventory
** File description:
** handle pause inventory
*/

#include "rpg.h"

static const char *texture[] = {
    "assets/inventory/covid.png",
    "assets/inventory/pops.png",
    "assets/inventory/rondoudou.png",
};

void initialise_inventory_pos(sfVector2f *pos)
{
    pos[0].x = 748;
    pos[0].y = 645;
    pos[1].x = 845;
    pos[1].y = 645;
    pos[2].x = 950;
    pos[2].y = 645;
}

int display_invetory_element(sfVector2f pos, int element, game_t *game)
{
    sfTexture *pixel = NULL;
    sfSprite *spr = NULL;

    pixel = sfTexture_createFromFile(texture[element], NULL);
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

void handle_inventory(game_t *game)
{
    int inc = 0;
    sfVector2f *pos;

    pos = malloc(sizeof(sfVector2f) * (3));
    initialise_inventory_pos(pos);
    if (game->adv.covid == 2)
        display_invetory_element(pos[inc++], 0, game);
    if (game->adv.pops == 1)
        display_invetory_element(pos[inc++], 1, game);
    if (game->adv.rondoudou == 1)
        display_invetory_element(pos[inc++], 2, game);
    free(pos);
}