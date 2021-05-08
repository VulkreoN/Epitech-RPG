/*
** EPITECH PROJECT, 2021
** intro_config
** File description:
** configurate intro structure
*/

#include "rpg.h"

static void put_back_start_pos(start_t *start)
{
    set_pos(&start->new->pos, 660, 250);
    set_pos(&start->quit->pos, 660, 750);
    set_pos(&start->param->pos, 0, 0);
    sfSprite_setPosition(start->new->spr, start->new->pos);
    sfSprite_setPosition(start->quit->spr, start->quit->pos);
    sfSprite_setPosition(start->param->spr, start->param->pos);
    if (start->played != 0) {
        set_pos(&start->start->pos, 660, 500);
        sfSprite_setPosition(start->start->spr, start->start->pos);
    }
    else
        sfSprite_setPosition(start->play_disabled_spr, send_pos(660, 500));
}

void destroy_intro(intro_t *intro, start_t *start)
{
    put_back_start_pos(start);
    if (intro->bg_spr != NULL)
        sfSprite_destroy(intro->bg_spr);
    if (intro->rdd_spr != NULL)
        sfSprite_destroy(intro->rdd_spr);
    if (intro->wan_spr != NULL)
        sfSprite_destroy(intro->wan_spr);
    if (intro->bg != NULL)
        sfTexture_destroy(intro->bg);
    if (intro->rdd != NULL)
        sfTexture_destroy(intro->rdd);
    if (intro->wan != NULL)
        sfTexture_destroy(intro->wan);
    if (intro->time != NULL)
        sfClock_destroy(intro->time);
    free(intro);
}

static void initialise_null_value(intro_t *intro)
{
    intro->bg = NULL;
    intro->bg_spr = NULL;
    intro->rdd = NULL;
    intro->rdd_spr = NULL;
    intro->wan = NULL;
    intro->wan_spr = NULL;
    intro->time = NULL;
    set_pos(&(intro->rdd_pos), -150, 630);
    set_pos(&(intro->wan_pos), (1980 / 2) - (937 / 2), -408);
    intro->skip = 0;
    intro->sec = 0.0;
    intro->angle = 0.0;
}

int initialise_intro(game_t *game, intro_t *intro)
{
    initialise_null_value(intro);
    intro->bg = sfTexture_createFromFile("assets/menu/bg.jpg", NULL);
    if (intro->bg == NULL)
        return (put_game_error(game));
    intro->bg_spr = sfSprite_create();
    sfSprite_setTexture(intro->bg_spr, intro->bg, sfTrue);
    intro->wan = sfTexture_createFromFile("assets/menu/wanos.png", NULL);
    if (intro->wan == NULL)
        return (put_game_error(game));
    intro->wan_spr = sfSprite_create();
    sfSprite_setTexture(intro->wan_spr, intro->wan, sfTrue);
    intro->rdd = sfTexture_createFromFile("assets/menu/rondoudou.png", NULL);
    if (intro->rdd == NULL)
        return (put_game_error(game));
    intro->rdd_spr = sfSprite_create();
    sfSprite_setTexture(intro->rdd_spr, intro->rdd, sfTrue);
    intro->time = sfClock_create();
    return (0);
}