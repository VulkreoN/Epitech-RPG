/*
** EPITECH PROJECT, 2020
** undefined
** File description:
** destroy_menus.c
*/

#include <fight.h>

void destroy_intro_menus(fight_t *fight)
{
    sfTexture_destroy(fight->left->texture);
    sfTexture_destroy(fight->right->texture);
    sfTexture_destroy(fight->vs->texture);
    free(fight->left);
    free(fight->right);
}

void destroy_flash(fight_t *fight)
{
    for (int i = 0; i<fight->nb_flash;i++) {
        sfRectangleShape_destroy(fight->flash[i]->bar);
        sfTexture_destroy(fight->flash[i]->texture);
    }
    for (int i = 0; i<fight->nb_flash;i++)
        free(fight->flash[i]);
    free(fight->flash);
}

void free_struct(fight_t *fight)
{
    free(fight->bg);
    free(fight->hugo->hp->bar);
    free(fight->opponent->hp->bar);
    free(fight->hugo->hp);
    free(fight->opponent->hp);
    free(fight->hugo);
    free(fight->opponent);
    free(fight->line);
    free(fight->box);
    free(fight->arrow);
    free(fight->turn);
    destroy_flash(fight);
}

void destroy_menus(fight_t *fight)
{
    destroy_textures(fight);
    for (int i = 0; i<9;i++)
        sfTexture_destroy(fight->hugo->texture[i]);
    for (int i = 0; i<3;i++)
        sfTexture_destroy(fight->opponent->texture[i]);
    free(fight->vs);
    free_struct(fight);
    sfClock_destroy(fight->clock);
    free(fight);
}