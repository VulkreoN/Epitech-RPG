/*
** EPITECH PROJECT, 2021
** pause_buttons
** File description:
** baute buttons redirections
*/

#include "rpg.h"

static void handle_menu_headers(pause_t *pause)
{
    if (pause->info->texture == 2) {
        pause->header = 1;
        change_sprite(pause->menu, 0);
    }
    if (pause->player->texture == 2) {
        pause->header = 0;
        change_sprite(pause->menu, 1);
    }
    if (pause->skill->texture == 2) {
        pause->header = 2;
        change_sprite(pause->menu, 2);
    }
}

static void handle_pause_param_menu(game_t *game, pause_t *pause)
{
    if (pause->home->texture == 2) {
        destroy_music(game);
        handle_starting(game);
    }
    else if (pause->param->texture == 2)
        handle_settings(game);
    handle_menu_headers(pause);
    if (pause->atkbtn->texture == 2 && pause->atk <= 70
    && pause->money >= (pause->atk / 10) * 50) {
        pause->money -= (pause->atk / 10) * 50;
        pause->atk += 10;
    } else if (pause->defbtn->texture == 2 && pause->def <= 70
    && pause->money >= (pause->def / 10) * 50) {
        pause->money -= (pause->def / 10) * 50;
        pause->def += 10;
    }
}

void handle_escape_pause(pause_t *pause, sfEvent event)
{
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)
        pause->leave = 1;
}

void handle_pause_buttons(game_t *game, pause_t *pause)
{
    if (pause->quit->texture == 2)
        sfRenderWindow_close(game->window);
    else if (pause->resume->texture == 2)
        pause->leave = 1;
    handle_pause_param_menu(game, pause);
}