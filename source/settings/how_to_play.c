/*
** EPITECH PROJECT, 2020
** undefined
** File description:
** how_to_play.c
*/

#include "rpg.h"

void display_how_to_play_menu(sfRenderWindow *window)
{
    make_text_white(window, "    Press Esc to skip cinematics\n\
    Use mouse to select an option\n\
    Left Click to select it\n\n\
    IN THE OVERWORLD:\n\
    Arrow keys to move\n\
    E to interact with objects or PNJ\n\
    ENTER to skip dialogues\n\
    Esc for the pause menu\n\n\
    FIGHT:\n\
    Use the arrow key to choose an action\n\
    Enter to select it", send_pos(-45, 200), 35);
}