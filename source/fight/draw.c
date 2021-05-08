/*
** EPITECH PROJECT, 2020
** undefined
** File description:
** draw.c
*/

#include <fight.h>

void draw_fight(fight_t *fight, sfRenderWindow *window)
{
    sfRenderWindow_drawSprite(window, fight->hugo->spr, NULL);
    sfRenderWindow_drawSprite(window, fight->opponent->spr, NULL);
    sfRenderWindow_drawSprite(window, fight->hugo->hp->spr, NULL);
    sfRenderWindow_drawSprite(window, fight->opponent->hp->spr,
    NULL);
    sfRenderWindow_drawText(window, fight->hugo->text, NULL);
    sfRenderWindow_drawText(window, fight->opponent->text, NULL);
    sfRenderWindow_drawRectangleShape(window,
    fight->hugo->hp->bar->bar, NULL);
    sfRenderWindow_drawRectangleShape(window,
    fight->opponent->hp->bar->bar, NULL);
    sfRenderWindow_drawText(window, fight->hugo->hp->text, NULL);
    sfRenderWindow_drawRectangleShape(window,
    fight->box->bar, NULL);
    if (!fight->turn->turn) {
        sfRenderWindow_drawSprite(window, fight->arrow->spr, NULL);
        for (int i = 0; i < 4; i++)
            sfRenderWindow_drawText(window, fight->attack[i].text, NULL);
    }
    if (fight->turn->turn > 0)
        sfRenderWindow_drawText(window, fight->turn->text, NULL);
}

void display_ressources(fight_t *fight, sfRenderWindow *window)
{
    sfRenderWindow_clear(window, sfBlue);
    sfRenderWindow_drawSprite(window, fight->bg->spr, NULL);
    if (!fight->intro) {
        sfRenderWindow_drawSprite(window, fight->left->spr, NULL);
        sfRenderWindow_drawSprite(window, fight->right->spr, NULL);
    }
    if (fight->intro == 1) {
        sfRenderWindow_drawRectangleShape(window, fight->line->bar,
        NULL);
        for (int i = 0; i<fight->nb_flash; i++)
            sfRenderWindow_drawRectangleShape(window,
            fight->flash[i]->bar, NULL);
        sfRenderWindow_drawSprite(window, fight->vs->spr, NULL);
    }
    if (fight->intro == 2)
        draw_fight(fight, window);
    sfRenderWindow_display(window);
}