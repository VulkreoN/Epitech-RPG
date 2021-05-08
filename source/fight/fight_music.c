/*
** EPITECH PROJECT, 2021
** fight_music
** File description:
** handle music for fight
*/

#include <taya.h>
#include <fight.h>

void assign_music_for_fight(sfMusic *song)
{
    sfMusic_play(song);
    sfMusic_setLoop(song, sfTrue);
    sfMusic_setVolume(song, 50);
}