/*
** EPITECH PROJECT, 2021
** main
** File description:
** myRPG
*/

#include "fight.h"
#include "../include/taya.h"
#include "rpg.h"

int main(void)
{
    sfVideoMode mode = {1920, 1080, 32};
    game_t *game;

    game = malloc(sizeof(game_t));
    game->window = sfRenderWindow_create(mode,
    "MEGA SUPER Rondoudou's Quest XIV ULTRA PART V DELUXE",
    sfResize | sfClose, NULL);
    if (!game->window)
        return (84);
    initialise_game(game);
    handle_starting(game);
    sfRenderWindow_destroy(game->window);
    destroy_game(game);
    if (game->error == 1) {
        free(game);
        write(2, "Missing assets!\n", 16);
        return (84);
    }
    free(game);
    return (0);
}