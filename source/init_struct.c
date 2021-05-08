/*
** EPITECH PROJECT, 2021
** init_struct
** File description:
** myRPG
*/

#include "taya.h"
#include "rpg.h"
#include <SFML/Graphics.h>
#include <stdlib.h>

void initi_time(t_timeManager *timeManager, int binairy)
{
    t_clock *clock = &timeManager->clock;

    if (binairy == 0) {
        clock->clock = sfClock_create();
        timeManager->i_timeStamp_lastFrame =
        gettime(clock->time, clock->clock);
        timeManager->i_timeStamp_currentFrame = 0;
        timeManager->i_deltaTime = 0;
    }
    if (binairy == 1) {
        timeManager->i_timeStamp_currentFrame =
        gettime(clock->time, clock->clock);
        timeManager->i_deltaTime =
        timeManager->i_timeStamp_currentFrame -
        timeManager->i_timeStamp_lastFrame;
        timeManager->i_timeStamp_lastFrame =
        timeManager->i_timeStamp_currentFrame;
    }
}

void init_pnj(pnj_t *pnj_t, map_t *map_t)
{
    pnj_t->cell.x = 20;
    pnj_t->cell.y = 20;
    map_t->line[20].colone[20].isEmpty = sfFalse;
    map_t->line[21].colone[20].isEmpty = sfFalse;
    pnj_t->indexMap = 1;
    pnj_t->text = "Maxence: Yo c'est Maxence, entraine toi en m'affrontant !";
}

void fill_cell(int a, int b, map_t *map_t, sfIntRect *area)
{
    float x = 0;
    float y = 0;

    x = (WIDTH * b) * 2.4;
    y = (HEIGHT * a) * 1.8;
    set_pos(&map_t->line[a].colone[b].pos, x, y);
    map_t->line[a].colone[b].texture =
    sfTexture_createFromFile(map_t->line[a].colone[b].path, area);
}

void init_screen(map_t *map_t)
{
    int c = 0;
    char path[] = "maps/map1";
    char *string = malloc(sizeof(char) * 2);

    path[8] = map_t->indexScreen + 48;
    if (map_t->indexScreen == 1) {
        map_t->path = "assets/map/house_floor.jpg";
    } else if (map_t->indexScreen == 2)
        map_t->path = "assets/map/fleurs.png";
    map_t->sol = sfTexture_createFromFile(map_t->path, NULL);
    map_t->buffer = getbuffer(path);
    for (int a = 0; a < 37; a++) {
        for (int b = 0; b < 50; b++) {
            if (map_t->buffer[c] == '\n' || map_t->buffer[c] == 44)
                c++;
            get_string(map_t->buffer, &c, string);
            make_house(map_t, a, b, string);
            make_outside(map_t, a, b, string);
        }
    }
    free(string);
}

void init_map(map_t *map_t)
{
    map_t->indexScreen = 1;
    init_screen(map_t);
    init_pnj(&map_t->pnj_t[0], map_t);
}