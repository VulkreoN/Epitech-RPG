/*
** EPITECH PROJECT, 2021
** destroy_pause.c
** File description:
** destroy pause structures
*/

#include "rpg.h"

static void give_player_skills(pause_t *pause, player_t *player)
{
    player->attack = pause->atk;
    player->defense = pause->def;
    player->money = pause->money;
}

static void destroy_pause_object(pause_t *pause)
{
    destroy_sprite(pause->menu);
    destroy_sprite(pause->home);
    destroy_sprite(pause->info);
    destroy_sprite(pause->param);
    destroy_sprite(pause->player);
    destroy_sprite(pause->quit);
    destroy_sprite(pause->resume);
    destroy_sprite(pause->skill);
    destroy_sprite(pause->atkbtn);
    destroy_sprite(pause->defbtn);
}

void destroy_pause_menu(pause_t *pause, player_t *player)
{
    sfSprite_destroy(pause->bg_spr);
    sfTexture_destroy(pause->bg);
    sfSprite_destroy(pause->rod_spr);
    sfTexture_destroy(pause->rod);
    destroy_pause_object(pause);
    free(pause->menu);
    free(pause->home);
    free(pause->info);
    free(pause->param);
    free(pause->player);
    free(pause->quit);
    free(pause->resume);
    free(pause->skill);
    free(pause->atkbtn);
    free(pause->defbtn);
    give_player_skills(pause, player);
}