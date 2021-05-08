/*
** EPITECH PROJECT, 2021
** lily
** File description:
** handle lily npc
*/

#include "rpg.h"

int check_lily_collision(sfVector2f cell, player_t *player)
{
    int value = 0;

    if (player->lily == 0)
        value = check_collide(cell, send_pos(15, 27), send_pos(15, 30));
    return (value);
}

void make_lily_function(game_t *game, player_t *player)
{
    if (game->adv.rondodu == 1)
        player->lily = 1;
}

static void handle_lily_pnj(npc_t *lily, game_t *game, player_t *player)
{
    char *press = "Press E to interact";

    if (player->lily == 1)
        return;
    sfRenderWindow_drawSprite(game->window, lily->spr, NULL);
    if (can_talk_to_npc(lily, player->pos)) {
        print_text(game->window, press, send_pos(800, 10), sfBlack);
        if (sfKeyboard_isKeyPressed(sfKeyE) == sfTrue)
            player->talk = sfTrue;
    }
    if (player->talk == sfTrue)
        handle_npc_interaction(lily, game, player, 0);
}

static void initialise_lily_text(npc_t *lily, game_t *game)
{
    lily->text = malloc(sizeof(char *) * (3));
    lily->text[0] = "Hugo: Tu penses que j ai mes chances pour la promotion ?";
    if (game->adv.rondodu == 0 || game->adv.rondodu == 2)
        lily->text[1] = "Lily: Nan, il te faut Rondoudou, sans lui c est mort";
    else
        lily->text[1] = "Lily: Ouais, vas-y, ensemble vous etes inarretable";
    lily->text[2] = NULL;
}

int initialise_lily(game_t *game, player_t *player)
{
    npc_t *lily;

    lily = malloc(sizeof(npc_t));
    lily->rect = send_rect(76, 49, 0, 0);
    lily->pixel = sfTexture_createFromFile("assets/npc/lily.png", &lily->rect);
    if (lily->pixel == NULL)
        return (put_game_error(game));
    lily->spr = sfSprite_create();
    set_pos(&lily->pos, 534, 826);
    sfSprite_setTexture(lily->spr, lily->pixel, sfTrue);
    sfSprite_setPosition(lily->spr, lily->pos);
    lily->opponent = make_lily_function;
    initialise_lily_text(lily, game);
    handle_lily_pnj(lily, game, player);
    destroy_npc(lily);
    return (0);
}