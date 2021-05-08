/*
** EPITECH PROJECT, 2021
** start
** File description:
** handle start
*/

#include "rpg.h"

int check_click_start(game_t *game, start_t *start, sfMouseButtonEvent mouse)
{
    sfVector2u start_size = sfTexture_getSize(start->new->pixel[0]);
    sfVector2f start_pos = start->new->pos;
    sfVector2u set_size = sfTexture_getSize(start->param->pixel[0]);
    sfVector2f set_pos = start->param->pos;

    game->mouse = 0;
    if (mouse.x >= start_pos.x && mouse.x <= start_pos.x + start_size.x) {
        if (mouse.y >= start_pos.y && mouse.y <= start_pos.y + start_size.y) {
            destroy_music(game);
            gameloop(game);
        }
    }
    else if (mouse.x >= set_pos.x && mouse.x <= set_pos.x + set_size.x)
        if (mouse.y >= set_pos.y && mouse.y <= set_pos.y + set_size.y)
            handle_settings(game);
    return (0);
}

int check_quit(object_t *leave, sfEvent event)
{
    sfMouseButtonEvent mouse;
    sfVector2u size = sfTexture_getSize(leave->pixel[0]);

    if (event.type != sfEvtMouseButtonPressed)
        return (1);
    mouse = event.mouseButton;
    if (mouse.x >= leave->pos.x && mouse.x <= leave->pos.x + size.x)
        if (mouse.y >= leave->pos.y && mouse.y <= leave->pos.y + size.y)
            return (0);
    return (1);
}

int analyse_start_event(start_t *start, game_t *game)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(game->window, &event)) {
        mouse_handling(game, event);
        if (event.type == sfEvtClosed
        || check_quit(start->quit, event) == 0)
            sfRenderWindow_close(game->window);
        else if (event.type == sfEvtMouseButtonReleased)
            return (check_click_start(game, start, event.mouseButton));
    } return (0);
}

static void handle_start_display(game_t *game, start_t *start)
{
    sfRenderWindow_drawSprite(game->window, start->bg_spr, NULL);
    sfRenderWindow_drawSprite(game->window, start->rdd_spr, NULL);
    if (start->played == 0) {
        sfRenderWindow_drawSprite(game->window,
        start->play_disabled_spr, NULL);
    }
    else {
        make_redirection(game, start->start);
    }
    make_redirection(game, start->new);
    make_redirection(game, start->quit);
    make_redirection(game, start->param);
    make_text_white(game->window,
    "MEGA SUPER\nRondoudou's Quest XIV\nULTRA PART V DELUXE",
    send_pos(1250, 15), 50);
}

int handle_starting(game_t *game)
{
    start_t *start;

    if (game->error == 1)
        return (1);
    start = malloc(sizeof(start_t));
    initialise_start(start, game);
    handle_starting_cinematic(game, start);
    assign_music(game, 0);
    while (sfRenderWindow_isOpen(game->window)) {
        sfRenderWindow_clear(game->window, sfBlack);
        handle_start_display(game, start);
        analyse_start_event(start, game);
        sfRenderWindow_display(game->window);
    }
    destroy_start(start);
    free(start);
    return (0);
}