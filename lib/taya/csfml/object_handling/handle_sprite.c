/*
** EPITECH PROJECT, 2021
** handle_sprite
** File description:
** sprite handling functions
*/

#include "../../../../include/taya.h"
#include "../../../../include/rpg.h"
#include "../../../../include/linked_list.h"

void change_sprite(object_t *object, int texture)
{
    if (texture == object->texture)
        return;
    sfSprite_setTexture(object->spr, object->pixel[texture], sfTrue);
    object->texture = texture;
}

void initialise_object_elements(object_t *object)
{
    object->pixel = NULL;
    object->img = 0;
    object->spr = NULL;
}

void make_sprite(object_t *object, char *path)
{
    initialise_object_elements(object);
    make_object_texture(object, path);
    if (object->pixel == NULL)
        return;
    object->spr = sfSprite_create();
    sfSprite_setTexture(object->spr, object->pixel[0], sfTrue);
    sfSprite_setPosition(object->spr, object->pos);
    object->size = sfTexture_getSize(object->pixel[0]);
}

void destroy_sprite(object_t *object)
{
    if (object->spr != NULL)
        sfSprite_destroy(object->spr);
    for (int inc = 0; inc < object->img; inc++) {
        if (object->pixel[inc] != NULL)
            sfTexture_destroy(object->pixel[inc]);
    }
    if (object->pixel != NULL)
        free(object->pixel);
}