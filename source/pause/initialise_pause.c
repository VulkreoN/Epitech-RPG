/*
** EPITECH PROJECT, 2021
** initialise_pause
** File description:
** initialise pause structure
*/

#include "rpg.h"

static int initialise_atk_def_btn(pause_t *pause, game_t *game)
{
    pause->atkbtn = malloc(sizeof(object_t));
    set_pos(&pause->atkbtn->pos, 745, 302);
    pause->atkbtn->texture = 0;
    make_sprite(pause->atkbtn, "assets/menu/atk");
    if (pause->atkbtn->pixel == NULL)
        return (put_game_error(game));
    pause->defbtn = malloc(sizeof(object_t));
    set_pos(&pause->defbtn->pos, 753, 440);
    pause->defbtn->texture = 0;
    make_sprite(pause->defbtn, "assets/menu/def");
    if (pause->defbtn->pixel == NULL)
        return (put_game_error(game));
    pause->rod = sfTexture_createFromFile("assets/menu/rod.png", NULL);
    if (pause->rod == NULL)
        return (put_game_error(game));
    pause->rod_spr = sfSprite_create();
    sfSprite_setTexture(pause->rod_spr, pause->rod, sfTrue);
    return (0);
}

static int initialise_pause_heading(pause_t *pause, game_t *game)
{
    pause->info = malloc(sizeof(object_t));
    set_pos(&pause->info->pos, 873, 851);
    pause->info->texture = 0;
    make_sprite(pause->info, "assets/menu/info");
    if (pause->info->pixel == NULL)
        return (put_game_error(game));
    pause->skill = malloc(sizeof(object_t));
    set_pos(&pause->skill->pos, 1036, 851);
    pause->skill->texture = 0;
    make_sprite(pause->skill, "assets/menu/skill_info");
    if (pause->skill->pixel == NULL)
        return (put_game_error(game));
    pause->player = malloc(sizeof(object_t));
    set_pos(&pause->player->pos, 710, 851);
    pause->player->texture = 0;
    make_sprite(pause->player, "assets/menu/player_info");
    if (pause->player->pixel == NULL)
        return (put_game_error(game));
    initialise_atk_def_btn(pause, game);
    return (0);
}

static int initialise_pause_menu_buttons(pause_t *pause, game_t *game)
{
    pause->home = malloc(sizeof(object_t));
    set_pos(&pause->home->pos, 951, 293);
    pause->home->texture = 0;
    make_sprite(pause->home, "assets/menu/home_menu");
    if (pause->resume->pixel == NULL)
        return (put_game_error(game));
    pause->param = malloc(sizeof(object_t));
    set_pos(&pause->param->pos, 716, 541);
    pause->param->texture = 0;
    make_sprite(pause->param, "assets/menu/param_menu");
    if (pause->param->pixel == NULL)
        return (put_game_error(game));
    pause->quit = malloc(sizeof(object_t));
    set_pos(&pause->quit->pos, 951, 541);
    pause->quit->texture = 0;
    make_sprite(pause->quit, "assets/menu/quit_menu");
    if (pause->quit->pixel == NULL)
        return (put_game_error(game));
    initialise_pause_heading(pause, game);
    return (0);
}

void intialise_pause_atk_def(pause_t *pause, player_t *player)
{
    pause->atk = player->attack;
    pause->def = player->defense;
    pause->money = player->money;
}

int initialise_pause(pause_t *pause, game_t *game, player_t *player)
{
    pause->bg = sfTexture_createFromFile("assets/menu/rondoudou_bg.jpg", NULL);
    if (pause->bg == NULL)
        return (put_game_error(game));
    pause->bg_spr = sfSprite_create();
    sfSprite_setTexture(pause->bg_spr, pause->bg, sfTrue);
    pause->menu = malloc(sizeof(object_t));
    set_pos(&pause->menu->pos, 648, 110);
    pause->menu->texture = 0;
    make_sprite(pause->menu, "assets/menu/menu");
    if (pause->menu->pixel == NULL)
        return (put_game_error(game));
    pause->resume = malloc(sizeof(object_t));
    set_pos(&pause->resume->pos, 716, 293);
    pause->resume->texture = 0;
    make_sprite(pause->resume, "assets/menu/play_menu");
    if (pause->resume->pixel == NULL)
        return (put_game_error(game));
    initialise_pause_menu_buttons(pause, game);
    pause->header = 1;
    intialise_pause_atk_def(pause, player);
    return (0);
}