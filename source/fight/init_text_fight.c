/*
** EPITECH PROJECT, 2020
** undefined
** File description:
** init_text_fight.c
*/

#include <taya.h>
#include <fight.h>

char *int_to_str(int nb)
{
    char buffer[1000];
    int i = 0;

    if (nb < 0) {
        nb = -nb;
        buffer[i++] = '-';
    }
    while (nb > 9) {
        buffer[i++] = nb % 10 + '0';
        nb /= 10;
    }
    buffer[i++] = nb + '0';
    buffer[i] = '\0';
    return my_strdup(my_revstr(buffer));
}

void change_life_text(hp_t *hp)
{
    char buffer[100];
    char *p;

    p = int_to_str(hp->life);
    my_strcpy(buffer, p);
    free(p);
    my_strcat(buffer, "/");
    p = int_to_str(hp->life_max);
    my_strcat(buffer, p);
    sfText_setString(hp->text, buffer);
    free(p);
}

void init_life_text(fight_t *fight)
{
    char buffer[100];
    char *p;

    p = int_to_str(fight->hugo->hp->life);
    my_strcpy(buffer, p);
    my_strcat(buffer, "/");
    free(p);
    p = int_to_str(fight->hugo->hp->life_max);
    my_strcat(buffer, p);
    fight->hugo->hp->text = sfText_create();
    sfText_setFont(fight->hugo->hp->text, fight->font);
    fight->hugo->hp->pos.x = 1450;
    fight->hugo->hp->pos.y = 720;
    sfText_setPosition(fight->hugo->hp->text, fight->hugo->hp->pos);
    sfText_setCharacterSize(fight->hugo->hp->text, 30);
    sfText_setString(fight->hugo->hp->text, buffer);
    sfText_setColor(fight->hugo->hp->text, sfBlack);
    free(p);
}

void init_text_hugo(fight_t *fight)
{
    fight->hugo->text = sfText_create();
    fight->hugo->text_pos.x = 1200;
    fight->hugo->text_pos.y = 610;
    fight->font = sfFont_createFromFile("assets/fonts/pokemon.ttf");
    my_strcpy(fight->hugo->name, "Hugo");
    sfText_setFont(fight->hugo->text, fight->font);
    sfText_setPosition(fight->hugo->text, fight->hugo->text_pos);
    sfText_setCharacterSize(fight->hugo->text, 50);
    sfText_setString(fight->hugo->text, fight->hugo->name);
    sfText_setColor(fight->hugo->text, sfBlack);
}

void init_text_opponent(fight_t *fight)
{
    fight->opponent->text = sfText_create();
    fight->opponent->text_pos.x = 50;
    fight->opponent->text_pos.y = 30;
    sfText_setFont(fight->opponent->text, fight->font);
    sfText_setPosition(fight->opponent->text, fight->opponent->text_pos);
    if (my_strlen(fight->opponent->name) > 10)
        sfText_setCharacterSize(fight->opponent->text, 27);
    else
    sfText_setCharacterSize(fight->opponent->text, 50);
    sfText_setString(fight->opponent->text, fight->opponent->name);
    sfText_setColor(fight->opponent->text, sfBlack);
}