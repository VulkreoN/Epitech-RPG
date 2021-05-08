/*
** EPITECH PROJECT, 2021
** initialise_settings
** File description:
** settings handling
*/

#include "taya.h"
#include "rpg.h"

static int initialise_more_less(settings_t *param, game_t *game)
{
    param->high = malloc(sizeof(object_t));
    set_pos(&param->high->pos, 1470, 0);
    param->high->texture = 0;
    make_sprite(param->high, "assets/menu/more");
    if (param->high->pixel == NULL)
        return (put_game_error(game));
    param->low = malloc(sizeof(object_t));
    set_pos(&param->low->pos, 1720, 0);
    param->low->texture = 0;
    make_sprite(param->low, "assets/menu/less");
    if (param->low->pixel == NULL)
        return (put_game_error(game));
    return (0);
}

int initialise_settings(settings_t *param, game_t *game)
{
    param->bg = sfTexture_createFromFile("assets/menu/bg.jpg", NULL);
    if (param->bg == NULL)
        return (put_game_error(game));
    param->bg_spr = sfSprite_create();
    sfSprite_setTexture(param->bg_spr, param->bg, sfTrue);
    param->back = malloc(sizeof(object_t));
    set_pos(&param->back->pos, 0, 0);
    param->back->texture = 0;
    make_sprite(param->back, "assets/menu/back");
    if (param->back->pixel == NULL)
        return (put_game_error(game));
    param->play = malloc(sizeof(object_t));
    set_pos(&param->play->pos, 1120, 0);
    param->play->texture = 0;
    make_sprite(param->play, "assets/menu/play");
    if (param->play->pixel == NULL)
        return (put_game_error(game));
    initialise_more_less(param, game);
    return (0);
}