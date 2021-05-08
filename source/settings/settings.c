/*
** EPITECH PROJECT, 2021
** settings
** File description:
** handle settings
*/

#include "rpg.h"

void handle_play_pause(game_t *game, settings_t *param)
{
    if (game->play_pause == 0) {
        game->play_pause = 1;
        change_sprite(param->play, 3);
        sfMusic_pause(game->music);
    } else {
        game->play_pause = 0;
        change_sprite(param->play, 0);
        sfMusic_play(game->music);
    }
}

void handle_low_volum(game_t *game)
{
    if (game->volum > 0)
        sfMusic_setVolume(game->music, (game->volum -= 10));
}

void check_settings_click(game_t *game, settings_t *param,
sfMouseButtonEvent mouse)
{
    sfVector2u size = sfTexture_getSize(param->play->pixel[0]);
    sfVector2f play_pos = param->play->pos;
    sfVector2f high_pos = param->high->pos;
    sfVector2f low_pos = param->low->pos;

    game->mouse = 0;
    if (mouse.y >= 0 && mouse.y <= play_pos.y + size.y
    && mouse.x >= play_pos.x && mouse.x <= low_pos.x + size.x) {
        if (mouse.x <= play_pos.x + size.x)
            handle_play_pause(game, param);
        else if (mouse.x >= high_pos.x && mouse.x <= high_pos.x + size.x &&
        game->volum < 100)
            sfMusic_setVolume(game->music, (game->volum += 10));
        else
            handle_low_volum(game);
    } else if (mouse.y >= 0 && mouse.x >= 0 &&
    mouse.y <= 200 && mouse.x <= 200)
        param->leave = 1;
}

void check_settings_event(game_t *game, settings_t *param)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(game->window, &event)) {
        mouse_handling(game, event);
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
        else if (event.type == sfEvtMouseButtonReleased)
            check_settings_click(game, param, event.mouseButton);
    }
}

void handle_settings(game_t *game)
{
    settings_t *param;

    param = malloc(sizeof(settings_t));
    initialise_settings(param, game);
    if (game->error == 1)
        return;
    param->leave = 0;
    while (sfRenderWindow_isOpen(game->window) && param->leave == 0) {
        sfRenderWindow_clear(game->window, sfBlack);
        sfRenderWindow_drawSprite(game->window, param->bg_spr, NULL);
        make_redirection(game, param->back);
        make_redirection(game, param->high);
        make_redirection(game, param->low);
        make_play_pause_redirection(game, param);
        check_settings_event(game, param);
        display_how_to_play_menu(game->window);
        sfRenderWindow_display(game->window);
    }
}