/*
** EPITECH PROJECT, 2021
** start_cinematic
** File description:
** handle starting cinematic
*/

#include "rpg.h"

static int analyse_intro_event(intro_t *intro, game_t *game)
{
    sfEvent event;

    intro->sec = sfClock_getElapsedTime(intro->time).microseconds / 1000000.0;
    while (sfRenderWindow_pollEvent(game->window, &event)) {
        mouse_handling(game, event);
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
        else if (event.type == sfEvtKeyPressed
        && event.key.code == sfKeyEscape)
            intro->skip = 1;
    } return (0);
}

static void handle_intro_display(game_t *game, intro_t *intro, start_t *start)
{
    if (intro->wan_pos.y + 408 >= 0 && intro->wan_pos.y <= 1080)
        sfRenderWindow_drawSprite(game->window, intro->wan_spr, NULL);
    if (intro->sec >= 6)
        sfRenderWindow_drawSprite(game->window, intro->rdd_spr, NULL);
    if (intro->sec >= 17) {
        sfRenderWindow_drawSprite(game->window, start->new->spr, NULL);
        sfRenderWindow_drawSprite(game->window, start->param->spr, NULL);
        sfRenderWindow_drawSprite(game->window, start->quit->spr, NULL);
    }
    handle_intro_movement(game, intro, start);
    if (start->played != 0 && intro->sec >= 17)
        sfRenderWindow_drawSprite(game->window, start->start->spr, NULL);
    else if (intro->sec >= 17)
        sfRenderWindow_drawSprite(game->window,
        start->play_disabled_spr, NULL);
}

void handle_starting_cinematic(game_t *game, start_t *start)
{
    intro_t *intro;

    intro = malloc(sizeof(intro_t));
    initialise_intro(game, intro);
    if (game->error == 1) {
        destroy_intro(intro, start);
        return;
    }
    assign_music(game, 0);
    while (sfRenderWindow_isOpen(game->window) && intro->skip == 0) {
        sfRenderWindow_clear(game->window, sfBlack);
        sfRenderWindow_drawSprite(game->window, intro->bg_spr, NULL);
        handle_intro_display(game, intro, start);
        make_text(game->window, "Press ESC to skip", send_pos(720, 900), 50);
        sfRenderWindow_display(game->window);
        analyse_intro_event(intro, game);
    }
    destroy_music(game);
    destroy_intro(intro, start);
}