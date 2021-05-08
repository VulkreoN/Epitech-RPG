/*
** EPITECH PROJECT, 2021
** pops
** File description:
** npc pops
*/

#include "rpg.h"
#include "fight.h"

static void handle_pops_pnj(npc_t *pops, game_t *game, player_t *player)
{
    char *press = "Press E to interact";

    if (game->adv.pops != 0)
        return;
    sfRenderWindow_drawSprite(game->window, pops->spr, NULL);
    if (can_talk_to_npc(pops, player->pos)) {
        print_text(game->window, press, send_pos(800, 20), sfRed);
        if (sfKeyboard_isKeyPressed(sfKeyE) == sfTrue)
            player->talk = sfTrue;
    }
    if (player->talk == sfTrue)
        handle_npc_interaction(pops, game, player, 1);
}

static void initialise_pops_text(npc_t *pops)
{
    pops->text[0] = "Miel Pops: Le Soleil nous reveille..";
    pops->text[1] = "Hugo: Euh bonjour ?";
    pops->text[2] = "Miel Pops: il fait beau il fait jour..";
    pops->text[3] = "Hugo: Allo ?";
    pops->text[4] = "Miel Pops: C'est le moment pour..";
    pops->text[5] = "Miel Pops: MIEL POPS !";
    pops->text[6] = NULL;
}

int initialise_pops(game_t *game, player_t *player)
{
    npc_t *pops;

    pops = malloc(sizeof(npc_t));
    pops->rect = send_rect(66, 67, 0, 0);
    pops->pixel = sfTexture_createFromFile("assets/inventory/pops.png",
    &pops->rect);
    if (pops->pixel == NULL)
        return (put_game_error(game));
    pops->spr = sfSprite_create();
    set_pos(&pops->pos, 400, 439);
    sfSprite_setTexture(pops->spr, pops->pixel, sfTrue);
    sfSprite_setPosition(pops->spr, pops->pos);
    pops->opponent = fight_with_miel_pops;
    pops->text = malloc(sizeof(char *) * (7));
    initialise_pops_text(pops);
    handle_pops_pnj(pops, game, player);
    destroy_npc(pops);
    return (0);
}