/*
** EPITECH PROJECT, 2021
** initialise_start
** File description:
** initialise starting menu
*/

#include "taya.h"
#include "rpg.h"

static void initialise_in_function_of_game_played(start_t *start)
{
    start->played = detect_save();
    if (start->played == 0) {
        start->play_disabled = sfTexture_createFromFile(
        "assets/menu/play_large_disabled.png", NULL);
        start->play_disabled_spr = sfSprite_create();
        sfSprite_setPosition(start->play_disabled_spr, send_pos(2660, 500));
        sfSprite_setTexture(start->play_disabled_spr,
        start->play_disabled, sfTrue);
    }
    else {
        start->start = malloc(sizeof(object_t));
        set_pos(&start->start->pos, 2660, 500);
        start->start->texture = 0;
        make_sprite(start->start, "assets/menu/play_large");
    }
}

static int initialise_quit_param(start_t *start, game_t *game)
{
    start->quit = malloc(sizeof(object_t));
    set_pos(&start->quit->pos, 2660, 750);
    start->quit->texture = 0;
    make_sprite(start->quit, "assets/menu/quit");
    if (start->quit->pixel == NULL)
        return (put_game_error(game));
    start->param = malloc(sizeof(object_t));
    set_pos(&start->param->pos, 2000, 0);
    start->param->texture = 0;
    make_sprite(start->param, "assets/menu/param");
    if (start->param->pixel == NULL)
        return (put_game_error(game));
    start->rdd = sfTexture_createFromFile("assets/menu/rondoudou.png", NULL);
    if (start->rdd == NULL)
        return (put_game_error(game));
    start->rdd_spr = sfSprite_create();
    sfSprite_setTexture(start->rdd_spr, start->rdd, sfTrue);
    sfSprite_setPosition(start->rdd_spr, send_pos(970, 141));
    return (0);
}

int initialise_start(start_t *start, game_t *game)
{
    start->bg = sfTexture_createFromFile("assets/menu/bg.jpg", NULL);
    if (start->bg == NULL)
        return (put_game_error(game));
    start->bg_spr = sfSprite_create();
    sfSprite_setTexture(start->bg_spr, start->bg, sfTrue);
    start->new = malloc(sizeof(object_t));
    set_pos(&start->new->pos, 2660, 250);
    start->new->texture = 0;
    make_sprite(start->new, "assets/menu/new_game");
    if (start->new->pixel == NULL)
        return (put_game_error(game));
    initialise_in_function_of_game_played(start);
    initialise_quit_param(start, game);
    return (0);
}