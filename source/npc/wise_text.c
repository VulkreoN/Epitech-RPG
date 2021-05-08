/*
** EPITECH PROJECT, 2021
** wise_text
** File description:
** handle wise text
*/

#include "rpg.h"

static char *get_class_text(int key)
{
    if (key == 0)
        return ("ERREUR : Tu n'es pas assez malin !");
    else if (key == 6)
        return ("ERREUR : Tu n'es pas assez fort !");
    else
        return ("ERREUR : Tu crois vraiment que la\nmagie existe ?");
}

int handle_wise_bad_class(game_t *game, int key, sfBool display)
{
    sfTexture *pixel = NULL;
    sfSprite *spr = NULL;

    game->wise = key + 1;
    if (!display)
        return (0);
    pixel = sfTexture_createFromFile("assets/npc/warn.png", NULL);
    if (pixel == NULL)
        return (put_game_error(game));
    spr = sfSprite_create();
    sfSprite_setTexture(spr, pixel, sfTrue);
    sfSprite_setPosition(spr, send_pos(710, 353));
    sfRenderWindow_drawSprite(game->window, spr, NULL);
    make_text(game->window, get_class_text(key), send_pos(730, 600), 25);
    sfTexture_destroy(pixel);
    sfSprite_destroy(spr);
    return (0);
}

static void handle_wise_text_rondodu(npc_t *wise, game_t *game)
{
    if (game->adv.rondodu == 0) {
        wise->text[3] = ("Albus Gandalf: Oublies pas de recuperer ton Rondoudou"
        " je viens de le voir entrer dans Epitech");
    } else if (game->adv.rondodu == 1) {
        wise->text[3] = ("Albus Gandalf: Tu as recupere Rondoudou bravo ! Il"
        " est maintenant temps pour toi d en finir avec la quete principale\n"
        " et d'aller recuperer ta promotion\naupres de Jerome dans la salle "
        "pedago");
    } else {
        wise->text[3] = ("Albus Gandalf: Tu n'as pas recupere Rondoudou !"
        "Tu n as plus aucune chance de reussir maintenant, tout est perdu !");
    }
    wise->text[4] = NULL;
}

void handle_wise_test(npc_t *wise, game_t *game)
{
    wise->text[0] = "Albus Gandalf: Tu veux des infos sur ton avance ?";
    if (game->adv.covid == 0) {
        wise->text[1] = ("Albus Gandalf: Oublies pas d'affronter le Covid, "
        "il est en haut");
    } else if (game->adv.covid == 1) {
        wise->text[1] = ("Albus Gandalf: Tu ne serais pas cas contact toi ?"
        " Oh mais t as vaincu le Covid, bravo !");
    } else {
        wise->text[1] = ("Albus Gandalf: Tu pourrais faire l effort de mettre"
        " un masque ! Oh et de desinfecter ton inventaire tant que tu y es");
    }
    if (game->adv.pops == 0) {
        wise->text[2] = ("Albus Gandalf: Va a Carrefour si tu veux faire la "
        "quete secondaire. Oh et depeche toi elle me casse les oreilles !");
    } else if (game->adv.pops == 1) {
        wise->text[2] = ("Albus Gandalf: Tu as reussi la quete secondaire ?\n"
        "Mes oreilles revivent merci !\nTu as Miel Pops dans ton inventaire");
    } else {
        wise->text[2] = ("Albus Gandalf: Bon tu as echoue a la quete secondair"
        "e mais au moins elle est plus la pour nous casser les timpans");
    } handle_wise_text_rondodu(wise, game);
}