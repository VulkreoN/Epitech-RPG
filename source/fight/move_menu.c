/*
** EPITECH PROJECT, 2020
** undefined
** File description:
** move_menu.c
*/

#include <fight.h>

int move_menu_right(menu_t *menu, int pos, int move)
{
    if (menu->pos.x < pos) {
        menu->move.x = move;
        sfSprite_move(menu->spr, menu->move);
        menu->pos = sfSprite_getPosition(menu->spr);
        if (menu->pos.x > pos)
            menu->pos.x = pos;
    }
    if (menu->pos.x == pos)
        return (1);
    return (0);
}

int move_menu_left(menu_t *menu, int pos, int move)
{
    if (menu->pos.x > pos) {
        menu->move.x = -move;
        sfSprite_move(menu->spr, menu->move);
        menu->pos = sfSprite_getPosition(menu->spr);
        if (menu->pos.x < pos)
            menu->pos.x = pos;
    }
    if (menu->pos.x == pos)
        return (1);
    return (0);
}