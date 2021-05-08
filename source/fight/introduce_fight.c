/*
** EPITECH PROJECT, 2020
** undefined
** File description:
** introduce_fight.c
*/

#include <fight.h>

void make_anim_fight(fight_t *fight)
{
    if (fight->hugo->change > 8)
        fight->hugo->change = 0;
    if (fight->opponent->change > 2)
        fight->opponent->change = 0;
    if (fight->sec >= 0.2) {
        sfSprite_setTexture(fight->hugo->spr,
        fight->hugo->texture[fight->hugo->change++], sfTrue);
        sfSprite_setTexture(fight->opponent->spr,
        fight->opponent->texture[fight->opponent->change++], sfTrue);
    }
    if (fight->sec >= 0.2)
        sfClock_restart(fight->clock);
}

void start_fight(fight_t *fight)
{
    fight->intro = 2;
    sfTexture_destroy(fight->bg->texture);
    fight->bg->texture =
    sfTexture_createFromFile("assets/background_fight.png", NULL);
    sfSprite_setTexture(fight->bg->spr, fight->bg->texture, sfTrue);
}

void make_intro(fight_t *fight)
{
    if (move_menu_right(fight->left, 820, 40/(fight->sec+1))
    & move_menu_left(fight->right, 820, 40/((fight->sec)+1)))
        fight->intro = 1;
}