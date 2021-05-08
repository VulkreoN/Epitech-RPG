/*
** EPITECH PROJECT, 2021
** true rondoudou
** File description:
** handle true rondoudou
*/

#include "rpg.h"

void make_rondoudou_function(game_t *game, player_t *player)
{
    game->adv.rondoudou = 1;
    player->attack = player->attack;
}

static void handle_rondoudou_pnj(npc_t *rondoudou,
game_t *game, player_t *player)
{
    char *press = "Press E to interact";

    if (game->adv.rondodu != 1 || game->adv.rondoudou != 0)
        return;
    sfRenderWindow_drawSprite(game->window, rondoudou->spr, NULL);
    if (can_talk_to_npc(rondoudou, player->pos)) {
        print_text(game->window, press, send_pos(800, 20), sfRed);
        if (sfKeyboard_isKeyPressed(sfKeyE) == sfTrue)
            player->talk = sfTrue;
    }
    if (player->talk == sfTrue)
        handle_npc_interaction(rondoudou, game, player, 0);
}

static void initialise_rondoudou_text(npc_t *rondoudou)
{
    rondoudou->text = malloc(sizeof(char *) * (7));
    rondoudou->text[0] = "Hugo: Rondoudou ? Mon Rondoudou ?";
    rondoudou->text[1] = "Rondoudou: Rondoudou Rondou Rondoudou Rondoudou";
    rondoudou->text[2] = ("Hugo: Alors pendant tout ce"
    " temps tu etais en vacances");
    rondoudou->text[3] = "Rondoudou: Rondou Rondoudou Rondou Rondoudou";
    rondoudou->text[4] = "Hugo: Moi aussi je suis content de te revoir !";
    rondoudou->text[5] = ("Hugo: Il est enfin temps d'aller negocier"
    " cette promotion. En route vers la salle pedago Rondoudou !");
    rondoudou->text[6] = NULL;
}

int initialise_rondoudou(game_t *game, player_t *player)
{
    npc_t *rdd;

    rdd = malloc(sizeof(npc_t));
    rdd->rect = send_rect(67, 66, 0, 0);
    rdd->pixel = sfTexture_createFromFile("assets/inventory/rondoudou.png",
    &rdd->rect);
    if (rdd->pixel == NULL)
        return (put_game_error(game));
    rdd->spr = sfSprite_create();
    set_pos(&rdd->pos, 530, 460);
    sfSprite_setTexture(rdd->spr, rdd->pixel, sfTrue);
    sfSprite_setPosition(rdd->spr, rdd->pos);
    initialise_rondoudou_text(rdd);
    rdd->opponent = make_rondoudou_function;
    handle_rondoudou_pnj(rdd, game, player);
    destroy_npc(rdd);
    return (0);
}