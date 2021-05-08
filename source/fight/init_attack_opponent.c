/*
** EPITECH PROJECT, 2020
** fight
** File description:
** init_attack_opponent.c
*/

#include "fight.h"

void attack_of_miel_pops(attack_t attack[4], int def)
{
    init_name_attack(&attack[0], "BZZZ bzz bzzzzzzz",
    200, 850);
    attack[0].damage = 150 - def + 10;
    init_name_attack(&attack[1], "Miel Pops!",
    1100, 850);
    attack[1].damage = 50 - def + 10;
    if (def >= 60)
        attack[1].damage = 5;
    init_name_attack(&attack[2], "Grosse piqure", 200, 950);
    attack[2].damage = 40 - def + 10;
    if (def >= 50)
        attack[2].damage = 5;
    init_name_attack(&attack[3], "Je vais appeler Maya fdp",
    1100, 950);
    attack[3].damage = 10 - def + 10;
    if (def >= 20)
        attack[3].damage = 5;
}

void attack_of_covid(attack_t attack[4], int def)
{
    init_name_attack(&attack[0], "ATCHOUM", 200, 850);
    attack[0].damage = 60 - def + 10;
    if (def == 70)
        attack[0].damage = 5;
    init_name_attack(&attack[1], "JE SUIS LE COVID", 1100, 850);
    attack[1].damage = 45 - def + 10;
    if (def >= 45)
        attack[1].damage = 5;
    init_name_attack(&attack[2], "CONFINED LES PNJ", 200, 950);
    attack[2].damage = 120 - def + 10;
    init_name_attack(&attack[3], "AYAAAAAAAAA", 1100, 950);
    attack[3].damage = 20 - def + 10;
    if (def >= 40)
        attack[3].damage = 5;
}

void attack_of_maxence(attack_t attack[4], int def)
{
    init_name_attack(&attack[0], "Hugo, la TA dit n'importe quoi",
    200, 850);
    attack[0].damage = 150 - def + 10;
    init_name_attack(&attack[1], "L'intra fait pas foi du tout",
    1100, 850);
    attack[1].damage = 50 - def + 10;
    if (def >= 60)
        attack[1].damage = 5;
    init_name_attack(&attack[2], "Whanos ne me guide pas", 200, 950);
    attack[2].damage = 40 - def + 10;
    if (def >= 40)
        attack[2].damage = 5;
    init_name_attack(&attack[3], "Je ferais PAS de tests fonctionnels",
    1100, 950);
    attack[3].damage = 10 - def + 10;
    if (def >= 20)
        attack[3].damage = 5;
}

void attack_of_jerome(attack_t attack[4], int def)
{
    init_name_attack(&attack[0], "Salete de tek1", 200, 850);
    attack[0].damage = 40 - def + 10;
    if (def >= 40)
        attack[0].damage = 5;
    init_name_attack(&attack[1], "Va faire des JPO toi", 1100, 850);
    attack[1].damage = 140 - def + 10;
    init_name_attack(&attack[2], "Tirs au fusil a merde", 200, 950);
    attack[2].damage = 10 - def + 10;
    if (def >= 20)
        attack[2].damage = 5;
    init_name_attack(&attack[3], "Rondoudou c'est pas un vrai\nPokemon",
    1100, 950);
    attack[3].damage = 80 - def + 10;
}

void attack_of_rondodu(attack_t attack[4], int def)
{
    init_name_attack(&attack[0], "RONDOUDOU", 200, 850);
    attack[0].damage = 20 - def + 10;
    if (def >= 30)
        attack[0].damage = 5;
    init_name_attack(&attack[1], "Mon cheri :)", 1100, 850);
    attack[1].damage = 140 - def + 10;
    init_name_attack(&attack[2], "Tu m'as manque !", 200, 950);
    attack[2].damage = 10 - def + 10;
    if (def >= 20)
        attack[2].damage = 5;
    init_name_attack(&attack[3], "Voici les croissants :)", 1100, 950);
    attack[3].damage = 60 - def + 10;
    if (def >= 70)
        attack[3].damage = 5;
}