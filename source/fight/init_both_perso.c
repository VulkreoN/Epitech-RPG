/*
** EPITECH PROJECT, 2020
** undefined
** File description:
** init_both_perso.c
*/

#include <taya.h>
#include <fight.h>

void init_life_hugo(hp_t *hp, int x, int y)
{
    hp->life = 271;
    hp->life_max = hp->life;
    hp->spr = sfSprite_create();
    hp->rect.width = 600;
    hp->rect.height = 220;
    hp->move.x = 0;
    hp->move.y = 0;
    hp->rect.top = 250;
    hp->rect.left = 0;
    hp->texture = sfTexture_createFromFile("assets/health_bar.png",
        &hp->rect);
    hp->pos.x = x;
    hp->pos.y = y;
    sfSprite_setPosition(hp->spr, hp->pos);
    sfSprite_setTexture(hp->spr, hp->texture, sfTrue);
}

void init_life_opponent(hp_t *hp, int x, int y)
{
    hp->life = 271;
    hp->life_max = hp->life;
    hp->spr = sfSprite_create();
    hp->rect.width = 600;
    hp->rect.height = 220;
    hp->move.x = 0;
    hp->move.y = 0;
    hp->rect.top = 0;
    hp->rect.left = 0;
    hp->texture = sfTexture_createFromFile("assets/health_bar.png",
        &hp->rect);
    hp->pos.x = x;
    hp->pos.y = y;
    sfSprite_setPosition(hp->spr, hp->pos);
    sfSprite_setTexture(hp->spr, hp->texture, sfTrue);
}

void init_hugo(fight_t *fight)
{
    fight->hugo = malloc(sizeof(perso_t));
    fight->hugo->hp = malloc(sizeof(hp_t));
    fight->hugo->rect.width = 350;
    fight->hugo->rect.height = 300;
    fight->hugo->spr = sfSprite_create();
    fight->hugo->move.x = 0;
    fight->hugo->move.y = 0;
    fight->hugo->rect.top = 0;
    for (int i = 0; i < 9; i++) {
        fight->hugo->rect.left = 350* (i%3);
        fight->hugo->rect.top = 0 + (300 * (i % 3));
        fight->hugo->texture[i] =
        sfTexture_createFromFile("assets/Rondoudou.png", &fight->hugo->rect);
    }
    fight->hugo->pos.x = 250;
    fight->hugo->pos.y = 490;
    sfSprite_setPosition(fight->hugo->spr, fight->hugo->pos);
    sfSprite_setTexture(fight->hugo->spr, fight->hugo->texture[0], sfTrue);
    fight->hugo->change = 0;
    my_strcpy(fight->hugo->name, "Hugo");
    init_life_hugo(fight->hugo->hp, 1100, 585);
}

void init_opponent_sprite(fight_t *fight, char *name)
{
    char buffer[100];

    fight->opponent->rect.width = 400;
    fight->opponent->rect.height = 500;
    fight->opponent->spr = sfSprite_create();
    fight->opponent->move.x = 0;
    fight->opponent->move.y = 0;
    fight->opponent->rect.top = 0;
    my_strcpy(buffer, "assets/");
    my_strcat(buffer, name);
    my_strcat(buffer, ".png");
    my_strcpy(fight->opponent->name, name);
    for (int i = 0; i < 3; i++) {
        fight->opponent->rect.left = 420*i;
        fight->opponent->texture[i] =
        sfTexture_createFromFile(buffer, &fight->opponent->rect);
    }
}

void init_opponent(fight_t *fight, char *name)
{
    fight->opponent = malloc(sizeof(perso_t));
    fight->opponent->hp = malloc(sizeof(hp_t));
    init_opponent_sprite(fight, name);
    fight->opponent->pos.x = 1200;
    fight->opponent->pos.y = 0;
    sfSprite_setPosition(fight->opponent->spr, fight->opponent->pos);
    sfSprite_setTexture(fight->opponent->spr, fight->opponent->texture[0],
    sfTrue);
    fight->opponent->hp->life = 100;
    fight->opponent->change = 0;
    fight->opponent->attack = 0;
    init_life_opponent(fight->opponent->hp, 0, 0);
}