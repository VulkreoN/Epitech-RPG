/*
** EPITECH PROJECT, 2021
** B-MUL-200-TLS-2-1-myrpg-johann.sako
** File description:
** create_save
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "taya.h"
#include "rpg.h"

static const int EPI_ERROR = 84;
static const int NO_ERROR = 0;

static int create_new_file(int fd, char const *filepath)
{
    mode_t mode = S_IRUSR | S_IRGRP | S_IROTH;

    close(fd);
    remove(filepath);
    fd = open(filepath, O_WRONLY | O_CREAT | O_TRUNC, mode);
    return fd;
}

int create_save(player_t *player, game_t *game, map_t *map)
{
    char const *filepath = ".save";
    mode_t mode = S_IRUSR | S_IRGRP | S_IROTH;
    int open_status = open(filepath, O_WRONLY | O_CREAT, mode);

    open_status = create_new_file(open_status, filepath);
    destroy_music(game);
    if (open_status == -1)
        return EPI_ERROR;
    my_ldprintf(open_status, "%d\n%d\n%d\n%d\n%d\n%d\n"
    , player->attack, player->defense, player->money, player->lily
    , (int)player->cell.x, (int)player->cell.y);
    my_ldprintf(open_status, "%d\n", map->indexScreen);
    my_ldprintf(open_status, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d",
    game->adv.covid, game->adv.jerome, game->adv.maxence, game->adv.pops
    , game->adv.rondodu, game->adv.rondoudou, game->adv.wise, game->intro);
    my_ldprintf(1, "GAME SAVED\n");
    close(open_status);
    return NO_ERROR;
}