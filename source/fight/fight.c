/*
** EPITECH PROJECT, 2020
** undefined
** File description:
** fight.c
*/

#include <fight.h>
#include "rpg.h"

void move_flash(fight_t *fight)
{
    for (int i = 0; i<fight->nb_flash; i++) {
        fight->flash[i]->move.x = 100;
        fight->flash[i]->move.y = 0;
        sfRectangleShape_move(fight->flash[i]->bar, fight->flash[i]->move);
        fight->flash[i]->pos =
        sfRectangleShape_getPosition(fight->flash[i]->bar);
        if (fight->flash[i]->pos.x >= 1920)
            fight->flash[i]->pos.x = 0;
        sfRectangleShape_setPosition(fight->flash[i]->bar,
        fight->flash[i]->pos);
    }
}

void make_fight(fight_t *fight)
{
    fight->time = sfClock_getElapsedTime(fight->clock);
    fight->sec = sfTime_asSeconds(fight->time);
    if (!fight->intro)
        make_intro(fight);
    if (fight->intro == 1) {
        move_flash(fight);
        if (fight->sec >= 5)
            start_fight(fight);
        if (fight->sec >= 5)
            sfClock_restart(fight->clock);
    }
    if (fight->intro == 2) {
        change_life_text(fight->hugo->hp);
        make_anim_fight(fight);
    }
}

int fight_loop(fight_t *fight, sfRenderWindow *window)
{
    init_fight_loop(fight);
    while (sfRenderWindow_isOpen(window)) {
        make_fight(fight);
        event_loop(fight, window);
        display_ressources(fight, window);
        if (fight->hugo->hp->life <= 0)
            return (2);
        if (fight->opponent->hp->life <= 0)
            return (1);
        if (fight->turn->turn == 2)
            fight->turn->turn = 0;
        if (fight->turn->turn == 1)
            take_hit(fight, fight->hugo,
            fight->opponent_atk[fight->opponent->attack++ % 4].damage, window);
    }
    return (0);
}

void start_fight_with_music(game_t *game, player_t *player, void (*opponent)
(game_t *, player_t *))
{
    destroy_music(game);
    opponent(game, player);
    assign_music(game, 4);
}