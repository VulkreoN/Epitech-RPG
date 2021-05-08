/*
** EPITECH PROJECT, 2020
** undefined
** File description:
** initialise.c
*/

#include <taya.h>
#include <fight.h>

void init_box(bar_t *bar)
{
    sfIntRect rect;
    rect.width = 1920;
    rect.height = 280;
    rect.top = 0;
    rect.left = 0;
    bar->bar = sfRectangleShape_create();
    bar->pos.x = 0;
    bar->pos.y = 800;
    bar->size.x = 1920;
    bar->size.y = 280;
    bar->texture = sfTexture_createFromFile("assets/text_box.png", &rect);
    sfRectangleShape_setPosition(bar->bar, bar->pos);
    sfRectangleShape_setSize(bar->bar, bar->size);
    sfRectangleShape_setTexture(bar->bar, bar->texture, sfTrue);
}

void init_arrow(arrow_t *arrow, int x, int y)
{
    sfIntRect rect;
    rect.width = 1920;
    rect.height = 280;
    rect.top = 0;
    rect.left = 0;
    arrow->pos.x = x;
    arrow->pos.y = y;
    arrow->first_posx = x;
    arrow->first_posy = y;
    arrow->decal_x = 900;
    arrow->decal_y = 100;
    arrow->spr = sfSprite_create();
    arrow->move.x = 0;
    arrow->move.y = 0;
    arrow->texture = sfTexture_createFromFile("assets/arrow.png", &rect);
    arrow->position_x = malloc(sizeof(char)*6);
    arrow->position_y = malloc(sizeof(char)*5);
    my_strcpy(arrow->position_x, "right");
    my_strcpy(arrow->position_y, "down");
    sfSprite_setPosition(arrow->spr, arrow->pos);
    sfSprite_setTexture(arrow->spr, arrow->texture, sfTrue);
}

void init_turn(turn_t *turn)
{
    turn->turn = 0;
    turn->text = sfText_create();
    turn->text_pos.x = 100;
    turn->text_pos.y = 825;
    turn->action = malloc(sizeof(char) * 50);
    sfText_setPosition(turn->text, turn->text_pos);
    sfText_setCharacterSize(turn->text, 50);
    sfText_setColor(turn->text, sfBlack);
}

void init_fight(fight_t *fight, player_t *player)
{
    fight->bg = malloc(sizeof(menu_t));
    fight->left = malloc(sizeof(menu_t));
    fight->right = malloc(sizeof(menu_t));
    fight->vs = malloc(sizeof(menu_t));
    fight->arrow = malloc(sizeof(arrow_t));
    fight->line = malloc(sizeof(bar_t));
    fight->box = malloc(sizeof(bar_t));
    fight->turn = malloc(sizeof(turn_t));
    init_pos_menu(fight);
    init_menu(fight);
    init_box(fight->box);
    init_arrow(fight->arrow , 1000, 925);
    init_turn(fight->turn);
    fight->intro = 0;
    fight->nb_flash = 15;
    fight->dmg = player->attack;
    fight->def = player->defense;
}