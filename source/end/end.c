/*
** EPITECH PROJECT, 2021
** end
** File description:
** handle end_game
*/

#include "rpg.h"

static void display_rondoudou_dab(game_t *game, float y)
{
    sfTexture *pixel = NULL;
    sfSprite *spr = NULL;

    pixel = sfTexture_createFromFile("assets/end.png", NULL);
    spr = sfSprite_create();
    sfSprite_setTexture(spr, pixel, sfTrue);
    sfSprite_setPosition(spr, send_pos(650, 1080 + 1200 - y));
    sfRenderWindow_drawSprite(game->window, spr, NULL);
    sfTexture_destroy(pixel);
    sfSprite_destroy(spr);
}

static void check_end_event(game_t *game)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(game->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
    }
}

static void handle_end_game_display(game_t *game, sfTime time)
{
    float y = 100.0 + (time.microseconds / 20000.0);
    char *press = "Press ESCAPE to skip credits";
    char *thanks = "Merci d'avoir joue !";

    if (y >= 2200.0)
        y = 2200.0;
    display_rondoudou_dab(game, y);
    handle_copyright_end(game, y);
    handle_hakim_end(game, y);
    handle_maxence_end(game, y);
    handle_joris_end(game, y);
    handle_johann_end(game, y);
    print_text(game->window, press, send_pos(0, 0), sfRed);
    make_text_white(game->window, thanks, send_pos(730, 2980 - y), 40);
}

void handle_end_game(game_t *game)
{
    sfTime time;
    sfClock *clock;

    destroy_music(game);
    assign_music(game, 0);
    clock = sfClock_create();
    time = sfClock_getElapsedTime(clock);
    while (!sfKeyboard_isKeyPressed(sfKeyEscape)
    && sfRenderWindow_isOpen(game->window) &&
    (time.microseconds / 20000.0) <= 2190.0) {
        if (game->error == 1)
            return;
        time = sfClock_getElapsedTime(clock);
        sfRenderWindow_clear(game->window, sfBlack);
        handle_end_game_display(game, time);
        sfRenderWindow_display(game->window);
        check_end_event(game);
    }
    destroy_music(game);
    handle_starting(game);
}