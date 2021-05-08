/*
** EPITECH PROJECT, 2021
** member_end
** File description:
** handle end for each group member
*/

#include "rpg.h"

void handle_johann_end(game_t *game, float y)
{
    char *task = "Reponsable menus, maps, npc et implementation du scenario";
    char *johann = "Johann Sako";

    make_text_white(game->window, task, send_pos(520, 1080 + 1000 - y), 30);
    make_text_white(game->window, johann, send_pos(520, 1080 + 950 - y), 40);
}

void handle_joris_end(game_t *game, float y)
{
    char *task = "Reponsable systeme de combat et scenario";
    char *joris = "Joris Vey";

    make_text_white(game->window, task, send_pos(520, 1080 + 800 - y), 30);
    make_text_white(game->window, joris, send_pos(520, 1080 + 750 - y), 40);
}

void handle_maxence_end(game_t *game, float y)
{
    char *task = "Reponsable joueur, maps et npc";
    char *maxence = "Maxence Folio";

    make_text_white(game->window, task, send_pos(520, 1080 + 600 - y), 30);
    make_text_white(game->window, maxence, send_pos(520, 1080 + 550 - y), 40);
}

void handle_hakim_end(game_t *game, float y)
{
    char *task = "Reponsable assets, merge et systeme de sauvegarde";
    char *hakim = "Hakim Redjem";

    make_text_white(game->window, task, send_pos(520, 1080 + 400 - y), 30);
    make_text_white(game->window, hakim, send_pos(520, 1080 + 350 - y), 40);
}

void handle_copyright_end(game_t *game, float y)
{
    char *start = ("demarrage et game_over:"
    " Yasashii Suisei - Steve Hansen");
    char *pause = ("pause et combat: if elevator "
    "had trap music - the bootleg boy 2");
    char *theme = "jeu: overlord theme - David Vitas";

    make_text_white(game->window, "MUSIQUE:", send_pos(520, 1080 - y), 40);
    make_text_white(game->window, start, send_pos(520, 1080 + 100 - y), 30);
    make_text_white(game->window, pause, send_pos(520, 1080 + 150 - y), 30);
    make_text_white(game->window, theme, send_pos(520, 1080 + 50 - y), 30);
}