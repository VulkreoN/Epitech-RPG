/*
** EPITECH PROJECT, 2021
** music
** File description:
** handle music
*/

#include "taya.h"
#include "rpg.h"

void destroy_music(game_t *game)
{
    if (game->music != NULL)
        sfMusic_destroy(game->music);
    game->music = NULL;
}

void assign_music(game_t *game, int number)
{
    char *song[] = {"assets/menu/start.ogg",
    "assets/menu/pause.ogg",
    "assets/menu/game_over.ogg",
    "assets/menu/omaewa.ogg",
    "assets/theme.ogg"};

    if (game->music == NULL) {
        game->music = sfMusic_createFromFile(song[number]);
        if (game->play_pause == 0)
            sfMusic_play(game->music);
        sfMusic_setVolume(game->music, game->volum);
        sfMusic_setLoop(game->music, sfTrue);
    }
}