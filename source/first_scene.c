/*
** EPITECH PROJECT, 2021
** first_scene
** File description:
** handle game first scene
*/

#include "rpg.h"

static const char *dialog[] = {
    "*Hugo se reveille dans son lit*",
    "Hugo: zzzzzzzz",
    "*Hugo ouvre les yeux et remarque quelque chose de bizarre*",
    "Hugo: ...",
    "Hugo: Ptdr t es ki ?",
    ("Rondodu: Je suis Rondodu, ton amour de toujours,"
    " tu ne te souviens pas d hier soir ?"),
    ("Hugo: Je n'ai toujours connu qu'un amour, et c'est pour Rondoudou"
    " chromatique,\npas pour un Rondodu ou je ne sais quelle tocardise!"),
    ("Rondodu: Je vais te laisser te reveiller,"
    " je vais chercher les croissants"),
    "*Rondodu sort de la maison*",
    ("Hugo: Mais ou est le vrai Rondoudou?\nMon amour de toujours"
    " n a pas pu m abandonner comme ca!\nPas aujourd hui!!!"),
    "*Mission principale: Trouver le vrai Rondoudou !*",
    "Hugo: J'ai un petit creux, je devrais aller acheter un truc a manger",
    "*Mission secondaire: Aller dans un supermarche*"
};

static int print_rondoudou(game_t *game)
{
    sfTexture *pixel = NULL;
    sfSprite *spr = NULL;

    pixel = sfTexture_createFromFile("assets/npc/rondodu.png", NULL);
    if (pixel == NULL)
        return (put_game_error(game));
    spr = sfSprite_create();
    sfSprite_setTexture(spr, pixel, sfTrue);
    if (game->intro == 2 || game->intro == 8)
        sfSprite_setPosition(spr, send_pos(-50, 400));
    else
        sfSprite_setPosition(spr, send_pos(100, 400));
    if (game->intro == 2)
        sfSprite_setRotation(spr, 30);
    sfRenderWindow_drawSprite(game->window, spr, NULL);
    sfTexture_destroy(pixel);
    sfSprite_destroy(spr);
    return (0);
}

static void print_first_scene(game_t *game)
{
    int text_size = 25;

    if (game->intro == 10)
        text_size += 15;
    else if (game->intro == 12)
        text_size += 10;
    print_dia("assets/dia.jpg", send_pos(0, 763), game->window);
    make_text(game->window, (char *)dialog[game->intro],
    send_pos(300, 800), text_size);
    if (game->intro >= 2 && game->intro <= 8)
        print_rondoudou(game);
}

static void handle_first_scene_event(game_t *game)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(game->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
        else if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEnter)
            game->intro += 1;
    }
}

void make_game_first_scene(game_t *game)
{
    while (sfRenderWindow_isOpen(game->window) && game->intro != 13) {
        if (game->error == 1)
            return;
        sfRenderWindow_clear(game->window, sfBlack);
        print_first_scene(game);
        sfRenderWindow_display(game->window);
        handle_first_scene_event(game);
    }
}