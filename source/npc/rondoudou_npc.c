/*
** EPITECH PROJECT, 2021
** rondodu_npc
** File description:
** handle rondodu
*/

#include "rpg.h"
#include "fight.h"

static void handle_rondodu_pnj(npc_t *rondodu, game_t *game, player_t *player)
{
    char *press = "Press E to interact";

    if (game->adv.rondodu == 1)
        return;
    sfRenderWindow_drawSprite(game->window, rondodu->spr, NULL);
    if (can_talk_to_npc(rondodu, player->pos)) {
        print_text(game->window, press, send_pos(800, 20), sfRed);
        if (sfKeyboard_isKeyPressed(sfKeyE) == sfTrue)
            player->talk = sfTrue;
    }
    if (player->talk == sfTrue)
        handle_npc_interaction(rondodu, game, player, 1);
}

static void initialise_rondodu_text(npc_t *rondodu)
{
    rondodu->text = malloc(sizeof(char *) * (5));
    rondodu->text[0] = "Rondodu: Rondodu Rondoo Rondodu Rondodu HuHo";
    rondodu->text[1] = "Hugo: Ou est le vrai Rondoudou ?!";
    rondodu->text[2] = "Rondodu: Rondodu Rondoo Rondodu Rondodu HuHo";
    rondodu->text[3] = "Hugo: Tu ne me laisses pas le choix Rondodu !";
    rondodu->text[4] = NULL;
}

int initialise_rondodu(game_t *game, player_t *player)
{
    npc_t *rondodu;

    rondodu = malloc(sizeof(npc_t));
    rondodu->rect = send_rect(131, 139, 0, 0);
    rondodu->pixel = sfTexture_createFromFile("assets/npc/rondodu.png",
    &rondodu->rect);
    if (rondodu->pixel == NULL)
        return (put_game_error(game));
    rondodu->spr = sfSprite_create();
    set_pos(&rondodu->pos, 518, 439);
    sfSprite_setTexture(rondodu->spr, rondodu->pixel, sfTrue);
    sfSprite_setPosition(rondodu->spr, rondodu->pos);
    initialise_rondodu_text(rondodu);
    rondodu->opponent = fight_with_rondodu;
    handle_rondodu_pnj(rondodu, game, player);
    destroy_npc(rondodu);
    return (0);
}