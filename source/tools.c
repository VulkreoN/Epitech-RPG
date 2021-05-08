/*
** EPITECH PROJECT, 2021
** tools
** File description:
** myRPG
*/

#include "../include/taya.h"
#include "../include/rpg.h"
#include <SFML/Graphics.h>
#include <math.h>
#include <stdlib.h>

int gettime(sfTime time, sfClock *clock)
{
    int mseconds;

    time = sfClock_getElapsedTime(clock);
    mseconds = time.microseconds / 1000;
    return (mseconds);
}

void print_map(map_t *map_t, game_t *game)
{
    sfVector2f pos = {0};

    for (int a = 0; a < 37; a++) {
        for (int b = 0; b < 50; b++) {
            set_pos(&pos, (WIDTH * b) * 2.4, (HEIGHT * a) * 1.8);
            print_cell(&pos, game->window, map_t->sol);
            print_cell(&map_t->line[a].colone[b].pos,
game->window, map_t->line[a].colone[b].texture);
        }
    }
    if (map_t->indexScreen > 2) {
        sfRenderWindow_clear(game->window, sfBlack);
        display_map(game, map_t);
    }
}

void print_sprite(char *path, player_t *player_t, sfVector2f size,
sfRenderWindow *window)
{
    sfTexture* font;
    sfSprite* sp_font;
    sfVector2f pos = {0};

    pos.x = ceilf((player_t->cell.x + 0.5) * WIDTH - player_t->take.height);
    pos.y = ceilf((player_t->cell.y + 0.5) * HEIGHT -
player_t->take.width * 0.5);
    pos.x *= 2.4;
    pos.y *= 1.8;
    font = sfTexture_createFromFile(path, &player_t->take);
    sp_font = sfSprite_create();
    sfSprite_setTexture(sp_font, font, sfTrue);
    sfSprite_move(sp_font, pos);
    player_t->pos = sfSprite_getPosition(sp_font);
    sfSprite_setScale(sp_font, size);
    sfRenderWindow_drawSprite(window, sp_font, NULL);
    sfTexture_destroy(font);
    sfSprite_destroy(sp_font);
}

void print_text(sfRenderWindow* window, char *text, sfVector2f pos,
sfColor color)
{
    sfText* score;
    sfFont* font;
    int size = 25;

    score = sfText_create();
    font = sfFont_createFromFile("assets/fonts/write.ttf");
    sfText_setString(score, text);
    sfText_setFont(score, font);
    sfText_setCharacterSize(score, size);
    sfText_setColor(score, color);
    sfText_move(score, pos);
    sfRenderWindow_drawText(window, score, NULL);
    sfText_destroy(score);
    sfFont_destroy(font);
}