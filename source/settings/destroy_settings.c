/*
** EPITECH PROJECT, 2021
** destroy_settings
** File description:
** destroy settings structures
*/

#include "rpg.h"
#include "taya.h"

void destroy_settings(settings_t *param)
{
    sfTexture_destroy(param->bg);
    sfSprite_destroy(param->bg_spr);
    destroy_sprite(param->high);
    destroy_sprite(param->back);
    destroy_sprite(param->low);
    destroy_sprite(param->play);
    free(param->high);
    free(param->back);
    free(param->low);
    free(param->play);
}