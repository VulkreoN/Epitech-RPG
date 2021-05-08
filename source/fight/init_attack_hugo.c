/*
** EPITECH PROJECT, 2020
** fight
** File description:
** init_attack_hugo.c
*/

#include "fight.h"

void attack_on_miel_pops(attack_t attack[4], int dmg)
{
    init_name_attack(&attack[0], "Tu n'es rien face aux barquettes Lu",
    200, 850);
    attack[0].damage = 140 + dmg;
    init_name_attack(&attack[1], "Je te mange sans aucun souci",
    1100, 850);
    attack[1].damage = 40 + dmg;
    init_name_attack(&attack[2], "Salete d'abeille", 200, 950);
    attack[2].damage = 40 + dmg;
    init_name_attack(&attack[3], "Sortir le spray anti-insecte",
    1100, 950);
    attack[3].damage = 60 + dmg;
}

void attack_on_covid(attack_t attack[4], int dmg)
{
    init_name_attack(&attack[0], "Monter le masque", 200, 850);
    attack[0].damage = 40 + dmg;
    init_name_attack(&attack[1], "On dit la Covid", 1100, 850);
    attack[1].damage = 140 + dmg;
    init_name_attack(&attack[2], "Mettre le gel hydroalcoolique", 200, 950);
    attack[2].damage = 10 + dmg;
    init_name_attack(&attack[3], "Tu divulgaches le paysage", 1100, 950);
    attack[3].damage = 60 + dmg;
}

void attack_on_jerome(attack_t attack[4], int dmg)
{
    init_name_attack(&attack[0], "Ouais mais je m'en fiche", 200, 850);
    attack[0].damage = 1;
    init_name_attack(&attack[1], "Et pour ma promotion?", 1100, 850);
    attack[1].damage = 1;
    init_name_attack(&attack[2], "...", 200, 950);
    attack[2].damage = 80 + dmg;
    init_name_attack(&attack[3], "T'as vu mon Rondoudou? Style hein",
    1100, 950);
    attack[3].damage = 1;
}

void attack_on_maxence(attack_t attack[4], int dmg)
{
    init_name_attack(&attack[0], "Tu as fait des tests fonctionnels?",
    200, 850);
    attack[0].damage = 80 + dmg;
    init_name_attack(&attack[1], "Tu as utilise le docker Epitest?",
    1100, 850);
    attack[1].damage = 70 + dmg;
    init_name_attack(&attack[2], "L'intra fait foi", 200, 950);
    attack[2].damage = 80 + dmg;
    init_name_attack(&attack[3], "On dit un TA, tocard", 1100, 950);
    attack[3].damage = 120 + dmg;
}

void attack_on_rondodu(attack_t attack[4], int dmg)
{
    init_name_attack(&attack[0], "Ou est le vrai Rondoudou?", 200, 850);
    attack[0].damage = 1;
    init_name_attack(&attack[1], "Degages de la, le fake", 1100, 850);
    attack[1].damage = 140 + dmg;
    init_name_attack(&attack[2], "T'es meme pas chromatique", 200, 950);
    attack[2].damage = 120 + dmg;
    init_name_attack(&attack[3], "Ewwww", 1100, 950);
    attack[3].damage = 40 + dmg;
}