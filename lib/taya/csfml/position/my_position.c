/*
** EPITECH PROJECT, 2021
** my_position
** File description:
** position lib
*/

#include "../../../../include/taya.h"
#include "../../../../include/rpg.h"

sfIntRect send_rect(int height, int width, int top, int left)
{
    sfIntRect rect;

    rect.height = height;
    rect.width = width;
    rect.top = top,
    rect.left = left;
    return (rect);
}

sfVector2f send_pos(int x, int y)
{
    sfVector2f pos;

    pos.x = x;
    pos.y = y;
    return (pos);
}

void set_pos(sfVector2f *pos, float x, float y)
{
    pos->x = x;
    pos->y = y;
}