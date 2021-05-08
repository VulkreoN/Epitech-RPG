/*
** EPITECH PROJECT, 2021
** game
** File description:
** handle game functions
*/

#include "rpg.h"
#include "fight.h"
#include "../include/taya.h"

int put_game_error(game_t *game)
{
    game->error = 1;
    return (1);
}

static void display_in_game(game_t *game, player_t *player, map_t *map_t)
{
    sfVector2f size = {2, 2};

    handle_map(game, player, map_t);
    if (map_t->indexScreen == 1 || map_t->indexScreen == 2)
        print_map(map_t, game);
    print_sprite("assets/perso.png", player, size, game->window);
    player->foot_time.time = sfClock_getElapsedTime(player->foot_time.clock);
    if (player->foot_dir[0] != -1)
        display_foot_effect(game, player);
    if (map_t->indexScreen == 2 || map_t->indexScreen == 3)
        create_wind_effect(map_t, game->window);
    if (map_t->indexScreen == 1)
        print_pnj(game->window, map_t->pnj_t, &map_t->indexScreen);
    handle_npc(game, player, map_t);
    if (game->adv.jerome == 1)
        handle_end_game(game);
}

void gameloop(game_t *game)
{
    sfEvent event;
    t_timeManager timeManager = {0};
    map_t map_t = {0};
    player_t player_t = {0};

    assign_music(game, 4);
    initialise_game_config(&player_t, &map_t, &timeManager, game);
    while (sfRenderWindow_isOpen(game->window)) {
        if (game->error == 1)
            return;
        sfRenderWindow_clear(game->window, sfBlack);
        initi_time(&timeManager, 1);
        move_camera(&player_t, &map_t);
        move_player(&player_t, game, &timeManager, &map_t);
        display_in_game(game, &player_t, &map_t);
        interact(game, &player_t, &map_t);
        check_pause_in_game(game, &player_t, event);
        sfRenderWindow_display(game->window);
    } free(player_t.foot_dir);
    free(player_t.foot_pos);
    create_save(&player_t, game, &map_t);
}