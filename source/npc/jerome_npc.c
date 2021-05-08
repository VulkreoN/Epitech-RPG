/*
** EPITECH PROJECT, 2021
** jerome_npc
** File description:
** handle jerome npc
*/

#include "rpg.h"
#include "fight.h"

static void handle_jerome_pnj(npc_t *jerome, game_t *game, player_t *player)
{
    char *press = "Press E to interact";

    if (game->adv.jerome == 1)
        return;
    sfRenderWindow_drawSprite(game->window, jerome->spr, NULL);
    if (can_talk_to_npc(jerome, player->pos)) {
        print_text(game->window, press, send_pos(800, 20), sfRed);
        if (sfKeyboard_isKeyPressed(sfKeyE) == sfTrue)
            player->talk = sfTrue;
    }
    if (player->talk == sfTrue)
        handle_npc_interaction(jerome, game, player, 1);
}

static void initialise_jerome_text(npc_t *jerome)
{
    jerome->text[0] = "Hugo: Salut Jerome je suis ici pour ma promotion";
    jerome->text[1] = "Jerome: Prouve moi que tu la merites !";
    jerome->text[2] = NULL;
}

int initialise_jerome(game_t *game, player_t *player)
{
    npc_t *jerome;

    jerome = malloc(sizeof(npc_t));
    jerome->rect = send_rect(76, 49, 0, 0);
    jerome->pixel = sfTexture_createFromFile("assets/npc/jerome.png",
    &jerome->rect);
    if (jerome->pixel == NULL)
        return (put_game_error(game));
    jerome->spr = sfSprite_create();
    set_pos(&jerome->pos, 546, 266);
    sfSprite_setTexture(jerome->spr, jerome->pixel, sfTrue);
    sfSprite_setPosition(jerome->spr, jerome->pos);
    jerome->opponent = fight_with_jerome;
    jerome->text = malloc(sizeof(char *) * (3));
    initialise_jerome_text(jerome);
    handle_jerome_pnj(jerome, game, player);
    destroy_npc(jerome);
    return (0);
}