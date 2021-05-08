/*
** EPITECH PROJECT, 2020
** undefined
** File description:
** change_text.c
*/

#include <taya.h>
#include <fight.h>

void make_hugo_hit_text(turn_t *turn, char *name)
{
    char buffer[100];
    my_strcpy(buffer, name);
    my_strcat(buffer, " utilise ");
    my_strcat(buffer, turn->action);
    sfText_setString(turn->text, buffer);
}

void make_opponent_hit_text(turn_t *turn, char *name, char *action)
{
    char buffer[100];
    my_strcpy(buffer, name);
    my_strcat(buffer, " utilise ");
    my_strcat(buffer, action);
    sfText_setString(turn->text, buffer);
}