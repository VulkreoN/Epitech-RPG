/*
** EPITECH PROJECT, 2021
** mouse_handling
** File description:
** handle mouse
*/

#include "../../../../include/taya.h"
#include "../../../../include/rpg.h"

int check_mouse_on_button(object_t *object, sfVector2i mouse, game_t *game)
{
    int nb = 0;

    if (mouse.x >= object->pos.x && mouse.x <= object->pos.x + object->size.x
    && mouse.y >= object->pos.y && mouse.y <= object->pos.y + object->size.y) {
        nb = 1;
        if (game->mouse == 1)
            nb += 1;
    }
    return (nb);
}

void make_play_pause_redirection(game_t *game, settings_t *param)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(game->window);
    int mouse_on_button = check_mouse_on_button(param->play, mouse_pos, game);

    if (game->play_pause == 0)
        mouse_on_button += 3;
    change_sprite(param->play, mouse_on_button);
    sfRenderWindow_drawSprite(game->window, param->play->spr, NULL);
}

void make_redirection(game_t *game, object_t *object)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(game->window);
    int mouse_on_button = check_mouse_on_button(object, mouse_pos, game);

    change_sprite(object, mouse_on_button);
    sfRenderWindow_drawSprite(game->window, object->spr, NULL);
}

void mouse_handling(game_t *game, sfEvent event)
{
    if (event.type == sfEvtMouseButtonPressed)
        game->mouse = 1;
    else if (event.type == sfEvtMouseButtonReleased && game->mouse == 1)
        game->mouse = 2;
}