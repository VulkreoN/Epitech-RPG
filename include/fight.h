/*
** EPITECH PROJECT, 2020
** undefined
** File description:
** fight.h
*/

#ifndef FIGHT_H_
#define FIGHT_H_

#include "taya.h"
#include "rpg.h"
#include <stdlib.h>
#include <stdio.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>

typedef struct {
    sfRectangleShape *bar;
    sfVector2f pos;
    sfVector2f size;
    sfVector2f move;
    sfTexture *texture;
}   bar_t;

typedef struct {
    sfSprite *spr;
    sfTexture *texture;
    sfVector2f pos;
    sfVector2f move;
    bar_t *bar;
}   menu_t;

typedef struct {
    sfSprite *spr;
    sfTexture *texture;
    sfVector2f pos;
    sfVector2f move;
    float first_posx;
    float first_posy;
    int decal_x;
    int decal_y;
    char *position_x;
    char *position_y;
}   arrow_t;

typedef struct {
    sfText *text;
    sfVector2f pos;
    sfVector2f move;
    char *action;
    int damage;
}   attack_t;

typedef struct {
    int turn;
    sfText *text;
    sfVector2f text_pos;
    char *action;
}   turn_t;

typedef struct {
    sfSprite *spr;
    sfTexture *texture;
    sfVector2f pos;
    sfVector2f move;
    sfIntRect rect;
    bar_t *bar;
    int life;
    int life_max;
    sfText *text;
    sfVector2f text_pos;
}   hp_t;

typedef struct {
    sfSprite *spr;
    sfTexture *texture[9];
    sfVector2f pos;
    sfVector2f move;
    sfIntRect rect;
    int change;
    int attack;
    hp_t *hp;
    sfText *text;
    sfVector2f text_pos;
    char name[20];
}   perso_t;

typedef struct {
    menu_t *bg;
    menu_t *left;
    menu_t *right;
    menu_t *vs;
    bar_t *line;
    bar_t **flash;
    bar_t *box;
    perso_t *hugo;
    perso_t *opponent;
    arrow_t *arrow;
    turn_t *turn;
    attack_t attack[4];
    attack_t opponent_atk[4];
    int intro;
    int nb_flash;
    sfClock *clock;
    sfTime time;
    float sec;
    sfFont *font;
    int dmg;
    int def;
}   fight_t;

void init_opponent(fight_t *fight, char *path);
void init_hugo(fight_t *fight);
void init_fight(fight_t *fight, player_t *player);
void init_pos_menu(fight_t *fight);
void init_menu(fight_t *fight);
void init_text_hugo(fight_t *fight);
void init_text_opponent(fight_t *fight);
void init_bg_bar(bar_t *bar, int x, int y);
void init_hp_bar(bar_t *bar, int x, int y);
void init_flashing_bar(bar_t *bar, int x, int y);
void init_life_text(fight_t *fight);
void init_fight_loop(fight_t *fight);

int fight_loop(fight_t *fight, sfRenderWindow *window);
void event_loop(fight_t *fight, sfRenderWindow *window);

void fight_with_covid(game_t *game, player_t *player);
void fight_with_rondodu(game_t *game, player_t *player);
void fight_with_miel_pops(game_t *game, player_t *player);
void fight_with_jerome(game_t *game, player_t *player);
void fight_with_maxence(game_t *game, player_t *player);

void init_name_attack(attack_t *attack, char *sentence, int x, int y);

void attack_on_miel_pops(attack_t attack[4], int dmg);
void attack_on_covid(attack_t attack[4], int dmg);
void attack_on_jerome(attack_t attack[4], int dmg);
void attack_on_maxence(attack_t attack[4], int dmg);
void attack_on_rondodu(attack_t attack[4], int dmg);

void attack_of_miel_pops(attack_t attack[4], int def);
void attack_of_covid(attack_t attack[4], int def);
void attack_of_maxence(attack_t attack[4], int def);
void attack_of_jerome(attack_t attack[4], int def);
void attack_of_rondodu(attack_t attack[4], int def);

void display_ressources(fight_t *fight, sfRenderWindow *window);
void draw_fight(fight_t *fight, sfRenderWindow *window);

int move_menu_right(menu_t *menu, int pos, int move);
int move_menu_left(menu_t *menu, int pos, int move);
void move_flash(fight_t *fight);

void make_anim_fight(fight_t *fight);
void start_fight(fight_t *fight);
void make_intro(fight_t *fight);

void change_life_text(hp_t *hp);
void change_arrow_pos(sfEvent event, arrow_t *arrow);
void update_bar(bar_t *bar, int size_min, int size_max);
void take_hit(fight_t *fight, perso_t *perso, int damage, sfRenderWindow *win);
void hit_opponent(fight_t *fight, arrow_t *arrow, sfRenderWindow *window);
void heal_perso(fight_t *fight, perso_t *perso, int heal, sfRenderWindow *win);
void make_hugo_hit_text(turn_t *turn, char *name);
void make_opponent_hit_text(turn_t *turn, char *name, char *action);

void destroy_menus(fight_t *fight);
void destroy_textures(fight_t *fight);
void destroy_intro_menus(fight_t *fight);
void destroy_flash(fight_t *fight);

void assign_music_for_fight(sfMusic *song);
#endif