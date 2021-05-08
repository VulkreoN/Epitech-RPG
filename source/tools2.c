/*
** EPITECH PROJECT, 2021
** tools2
** File description:
** RPG
*/

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "../include/taya.h"
#include "../include/rpg.h"

char *getbuffer(char *arg)
{
    int fd = open(arg, O_RDONLY);
    char *buffer = NULL;
    buffer = malloc(sizeof(char) * 8000);

    if (fd <= 1) {
        return ("84");
    }
    if (read(fd, buffer, 8000) == -1) {
        return ("84");
    }
    close(fd);
    return (buffer);
}

void print_cell(sfVector2f *pos, sfRenderWindow *window, sfTexture *texture)
{
    sfSprite* sp_font;
    sfVector2f factors = {2.4, 1.8};

    sp_font = sfSprite_create();
    sfSprite_setTexture(sp_font, texture, sfTrue);
    sfSprite_scale(sp_font, factors);
    sfSprite_move(sp_font, *pos);
    sfRenderWindow_drawSprite(window, sp_font, NULL);
    sfSprite_destroy(sp_font);
}