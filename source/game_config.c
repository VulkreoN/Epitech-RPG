/*
** EPITECH PROJECT, 2021
** game_config
** File description:
** configurate game structure
*/

#include "rpg.h"
#include "fight.h"

void initialise_player_config(player_t *player)
{
    player->cell.x = 18.00;
    player->cell.y = 12.00;
    player->attack = 10;
    player->defense = 10;
    player->money = 100;
    set_pos(&player->pos, 864, 585);
    player->foot_pos = malloc(sizeof(sfVector2f) * (4));
    player->foot_dir = malloc(sizeof(int) * (4));
    for (int inc = 0; inc < 3; inc++) {
        player->foot_dir[inc] = -1;
        player->foot_pos[inc].x = -1;
        player->foot_pos[inc].y = -1;
    }
    player->foot_dir[3] = -1;
    player->foot_pos[3].x = -1;
    player->foot_pos[3].y = -1;
    player->foot_time.clock = sfClock_create();
    player->talk = sfFalse;
    player->foot_index = 1;
    player->lily = 0;
    player->guard = 0;
}

void initialise_game_config(player_t *player, map_t *map,
t_timeManager *timeManager, game_t *game)
{
    initialise_player_config(player);
    map->indexScreen = 1;
    initi_time(timeManager, 0);
    map->wind = 0;
    if (game->save == 1)
        load_save(game);
    give_tmp(game, map, player);
    init_map(map);
    make_game_first_scene(game);
}

void destroy_game(game_t *game)
{
    destroy_sprite(game->pause);
    if (game->music != NULL) {
        sfMusic_destroy(game->music);
    }
    free(game->pause);
}

static void initialise_game_default_value(game_t *game)
{
    game->mouse = 0;
    game->play_pause = 0;
    game->volum = 50;
    game->music = NULL;
    game->error = 0;
    game->talk = 0;
    game->adv.covid = 0;
    game->adv.jerome = 0;
    game->adv.maxence = 0;
    game->adv.pops = 0;
    game->adv.rondodu = 0;
    game->adv.wise = 0;
    game->adv.rondoudou = 0;
    game->wise = 0;
    game->intro = 0;
    initialise_game_tmp(game);
}

int initialise_game(game_t *game)
{
    srand(2147483647);
    sfRenderWindow_setFramerateLimit(game->window, 30);
    initialise_game_default_value(game);
    game->pause = malloc(sizeof(object_t));
    set_pos(&game->pause->pos, 10, 10);
    game->pause->texture = 0;
    make_sprite(game->pause, "assets/menu/pause");
    if (game->pause->pixel == NULL)
        return (put_game_error(game));
    return (0);
}