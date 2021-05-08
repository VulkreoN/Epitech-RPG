/*
** EPITECH PROJECT, 2020
** undefined
** File description:
** init_bar.c
*/

#include <fight.h>

void init_bg_bar(bar_t *bar, int x, int y)
{
    sfIntRect rect;
    rect.width = 1920;
    rect.height = 1080;
    rect.top = 0;
    rect.left = 0;
    bar->bar = sfRectangleShape_create();
    bar->pos.x = x;
    bar->pos.y = y;
    bar->size.x = 1920;
    bar->size.y = 150;
    bar->texture = sfTexture_createFromFile("assets/vs_bg.png", &rect);
    sfRectangleShape_setPosition(bar->bar, bar->pos);
    sfRectangleShape_setSize(bar->bar, bar->size);
    sfRectangleShape_setTexture(bar->bar, bar->texture, sfTrue);
}

void init_hp_bar(bar_t *bar, int x, int y)
{
    bar->bar = sfRectangleShape_create();
    bar->pos.x = x;
    bar->pos.y = y;
    bar->size.x = 271;
    bar->size.y = 15.5;
    sfRectangleShape_setPosition(bar->bar, bar->pos);
    sfRectangleShape_setSize(bar->bar, bar->size);
    sfRectangleShape_setFillColor(bar->bar, sfGreen);
}

void init_flashing_bar(bar_t *bar, int x, int y)
{
    sfIntRect rect;

    rect.width = 1920;
    rect.height = 1080;
    rect.top = 0;
    rect.left = 0;
    bar->bar = sfRectangleShape_create();
    bar->pos.x = x;
    bar->pos.y = y;
    bar->size.x = 100;
    bar->size.y = 13;
    bar->texture = sfTexture_createFromFile("assets/blank.png", &rect);
    sfRectangleShape_setPosition(bar->bar, bar->pos);
    sfRectangleShape_setSize(bar->bar, bar->size);
    sfRectangleShape_setTexture(bar->bar, bar->texture, sfTrue);
}

void update_bar(bar_t *bar, int size_min, int size_max)
{
    if (bar->size.x < size_min)
        bar->size.x = size_min;
    if (bar->size.x > size_max)
        bar->size.x = size_max;
    sfRectangleShape_setPosition(bar->bar, bar->pos);
    sfRectangleShape_setSize(bar->bar, bar->size);
    if (bar->size.x > 135)
        sfRectangleShape_setFillColor(bar->bar, sfGreen);
    if (bar->size.x < 135)
        sfRectangleShape_setFillColor(bar->bar, sfYellow);
    if (bar->size.x < 75)
        sfRectangleShape_setFillColor(bar->bar, sfRed);
}