/*
** EPITECH PROJECT, 2020
** undefined
** File description:
** hit_system.c
*/

#include <fight.h>
#include <taya.h>

void change_left_and_right_arrow_pos(sfEvent event, arrow_t *arrow)
{
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyLeft)
        if (arrow->pos.x == arrow->first_posx) {
            arrow->pos.x -= arrow->decal_x;
            sfSprite_setPosition(arrow->spr, arrow->pos);
            my_strcpy(arrow->position_x, "left");
        }
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyRight)
        if (arrow->pos.x == arrow->first_posx-arrow->decal_x) {
            arrow->pos.x += arrow->decal_x;
            sfSprite_setPosition(arrow->spr, arrow->pos);
            my_strcpy(arrow->position_x, "right");
        }
}

void change_up_and_down_arrow_pos(sfEvent event, arrow_t *arrow)
{
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyUp)
        if (arrow->pos.y == arrow->first_posy) {
            arrow->pos.y -= arrow->decal_y;
            sfSprite_setPosition(arrow->spr, arrow->pos);
            my_strcpy(arrow->position_y, "up");
        }
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyDown)
        if (arrow->pos.y == arrow->first_posy-arrow->decal_y) {
            arrow->pos.y += arrow->decal_y;
            sfSprite_setPosition(arrow->spr, arrow->pos);
            my_strcpy(arrow->position_y, "down");
        }
}

void change_arrow_pos(sfEvent event, arrow_t *arrow)
{
    change_left_and_right_arrow_pos(event, arrow);
    change_up_and_down_arrow_pos(event, arrow);
}

void hit_opponent(fight_t *fight, arrow_t *arrow, sfRenderWindow *window)
{
    if (!my_strcmp(arrow->position_x, "left") &&
    !my_strcmp(arrow->position_y, "up")) {
        my_strcpy(fight->turn->action, fight->attack[0].action);
        take_hit(fight, fight->opponent, fight->attack[0].damage, window);
    }
    if (!my_strcmp(arrow->position_x, "right") &&
    !my_strcmp(arrow->position_y, "up")) {
        my_strcpy(fight->turn->action, fight->attack[1].action);
        take_hit(fight, fight->opponent, fight->attack[1].damage, window);
    }
    if (!my_strcmp(arrow->position_x, "left") &&
    !my_strcmp(arrow->position_y, "down")) {
        my_strcpy(fight->turn->action, fight->attack[2].action);
        take_hit(fight, fight->opponent, fight->attack[2].damage, window);
    }
    if (!my_strcmp(arrow->position_x, "right") &&
    !my_strcmp(arrow->position_y, "down")) {
        my_strcpy(fight->turn->action, fight->attack[3].action);
        take_hit(fight, fight->opponent, fight->attack[3].damage, window);
    }
}