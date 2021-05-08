/*
** EPITECH PROJECT, 2020
** undefined
** File description:
** combat.c
*/

#include <fight.h>
#include <taya.h>

void make_damage_anim(fight_t *fight, perso_t *perso, sfClock *clock,
int damage)
{
    sfTime time;
    float sec;
    time = sfClock_getElapsedTime(clock);
    sec = sfTime_asSeconds(time);
    if (sec > 0.05) {
        perso->hp->bar->size.x -= damage/30.0;
        update_bar(perso->hp->bar, 0, 271);
        perso->hp->life = perso->hp->bar->size.x;
        if (!my_strcmp(perso->name, fight->hugo->name)) {
            fight->turn->turn = 2;
            make_opponent_hit_text(fight->turn, fight->opponent->name,
            fight->opponent_atk[(fight->opponent->attack-1)%4].action);
            change_life_text(perso->hp);
        }
        else {
            fight->turn->turn = 1;
            make_hugo_hit_text(fight->turn, "Hugo");
        }
        sfClock_restart(clock);
    }
}

void take_hit(fight_t *fight, perso_t *perso, int damage,
sfRenderWindow *window)
{
    float prev_hp = perso->hp->bar->size.x;
    sfClock *clock = sfClock_create();

    while (prev_hp-damage < perso->hp->bar->size.x) {
        if (perso->hp->bar->size.x <= 0)
            break;
        make_damage_anim(fight, perso, clock, damage);
        display_ressources(fight, window);
    }
    sfClock_destroy(clock);
}

void make_heal_anim(perso_t *perso, sfClock *clock, int heal)
{
    sfTime time;
    float sec;
    time = sfClock_getElapsedTime(clock);
    sec = sfTime_asSeconds(time);
    if (sec > 0.08) {
        perso->hp->bar->size.x += heal/10;
        update_bar(perso->hp->bar, 0, 271);
        perso->hp->life = perso->hp->bar->size.x;
        if (!my_strcmp(perso->name, "Hugo"))
            change_life_text(perso->hp);
        sfClock_restart(clock);
    }
}

void heal_perso(fight_t *fight, perso_t *perso, int heal,
sfRenderWindow *window)
{
    float prev_hp = perso->hp->bar->size.x;
    sfClock *clock = sfClock_create();

    while (prev_hp+heal > perso->hp->bar->size.x) {
        if (perso->hp->bar->size.x >= 271)
            break;
        make_heal_anim(perso, clock, heal);
        display_ressources(fight, window);
    }
    sfClock_destroy(clock);
}