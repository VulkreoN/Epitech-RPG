/*
** EPITECH PROJECT, 2021
** covid pnj
** File description:
** handle covid pnj
*/

#include "rpg.h"
#include "fight.h"

static void handle_covid_pnj(npc_t *covid, game_t *game, player_t *player)
{
    char *press = "Press E to interact";

    if (game->adv.covid != 0)
        return;
    sfRenderWindow_drawSprite(game->window, covid->spr, NULL);
    if (can_talk_to_npc(covid, player->pos)) {
        print_text(game->window, press, send_pos(800, 20), sfBlack);
        if (sfKeyboard_isKeyPressed(sfKeyE) == sfTrue)
            player->talk = sfTrue;
    }
    if (player->talk == sfTrue)
        handle_npc_interaction(covid, game, player, 1);
}

int initialise_covid(game_t *game, player_t *player)
{
    npc_t *covid;

    covid = malloc(sizeof(npc_t));
    covid->rect = send_rect(420, 360, 25, 0);
    covid->pixel = sfTexture_createFromFile("assets/Le_covid.png",
    &covid->rect);
    if (covid->pixel == NULL)
        return (put_game_error(game));
    covid->spr = sfSprite_create();
    set_pos(&covid->pos, 300, 300);
    sfSprite_setTexture(covid->spr, covid->pixel, sfTrue);
    sfSprite_setPosition(covid->spr, covid->pos);
    covid->opponent = fight_with_covid;
    covid->text = malloc(sizeof(char *) * (2));
    covid->text[0] = "LE Covid: C'etait bien 2020 ?";
    covid->text[1] = NULL;
    handle_covid_pnj(covid, game, player);
    destroy_npc(covid);
    return (0);
}