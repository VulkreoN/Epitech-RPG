/*
** EPITECH PROJECT, 2021
** make_text
** File description:
** handle text making
*/

#include "taya.h"

void make_text(sfRenderWindow *window, char *str, sfVector2f pos, int size)
{
    sfText *text;
    sfFont *font;

    font = sfFont_createFromFile("assets/fonts/write.ttf");
    text = sfText_create();
    sfText_setString(text, str);
    sfText_setFont(text, font);
    sfText_setColor(text, sfColor_fromRGB(0, 0, 0));
    sfText_setCharacterSize(text, size);
    sfText_setPosition(text, pos);
    sfRenderWindow_drawText(window, text, NULL);
    sfText_destroy(text);
}

void make_text_white(sfRenderWindow *window, char *str,
sfVector2f pos, int size)
{
    sfText *text;
    sfFont *font;

    font = sfFont_createFromFile("assets/fonts/write.ttf");
    text = sfText_create();
    sfText_setString(text, str);
    sfText_setFont(text, font);
    sfText_setColor(text, sfWhite);
    sfText_setCharacterSize(text, size);
    sfText_setPosition(text, pos);
    sfRenderWindow_drawText(window, text, NULL);
    sfText_destroy(text);
}