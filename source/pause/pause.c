/*
** EPITECH PROJECT, 2021
** pause
** File description:
** handle pause
*/

#include "rpg.h"

static void display_pause(game_t *game, pause_t *pause)
{
    sfRenderWindow_clear(game->window, sfBlack);
    sfRenderWindow_drawSprite(game->window, pause->bg_spr, NULL);
    sfRenderWindow_drawSprite(game->window, pause->menu->spr, NULL);
    handle_pause_headers_display(game, pause);
    sfRenderWindow_display(game->window);
}

static void check_pause_key_released(game_t *game, sfEvent event)
{
    if (event.key.type == sfEvtKeyReleased)
        game->key = sfTrue;
    else
        game->key = sfFalse;
}

static int analyse_pause_event(pause_t *pause, game_t *game)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(game->window, &event)) {
        mouse_handling(game, event);
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
        else if (event.type == sfEvtMouseButtonReleased)
            handle_pause_buttons(game, pause);
        handle_escape_pause(pause, event);
    }
    return (0);
}

int handle_pause(game_t *game, player_t *player)
{
    pause_t *pause;

    pause = malloc(sizeof(pause_t));
    if (pause == NULL)
        return (put_game_error(game));
    initialise_pause(pause, game, player);
    pause->leave = 0;
    assign_music(game, 1);
    while (sfRenderWindow_isOpen(game->window) && pause->leave == 0) {
        display_pause(game, pause);
        analyse_pause_event(pause, game);
    }
    destroy_music(game);
    destroy_pause_menu(pause, player);
    free(pause);
    return (0);
}

void check_pause_in_game(game_t *game, player_t *player, sfEvent event)
{
    while (sfRenderWindow_pollEvent(game->window, &event)) {
        mouse_handling(game, event);
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
        else if (game->pause->texture == 2 ||
        (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)) {
            destroy_music(game);
            handle_pause(game, player);
            assign_music(game, 4);
        }
        check_pause_key_released(game, event);
    }
    make_redirection(game, game->pause);
}