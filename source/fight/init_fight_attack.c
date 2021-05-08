/*
** EPITECH PROJECT, 2020
** undefined
** File description:
** init_fight_attack.c
*/

#include <fight.h>
#include <taya.h>

void init_name_attack(attack_t *attack, char *sentence, int x, int y)
{
    attack->pos.x = x;
    attack->pos.y = y;
    attack->text = sfText_create();
    attack->action = malloc(sizeof(char) * my_strlen(sentence) + 1);
    sfText_setPosition(attack->text, attack->pos);
    if (my_strlen(sentence) < 20)
        sfText_setCharacterSize(attack->text, 30);
    else
        sfText_setCharacterSize(attack->text, 25);
    my_strcpy(attack->action, sentence);
    sfText_setString(attack->text, attack->action);
    sfText_setColor(attack->text, sfBlack);
}

void init_opponent_attack(char *name, attack_t attack[4], fight_t *fight)
{
    if (!my_strcmp(name, "Le_covid"))
        attack_of_covid(attack, fight->def);
    if (!my_strcmp(name, "Miel_Pops"))
        attack_of_miel_pops(attack, fight->def);
    if (!my_strcmp(name, "Maxence"))
        attack_of_maxence(attack, fight->def);
    if (!my_strcmp(name, "Jerome"))
        attack_of_jerome(attack, fight->def);
    if (!my_strcmp(name, "Rondodu"))
        attack_of_rondodu(attack, fight->def);
}

void init_attack(char *name, attack_t attack[4], fight_t *fight)
{
    if (!my_strcmp(name, "Le_covid"))
        attack_on_covid(attack, fight->dmg);
    if (!my_strcmp(name, "Miel_Pops"))
        attack_on_miel_pops(attack, fight->dmg);
    if (!my_strcmp(name, "Jerome"))
        attack_on_jerome(attack, fight->dmg);
    if (!my_strcmp(name, "Maxence"))
        attack_on_maxence(attack, fight->dmg);
    if (!my_strcmp(name, "Rondodu"))
        attack_on_rondodu(attack, fight->dmg);
}

void init_fight_loop(fight_t *fight)
{
    init_text_hugo(fight);
    init_text_opponent(fight);
    fight->clock = sfClock_create();
    fight->hugo->hp->bar = malloc(sizeof(bar_t));
    fight->opponent->hp->bar = malloc(sizeof(bar_t));
    init_bg_bar(fight->line, 0, 420);
    init_hp_bar(fight->hugo->hp->bar, 1393, 690);
    init_hp_bar(fight->opponent->hp->bar, 240, 105);
    init_life_text(fight);
    init_attack(fight->opponent->name, fight->attack, fight);
    init_opponent_attack(fight->opponent->name, fight->opponent_atk, fight);
    for (int i = 0; i < 4; i++) {
        sfText_setFont(fight->attack[i].text, fight->font);
        sfText_setFont(fight->opponent_atk[i].text, fight->font);
    }
    sfText_setFont(fight->turn->text, fight->font);
    fight->flash = malloc(sizeof(bar_t *)*fight->nb_flash);
    for (int i = 0; i < fight->nb_flash; i++) {
        fight->flash[i] = malloc(sizeof(bar_t));
        init_flashing_bar(fight->flash[i], 0 + (i * 125), 435 + (i * 7));
    }
}