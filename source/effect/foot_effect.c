/*
** EPITECH PROJECT, 2021
** foot_effect
** File description:
** handle foot effect
*/

#include "rpg.h"
#include <math.h>

static void position_foot_effect(player_t *player, sfSprite *spr, int who)
{
    sfVector2f tmp = player->foot_pos[who];
    const float rotation[] = {180, 0, 270, 90};

    switch (player->foot_dir[who]) {
        case 0:
            tmp.x -= (15 * who) + 25;
            break;
        case 1:
            tmp.x += (15 * who) + 10;
            break;
        case 2:
            tmp.y -= (15 * who) + 30;
            break;
        default:
            tmp.y += (15 * who) + 10;
            break;
    }
    sfSprite_setRotation(spr, rotation[player->foot_dir[who]]);
    sfSprite_setPosition(spr, tmp);
}

void make_foot_spr(game_t *game, player_t *player, sfTexture *foot, int who)
{
    sfVector2f pos;
    sfSprite *spr = NULL;

    if (player->foot_dir[who] == -1)
        return;
    spr = sfSprite_create();
    sfSprite_setTexture(spr, foot, sfTrue);
    position_foot_effect(player, spr, who);
    sfRenderWindow_drawSprite(game->window, spr, NULL);
    pos = sfSprite_getPosition(spr);
    if (player->foot_dir[who] == 1 || player->foot_dir[who] == 2) {
        if (player->foot_dir[who] == 1)
            pos.x += 20;
        pos.y -= 2;
    }
    sfSprite_setPosition(spr, send_pos(pos.x - 12, pos.y - 5));
    sfRenderWindow_drawSprite(game->window, spr, NULL);
    sfSprite_destroy(spr);
}

void remove_all_foot(player_t *player, map_t *map)
{
    if (player->foot_index != map->indexScreen) {
        player->foot_dir[0] = -1;
        player->foot_dir[1] = -1;
        player->foot_dir[2] = -1;
        player->foot_index = map->indexScreen;
    }
}

void display_foot_effect(game_t *game, player_t *player)
{
    int sec = player->foot_time.time.microseconds / 1000000.0;
    int inc = 2;
    sfTexture **foot;

    foot = malloc(sizeof(sfTexture *) * (4));
    foot[0] = sfTexture_createFromFile("assets/foot/foot1.png", NULL);
    foot[1] = sfTexture_createFromFile("assets/foot/foot2.png", NULL);
    foot[2] = sfTexture_createFromFile("assets/foot/foot3.png", NULL);
    foot[3] = NULL;
    if (player->isMoving == sfFalse && sec % 3 == 0) {
        for (; inc >= 0 && player->foot_dir[inc] == -1; inc--);
        player->foot_dir[inc] = -1;
    }
    for (int inc = 0; inc < 3; inc++) {
        make_foot_spr(game, player, foot[inc], inc);
        sfTexture_destroy(foot[inc]);
    }
    free(foot);
}

void make_foot_effect(player_t *player)
{
    player->foot_pos[2] = player->foot_pos[1];
    player->foot_pos[1] = player->foot_pos[0];
    player->foot_pos[0].x = player->pos.x + 25;
    player->foot_pos[0].y = player->pos.y + 42;
    if ((player->foot_dir[0] != player->direction)
    && player->foot_dir[0] != -1) {
        player->foot_dir[0] = -1;
        player->foot_dir[1] = -1;
        player->foot_dir[2] = -1;
    } else if (player->isMoving && ((player->cell.x != player->last_cell.x)
    || (player->cell.y != player->last_cell.y))) {
        player->foot_dir[2] = player->foot_dir[1];
        player->foot_dir[1] = player->foot_dir[0];
        player->foot_dir[0] = player->direction;
    }
}