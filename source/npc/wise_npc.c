/*
** EPITECH PROJECT, 2021
** wise
** File description:
** wise npc
*/

#include "rpg.h"

static const int key[3] = {
    0,
    6,
    12
};

void check_wise_class(game_t *game, npc_t *npc)
{
    int check = 0;

    if (my_strcmp(npc->text[game->talk],
    ("Albus Gandalf: \nTapez sur A pour la classe Assassin"
    "\nTapez sur G pour la classe Guerrier\n Tapez sur M pour la classe Mage"
    "\nTapez sur ENTRER pour la classe Prof de Francais")) != 0)
        return;
    for (int inc = 0; inc < 3; inc++) {
        if (sfKeyboard_isKeyPressed(key[inc]) && game->key) {
            handle_wise_bad_class(game, key[inc], 0);
            check = 1;
        }
    }
    if (game->wise != 0)
        handle_wise_bad_class(game, game->wise - 1, 1);
    if (check == 0 && (sfKeyboard_isKeyPressed(sfKeyEnter) && game->key))
        game->wise = 0;
}

void wise_function(game_t *game, player_t *player)
{
    game->adv.wise = 1;
    player->guard = player->guard;
}

static void handle_wise_pnj(npc_t *wise, game_t *game, player_t *player)
{
    char *press = "Press E to interact";

    sfRenderWindow_drawSprite(game->window, wise->spr, NULL);
    if (can_talk_to_npc(wise, player->pos)) {
        print_text(game->window, press, send_pos(800, 20), sfRed);
        if (sfKeyboard_isKeyPressed(sfKeyE) == sfTrue)
            player->talk = sfTrue;
    }
    if (player->talk == sfTrue)
        handle_npc_interaction(wise, game, player, 0);
}

static void initialise_basic_wise_text(npc_t *wise)
{
    wise->text = malloc(sizeof(char *) * (11));
    wise->text[0] = ("???: Il semblerait que vous soyez "
    "perdu dans votre aventure");
    wise->text[1] = "Hugo: Non";
    wise->text[2] = ("???: Mon nom vous dites ? Je me nomme Albus Gandalf"
    " et je suis ici pour vous soutenir dans votre aventure");
    wise->text[3] = "Hugo: Passionant, aurevoir";
    wise->text[4] = ("Albus Gandalf: Il est maintenant temps pour vous de"
    " choisir votre classe !");
    wise->text[5] = "Hugo: Attends attends serieux ? Je peux choisir ?";
    wise->text[6] = ("Albus Gandalf: \nTapez sur A pour la classe Assassin"
    "\nTapez sur G pour la classe Guerrier\n Tapez sur M pour la classe Mage"
    "\nTapez sur ENTRER pour la classe Prof de Francais");
    wise->text[7] = ("Albus Gandalf: Vous etes bien sur de vous ?"
    " Tapez de nouveau sur la meme touche pour valider");
    wise->text[8] =  ("Albus Gandalf: Je ne m'attendais pas a un tel"
    " choix de votre part. Pourquoi pas.");
    wise->text[9] = "Hugo: ...";
    wise->text[10] = NULL;
}

int initialise_wise(game_t *game, player_t *player)
{
    npc_t *wise;

    wise = malloc(sizeof(npc_t));
    wise->rect = send_rect(80, 50, 0, 0);
    wise->pixel = sfTexture_createFromFile("assets/npc/sage.png", &wise->rect);
    if (wise->pixel == NULL)
        return (put_game_error(game));
    wise->spr = sfSprite_create();
    set_pos(&wise->pos, 580, 320);
    sfSprite_setTexture(wise->spr, wise->pixel, sfTrue);
    sfSprite_setPosition(wise->spr, wise->pos);
    wise->opponent = wise_function;
    if (game->adv.wise == 0)
        initialise_basic_wise_text(wise);
    else {
        wise->text = malloc(sizeof(char * ) * (5));
        handle_wise_test(wise, game);
    }
    handle_wise_pnj(wise, game, player);
    destroy_npc(wise);
    return (0);
}