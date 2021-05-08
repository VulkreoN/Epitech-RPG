/*
** EPITECH PROJECT, 2021
** guard_npc
** File description:
** handle npc guard
*/


#include "rpg.h"
#include "fight.h"

int check_guard_collision(sfVector2f cell, player_t *player)
{
    int value = 0;

    value = check_collide(cell, send_pos(9, 8), send_pos(42, 8));
    if (player->guard == 1)
        value += check_collide(cell, send_pos(24, 24), send_pos(26, 26));
    return (value);
}

void guard_function(game_t *game, player_t *player)
{
    game->error = game->error;
    player->guard = 2;
}

static void handle_guard_pnj(npc_t *guard, game_t *game, player_t *player)
{
    char *press = "Press E to interact";

    if (game->adv.pops == 0 || player->guard == 2)
        return;
    sfRenderWindow_drawSprite(game->window, guard->spr, NULL);
    if (can_talk_to_npc(guard, player->pos)) {
        print_text(game->window, press, send_pos(800, 20), sfRed);
        if (sfKeyboard_isKeyPressed(sfKeyE) == sfTrue)
            player->talk = sfTrue;
    }
    if (player->talk == sfTrue)
        handle_npc_interaction(guard, game, player, 0);
}

static void initialise_guard_text(npc_t *guard)
{
    guard->text[0] = ("Garde: Arretez-vous ici, "
    "vous avez vole quoi aujourd'hui ? :)");
    guard->text[1] = "Hugo: Vous m'accusez de vol?";
    guard->text[2] = ("Hugo: Je porte plainte pour harcelement,"
    " diffamation et incitation a la haine.");
    guard->text[3] = ("Garde: G pa kompri du"
    " coup ticket de caisse tout de suite.");
    guard->text[4] = ("Hugo: Vous avez dit du coup vous n avez plus le"
    " droit a la parole. Bonne journee. Que Whanos vous guide.");
    guard->text[5] = NULL;
}

int initialise_guard(game_t *game, player_t *player)
{
    npc_t *guard;

    guard = malloc(sizeof(npc_t));
    guard->rect = send_rect(113, 78, 0, 0);
    guard->pixel = sfTexture_createFromFile("assets/npc/guard.png",
    &guard->rect);
    if (guard->pixel == NULL)
        return (put_game_error(game));
    guard->spr = sfSprite_create();
    set_pos(&guard->pos, 900, 700);
    sfSprite_setTexture(guard->spr, guard->pixel, sfTrue);
    sfSprite_setPosition(guard->spr, guard->pos);
    guard->opponent = guard_function;
    guard->text = malloc(sizeof(char *) * (6));
    initialise_guard_text(guard);
    handle_guard_pnj(guard, game, player);
    destroy_npc(guard);
    return (0);
}