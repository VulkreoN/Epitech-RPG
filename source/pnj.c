/*
** EPITECH PROJECT, 2021
** pnj
** File description:
** my_rpg
*/

#include "taya.h"
#include <math.h>
#include "fight.h"
#include <SFML/Graphics.h>

void print_pnj(sfRenderWindow *window, pnj_t *pnj_t, int *indexScreen)
{
    sfTexture* font;
    sfSprite* sp_font;
    sfIntRect take = {0, 0, 82, 120};
    sfVector2f pos = {0};
    sfVector2f size = {0.25, 0.25};

    pos.x = (pnj_t->cell.x) * WIDTH;
    pos.y = (pnj_t->cell.y) * HEIGHT;
    pos.x = (pos.x * 2.4) + 10;
    pos.y *= 1.7;
    if (*indexScreen == pnj_t->indexMap) {
        font = sfTexture_createFromFile("assets/pnj.png", &take);
        sp_font = sfSprite_create();
        sfSprite_setTexture(sp_font, font, sfTrue);
        sfSprite_move(sp_font, pos);
        sfSprite_setScale(sp_font, size);
        sfRenderWindow_drawSprite(window, sp_font, NULL);
        sfTexture_destroy(font);
        sfSprite_destroy(sp_font);
    }
}

void print_dia(char *path, sfVector2f pos,
sfRenderWindow *window)
{
    sfTexture* font;
    sfSprite* sp_font;
    sfVector2f size = {1, 1};

    font = sfTexture_createFromFile(path, NULL);
    sp_font = sfSprite_create();
    sfSprite_setTexture(sp_font, font, sfTrue);
    sfSprite_move(sp_font, pos);
    sfSprite_setScale(sp_font, size);
    sfRenderWindow_drawSprite(window, sp_font, NULL);
    sfTexture_destroy(font);
    sfSprite_destroy(sp_font);
}

sfBool can_interact(sfVector2f cell1)
{
    if (check_collide(cell1, send_pos(20, 17), (send_pos(22, 20))))
        return (sfTrue);
    return (sfFalse);
}

static void make_pnj_interaction(player_t *player, map_t *map, game_t *game)
{
    if ((sfKeyboard_isKeyPressed(sfKeyEnter) == sfTrue
    && map->pnj_t->isTalking == sfTrue)) {
        map->pnj_t->isTalking = sfFalse;
        destroy_music(game);
        fight_with_maxence(game, player);
        assign_music(game, 4);
    } else if (player->isMoving)
        map->pnj_t->isTalking = sfFalse;
}

void interact(game_t *game, player_t *player_t, map_t *map)
{
    sfVector2f pos = {800, 20};
    sfVector2f dia = {300, 800};
    sfVector2f dia2 = {0, 763};

    if (can_interact(player_t->cell)
    && map->indexScreen == 1) {
        print_text(game->window, "Press E to interact", pos, sfRed);
        if (sfKeyboard_isKeyPressed(sfKeyE) == sfTrue)
            map->pnj_t->isTalking = sfTrue;
        if (map->pnj_t->isTalking == sfTrue) {
            print_dia("assets/dia.jpg", dia2, game->window);
            print_text(game->window, map->pnj_t->text, dia, sfBlack);
        }
        make_pnj_interaction(player_t, map, game);
    }
    if (map->pnj_t->isTalking == sfTrue && map->indexScreen == 1) {
        print_dia("assets/dia.jpg", dia2, game->window);
        print_text(game->window, map->pnj_t->text, dia, sfBlack);
    }
}