/*
** EPITECH PROJECT, 2020
** undefined
** File description:
** init_menu.c
*/

#include <fight.h>

void init_menu(fight_t *fight)
{
    fight->bg->texture = sfTexture_createFromFile(
    "assets/menu/rondoudou_bg.jpg", NULL);
    fight->left->texture = sfTexture_createFromFile("assets/bar_b.jpg", NULL);
    fight->right->texture = sfTexture_createFromFile("assets/bar_w.jpg", NULL);
    fight->vs->texture = sfTexture_createFromFile("assets/vs.png", NULL);
    fight->bg->spr = sfSprite_create();
    fight->left->spr = sfSprite_create();
    fight->right->spr = sfSprite_create();
    fight->vs->spr = sfSprite_create();
    sfSprite_setTexture(fight->bg->spr, fight->bg->texture, sfTrue);
    sfSprite_setTexture(fight->left->spr, fight->left->texture, sfTrue);
    sfSprite_setTexture(fight->right->spr, fight->right->texture, sfTrue);
    sfSprite_setTexture(fight->vs->spr, fight->vs->texture, sfTrue);
    sfSprite_setPosition(fight->right->spr, fight->right->pos);
    sfSprite_setPosition(fight->left->spr, fight->left->pos);
    sfSprite_setPosition(fight->vs->spr, fight->vs->pos);
}

void init_pos_menu(fight_t *fight)
{
    fight->right->pos.x = 1950;
    fight->right->pos.y = 0;
    fight->right->move.y = 0;
    fight->right->move.x = -5;
    fight->left->pos.x = -300;
    fight->left->pos.y = 0;
    fight->left->move.y = 0;
    fight->left->move.x = 5;
    fight->vs->pos.x = 800;
    fight->vs->pos.y = 400;
}