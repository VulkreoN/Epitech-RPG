/*
** EPITECH PROJECT, 2021
** intro_movement
** File description:
** handle sprite movement in intro
*/

#include "rpg.h"

static void handle_intro_buttons(start_t *start, intro_t *intro)
{
    if (start->param->pos.x != 0 && intro->sec >= 17) {
        set_pos(&(start->new->pos),
        start->new->pos.x - 8, start->new->pos.y);
        set_pos(&(start->param->pos),
        start->param->pos.x - 8, start->param->pos.y);
        set_pos(&(start->quit->pos),
        start->quit->pos.x - 8, start->quit->pos.y);
        sfSprite_setPosition(start->new->spr, start->new->pos);
        sfSprite_setPosition(start->param->spr, start->param->pos);
        sfSprite_setPosition(start->quit->spr, start->quit->pos);
    }
    if (start->param->pos.x != 0 && start->played != 0 && intro->sec >= 17) {
        set_pos(&(start->start->pos),
        start->start->pos.x - 8, start->start->pos.y);
        sfSprite_setPosition(start->start->spr, start->start->pos);
    }
    else if (start->param->pos.x != 0 && intro->sec >= 17) {
        sfSprite_setPosition(start->play_disabled_spr,
        send_pos(start->quit->pos.x, 500));
    }
}

static void make_intro_rotation(intro_t *intro)
{
    if (intro->sec < 15.2)
        sfSprite_setRotation(intro->rdd_spr, intro->angle);
    if (intro->sec >= 15.2 && intro->sec <= 16) {
        set_pos(&intro->wan_pos, intro->wan_pos.x, intro->wan_pos.y + 100);
        sfSprite_setRotation(intro->wan_spr, intro->angle);
        if (intro->sec <= 15.6)
            intro->angle = sfSprite_getRotation(intro->wan_spr) - 5;
    }
    else if (intro->sec >= 16.0 && intro->sec <= 16.5) {
        intro->angle = sfSprite_getRotation(intro->rdd_spr) + 5;
        set_pos(&intro->rdd_pos, intro->rdd_pos.x, intro->rdd_pos.y + 15);
        sfSprite_setRotation(intro->rdd_spr, intro->angle);
    }
}

static void handle_intro_position(intro_t *intro)
{
    if (intro->sec >= 1.5 && intro->sec <= 4)
        set_pos(&intro->wan_pos, intro->wan_pos.x, intro->wan_pos.y + 10);
    else if (intro->sec >= 6 && intro->sec <= 7.5)
        set_pos(&intro->rdd_pos, intro->rdd_pos.x + 10, intro->rdd_pos.y);
    if (intro->sec >= 8.5 && intro->sec <= 10.4) {
        intro->angle = sfSprite_getRotation(intro->rdd_spr) + 5;
        set_pos(&intro->rdd_pos, intro->rdd_pos.x + 3, intro->rdd_pos.y - 6);
    }
    else if (intro->sec >= 10.4 && intro->sec <= 11)
        set_pos(&intro->rdd_pos, intro->rdd_pos.x + 3, intro->rdd_pos.y + 6);
    if (intro->sec >= 16.5 && intro->sec <= 30) {
        set_pos(&intro->rdd_pos, intro->rdd_pos.x + 1.7, intro->rdd_pos.y);
    }
    else if (intro->sec >= 30 && intro->sec <= 32) {
        set_pos(&intro->rdd_pos, intro->rdd_pos.x - 4, intro->rdd_pos.y - 8);
    }
}

static void change_intro_music(game_t *game, intro_t *intro)
{
    if (intro->sec >= 11 && intro->sec <= 11.1) {
        intro->duration = sfMusic_getDuration(game->music);
        destroy_music(game);
        assign_music(game, 3);
    }
    if (intro->sec >= 15.2 && intro->sec <= 15.3) {
        destroy_music(game);
        assign_music(game, 0);
        sfMusic_setPlayingOffset(game->music, intro->duration);
    }
}

void handle_intro_movement(game_t *game, intro_t *intro, start_t *start)
{
    handle_intro_buttons(start, intro);
    make_intro_rotation(intro);
    handle_intro_position(intro);
    change_intro_music(game, intro);
    sfSprite_setPosition(intro->rdd_spr, intro->rdd_pos);
    sfSprite_setPosition(intro->wan_spr, intro->wan_pos);
    if (intro->sec >= 33)
        intro->skip = 2;
}