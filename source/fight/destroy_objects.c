/*
** EPITECH PROJECT, 2020
** undefined
** File description:
** destroy_objects.c
*/

#include <fight.h>

static void destroy_sprite_fight(fight_t *fight)
{
    sfSprite_destroy(fight->bg->spr);
    sfSprite_destroy(fight->left->spr);
    sfSprite_destroy(fight->right->spr);
    sfSprite_destroy(fight->hugo->spr);
    sfSprite_destroy(fight->vs->spr);
    sfSprite_destroy(fight->arrow->spr);
    sfSprite_destroy(fight->opponent->spr);
    sfSprite_destroy(fight->hugo->hp->spr);
    sfSprite_destroy(fight->opponent->hp->spr);
}

void destroy_text_and_rectangle(fight_t *fight)
{
    sfRectangleShape_destroy(fight->hugo->hp->bar->bar);
    sfRectangleShape_destroy(fight->opponent->hp->bar->bar);
    sfRectangleShape_destroy(fight->line->bar);
    sfRectangleShape_destroy(fight->box->bar);
    for (int i = 0; i < 4; i++) {
        sfText_destroy(fight->attack[i].text);
        sfText_destroy(fight->opponent_atk[i].text);
        free(fight->attack[i].action);
        free(fight->opponent_atk[i].action);
    }
    free(fight->arrow->position_x);
    free(fight->arrow->position_y);
    free(fight->turn->action);
    sfText_destroy(fight->hugo->text);
    sfText_destroy(fight->opponent->text);
    sfText_destroy(fight->hugo->hp->text);
    sfText_destroy(fight->turn->text);
}

void destroy_textures(fight_t *fight)
{
    destroy_sprite_fight(fight);
    destroy_intro_menus(fight);
    sfTexture_destroy(fight->bg->texture);
    sfTexture_destroy(fight->hugo->hp->texture);
    sfTexture_destroy(fight->opponent->hp->texture);
    sfTexture_destroy(fight->line->texture);
    sfTexture_destroy(fight->box->texture);
    sfTexture_destroy(fight->arrow->texture);
    destroy_text_and_rectangle(fight);
    sfFont_destroy(fight->font);
}