/*
** EPITECH PROJECT, 2021
** pause_header
** File description:
** handle pause headers display
*/

#include "rpg.h"

static void handle_atk_def_display(game_t *game, pause_t *pause)
{
    int pos = 850;

    for (int inc = 0; inc < (pause->atk - 10) / 10; inc++) {
        sfSprite_setPosition(pause->rod_spr, send_pos(pos + (40 * inc), 328));
        sfRenderWindow_drawSprite(game->window, pause->rod_spr, NULL);
    }
    for (int inc = 0; inc < (pause->def - 10) / 10; inc++) {
        sfSprite_setPosition(pause->rod_spr, send_pos(pos + (40 * inc), 470));
        sfRenderWindow_drawSprite(game->window, pause->rod_spr, NULL);
    }
}

static void handle_skill(game_t *game, pause_t *pause)
{
    int len = 0;
    int atk_price = (pause->atk / 10) * 50;
    int def_price = (pause->def / 10) * 50;

    change_sprite(pause->skill, 3);
    make_redirection(game, pause->info);
    make_redirection(game, pause->player);
    make_redirection(game, pause->atkbtn);
    make_redirection(game, pause->defbtn);
    len = 950 - (my_intlen(pause->money) * 10);
    make_text(game->window, int_to_str(pause->money), send_pos(len, 670), 50);
    make_text(game->window, int_to_str(atk_price), send_pos(1035, 285), 30);
    make_text(game->window, int_to_str(def_price), send_pos(1035, 425), 30);
    make_text(game->window, "SKILL", send_pos(890, 130), 50);
    handle_atk_def_display(game, pause);
    sfRenderWindow_drawSprite(game->window, pause->skill->spr, NULL);   
}

static void handle_player(game_t *game, pause_t *pause)
{
    int len = 1060 - (my_intlen(pause->money) * 10);

    change_sprite(pause->player, 3);
    make_redirection(game, pause->info);
    make_redirection(game, pause->skill);
    make_text(game->window, ":COINS: ", send_pos(997, 270), 35);
    make_text(game->window, int_to_str(pause->money), send_pos(len, 310), 35);
    make_text(game->window, ":ATTACK: ", send_pos(975, 390), 35);
    len = 1060 - (my_intlen(pause->atk) * 10);
    make_text(game->window, int_to_str(pause->atk), send_pos(len, 430), 35);
    make_text(game->window, ":DEFENSE: ", send_pos(968, 510), 35);
    len = 1060 - (my_intlen(pause->def) * 10);
    make_text(game->window, int_to_str(pause->def), send_pos(len, 550), 35);
    make_text(game->window, "STATUS", send_pos(850, 130), 50);
    sfRenderWindow_drawSprite(game->window, pause->player->spr, NULL);
    handle_inventory(game);
}

static void handle_info(game_t *game, pause_t *pause)
{
    change_sprite(pause->info, 3);
    make_redirection(game, pause->home);
    make_redirection(game, pause->resume);
    make_redirection(game, pause->param);
    make_redirection(game, pause->quit);
    make_redirection(game, pause->player);
    make_redirection(game, pause->skill);
    make_text(game->window, "INFO", send_pos(900, 130), 50);
    sfRenderWindow_drawSprite(game->window, pause->info->spr, NULL);
}

void handle_pause_headers_display(game_t *game, pause_t *pause)
{
    if (pause->header == 0)
        handle_player(game, pause);
    else if (pause->header == 1)
        handle_info(game, pause);
    else
        handle_skill(game, pause);
}