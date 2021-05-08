/*
** EPITECH PROJECT, 2021
** handle_npc
** File description:
** handle npc
*/

#include "rpg.h"

void destroy_npc(npc_t *npc)
{
    sfTexture_destroy(npc->pixel);
    sfSprite_destroy(npc->spr);
    free(npc->text);
    free(npc);
}

static sfBool check_player_is_moving(void)
{
    if (sfKeyboard_isKeyPressed(sfKeyUp)
    || sfKeyboard_isKeyPressed(sfKeyDown)
    || sfKeyboard_isKeyPressed(sfKeyLeft)
    || sfKeyboard_isKeyPressed(sfKeyRight))
        return (sfTrue);
    return (sfFalse);
}

void handle_npc_interaction(npc_t *npc, game_t *game,
player_t *player, sfBool fight)
{
    print_dia("assets/dia.jpg", send_pos(0, 763), game->window);
    if (npc->text[game->talk] != NULL)
        print_text(game->window, npc->text[game->talk],
        send_pos(300, 800), sfBlack);
    check_wise_class(game, npc);
    if (sfKeyboard_isKeyPressed(sfKeyEnter) && game->key && game->wise == 0)
        game->talk += 1;
    else if (check_player_is_moving()) {
        player->talk = sfFalse;
        game->talk = 0;
        game->wise = 0;
    }
    if (npc->text[game->talk] == NULL && npc->opponent != NULL) {
        if (fight)
            start_fight_with_music(game, player, npc->opponent);
        else
            npc->opponent(game, player);
        player->talk = sfFalse;
        game->talk = 0;
    }
}

int handle_npc(game_t *game, player_t *player, map_t *map)
{
    switch (map->indexScreen) {
        case 2:
            return (initialise_covid(game, player));
        case 3:
            return (initialise_wise(game, player));
        case 4:
            initialise_pops(game, player);
            return (initialise_guard(game, player));
        case 5:
            return (initialise_lily(game, player));
        case 6:
            initialise_rondodu(game, player);
            return (initialise_rondoudou(game, player));
        case 7:
            return (initialise_jerome(game, player));
        default:
            break;
    }
    return (0);
}

sfBool can_talk_to_npc(npc_t *npc, sfVector2f pos)
{
    sfVector2u size;

    size.x = npc->rect.width;
    size.y = npc->rect.height;
    if ((pos.x >= npc->pos.x - 40 && pos.x <= (npc->pos.x + size.x) + 20)
    && (pos.y >= npc->pos.y - 40 && pos.y <= (npc->pos.y + size.y) + 20))
        return (sfTrue);
    return (sfFalse);
}