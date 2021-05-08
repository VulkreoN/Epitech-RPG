/*
** EPITECH PROJECT, 2021
** destroy_start
** File description:
** destroy start structures
*/

#include "taya.h"
#include "rpg.h"

void destroy_start(start_t *start)
{
    sfTexture_destroy(start->bg);
    sfSprite_destroy(start->bg_spr);
    sfTexture_destroy(start->rdd);
    sfSprite_destroy(start->rdd_spr);
    destroy_sprite(start->new);
    free(start->new);
    destroy_sprite(start->param);
    free(start->param);
    destroy_sprite(start->quit);
    free(start->quit);
    if (start->played == 0) {
        sfTexture_destroy(start->play_disabled);
        sfSprite_destroy(start->play_disabled_spr);
    }
    else {
        destroy_sprite(start->start);
        free(start->start);
    }
}