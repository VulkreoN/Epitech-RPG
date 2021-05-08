/*
** EPITECH PROJECT, 2020
** undefined
** File description:
** check_event.c
*/

#include <fight.h>
#include <taya.h>

void check_fight_event(fight_t *fight, sfEvent event, sfRenderWindow *window)
{
    change_arrow_pos(event, fight->arrow);
    if (!fight->turn->turn)
        if (event.type == sfEvtKeyPressed &&
        event.key.code == sfKeyReturn)
            hit_opponent(fight, fight->arrow, window);
}

void event_loop(fight_t *fight, sfRenderWindow *window)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed ||
        (event.type == sfEvtKeyPressed
        && event.key.code == sfKeyQ)) {
            sfRenderWindow_close(window);
        }
        if ((event.type == sfEvtKeyPressed
        && event.key.code == sfKeyEscape) && fight->intro != 2) {
            fight->intro = 2;
            start_fight(fight);
        }
        if (fight->intro == 2)
            check_fight_event(fight, event, window);
    }
}