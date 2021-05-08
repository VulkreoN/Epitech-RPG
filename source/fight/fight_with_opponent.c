/*
** EPITECH PROJECT, 2020
** fight
** File description:
** fight_with_opponent.c
*/

#include "fight.h"
#include "rpg.h"
#include <taya.h>

void fight_with_rondodu(game_t *game, player_t *player)
{
    int ret = 0;
    sfMusic *song = sfMusic_createFromFile("assets/menu/pause.ogg");
    fight_t *fight;

    fight = malloc(sizeof(fight_t));
    if (!fight)
        return;
    assign_music_for_fight(song);
    init_fight(fight, player);
    init_hugo(fight);
    init_opponent(fight, "Rondodu");
    ret = fight_loop(fight, game->window);
    if (ret == 1) {
        game->adv.rondodu = 1;
        player->money += 200;
    }
    else if (ret == 2)
        game->adv.rondodu = 2;
    sfMusic_destroy(song);
    destroy_menus(fight);
}

void fight_with_miel_pops(game_t *game, player_t *player)
{
    int ret = 0;
    sfMusic *song = sfMusic_createFromFile("assets/menu/pause.ogg");
    fight_t *fight;

    fight = malloc(sizeof(fight_t));
    if (!fight)
        return;
    assign_music_for_fight(song);
    init_fight(fight, player);
    init_hugo(fight);
    init_opponent(fight, "Miel_Pops");
    ret = fight_loop(fight, game->window);
    if (ret == 1) {
        game->adv.pops = 1;
        player->money += 100;
    }
    else if (ret == 2)
        game->adv.pops = 2;
    player->guard = 1;
    sfMusic_destroy(song);
    destroy_menus(fight);
}

void fight_with_jerome(game_t *game, player_t *player)
{
    int ret = 0;
    sfMusic *song = sfMusic_createFromFile("assets/menu/pause.ogg");
    fight_t *fight;

    fight = malloc(sizeof(fight_t));
    if (!fight)
        return;
    assign_music_for_fight(song);
    init_fight(fight, player);
    init_hugo(fight);
    init_opponent(fight, "Jerome");
    ret = fight_loop(fight, game->window);
    if (ret == 1) {
        game->adv.jerome = 1;
        player->money += 150;
    }
    else if (ret == 2)
        game->adv.jerome = 2;
    sfMusic_destroy(song);
    destroy_menus(fight);
}

void fight_with_maxence(game_t *game, player_t *player)
{
    int ret = 0;
    sfMusic *song = sfMusic_createFromFile("assets/menu/pause.ogg");
    fight_t *fight;

    fight = malloc(sizeof(fight_t));
    if (!fight)
        return;
    assign_music_for_fight(song);
    init_fight(fight, player);
    init_hugo(fight);
    init_opponent(fight, "Maxence");
    ret = fight_loop(fight, game->window);
    if (ret == 1) {
        game->adv.maxence = 1;
        player->money += 50;
    }
    else if (ret == 2)
        game->adv.maxence = 2;
    sfMusic_destroy(song);
    destroy_menus(fight);
}

void fight_with_covid(game_t *game, player_t *player)
{
    sfMusic *song = sfMusic_createFromFile("assets/menu/pause.ogg");
    int ret = 0;
    fight_t *fight;

    fight = malloc(sizeof(fight_t));
    if (!fight)
        return;
    assign_music_for_fight(song);
    init_fight(fight, player);
    init_hugo(fight);
    init_opponent(fight, "Le_covid");
    ret = fight_loop(fight, game->window);
    if (ret == 1) {
        game->adv.covid = 1;
        player->money += 100;
    }
    else if (ret == 2)
        game->adv.covid = 2;
    sfMusic_destroy(song);
    destroy_menus(fight);
}