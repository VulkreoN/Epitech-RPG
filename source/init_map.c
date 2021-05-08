/*
** EPITECH PROJECT, 2021
** init_mat
** File description:
** my_rpg
*/

#include "taya.h"
#include "rpg.h"
#include <SFML/Graphics.h>
#include <stdlib.h>

enum house_furniture check_enum(char *string)
{
    enum house_furniture cell = 84;

    if (my_strcmp(string, "t1") == 0)
        cell = CANAPE_TL;
    if (my_strcmp(string, "t2") == 0)
        cell = CANAPE_TM;
    if (my_strcmp(string, "t3") == 0)
        cell = CANAPE_TR;
    if (my_strcmp(string, "b1") == 0)
        cell = CANAPE_BL;
    if (my_strcmp(string, "b2") == 0)
        cell = CANAPE_BM;
    if (my_strcmp(string, "b3") == 0)
        cell = CANAPE_BR;
    if (my_strcmp(string, "b3") == 0)
        cell = CANAPE_BR;
    if (my_strcmp(string, "c1") == 0)
        cell = CARPET1_TL;
    if (my_strcmp(string, "c2") == 0)
        cell = CARPET1_TM;
    if (my_strcmp(string, "c3") == 0)
        cell = CARPET1_TR;
    if (my_strcmp(string, "m1") == 0)
        cell = CARPET1_ML;
    if (my_strcmp(string, "m2") == 0)
        cell = CARPET1_MM;
    if (my_strcmp(string, "m3") == 0)
        cell = CARPET1_MR;
    if (my_strcmp(string, "d1") == 0)
        cell = CARPET1_BL;
    if (my_strcmp(string, "d2") == 0)
        cell = CARPET1_BM;
    if (my_strcmp(string, "d3") == 0)
        cell = CARPET1_BR;
    if (my_strcmp(string, "l1") == 0)
        cell = TABLE_TL;
    if (my_strcmp(string, "l2") == 0)
        cell = TABLE_TR;
    if (my_strcmp(string, "a1") == 0)
        cell = TABLE_BL;
    if (my_strcmp(string, "a2") == 0)
        cell = TABLE_BR;
    if (my_strcmp(string, "h1") == 0)
        cell = CHAIR;
    if (my_strcmp(string, "r1") == 0)
        cell = DRACO_TL;
    if (my_strcmp(string, "r2") == 0)
        cell = DRACO_TR;
    if (my_strcmp(string, "f1") == 0)
        cell = DRACO_BL;
    if (my_strcmp(string, "f2") == 0)
        cell = DRACO_BR;
    if (my_strcmp(string, "e1") == 0)
        cell = TREE_T;
    if (my_strcmp(string, "e2") == 0)
        cell = TREE_B;
    if (my_strcmp(string, "k1") == 0)
        cell = DESK_T;
    if (my_strcmp(string, "k2") == 0)
        cell = DESK_M;
    if (my_strcmp(string, "k3") == 0)
        cell = DESK_B;
    return (cell);
}

void fill_struct(sfBool isEmpty, char *path, colone_t *cell)
{
    cell->isEmpty = isEmpty;
    cell->path = path;
}

void make_house(map_t *map_t, int a, int b, char *string)
{
    if (my_strcmp(string, "06") == 0) {
        map_t->line[a].colone[b].isEmpty = sfFalse;
        map_t->line[a].colone[b].path = "assets/map/black.jpg";
        fill_cell(a, b, map_t, NULL);
    }
    if (my_strcmp(string, "03") == 0) {
        map_t->line[a].colone[b].isEmpty = sfTrue;
        map_t->line[a].colone[b].path = "assets/map/house_floor.jpg";
        fill_cell(a, b, map_t, NULL);
    }
    make_furniture(map_t, a, b, string);
}

void make_outside(map_t *map_t, int a, int b, char *string)
{
    colone_t *cell = &map_t->line[a].colone[b];
    sfIntRect area = {0, 0, 16, 16};
    sfBool find_object = sfTrue;

    switch (enum_outside(string)) {
        case(HOUSE):
            built_house(cell, a, b, map_t);
            find_object = sfFalse;
            break;
        case(GRASS):
            fill_struct(sfFalse, "assets/map/buisson2.png", cell);
            break;
        case(FLOWERS):
            fill_struct(sfTrue, "assets/map/fleurs.png", cell);
            break;
        default:
            find_object = sfFalse;
            break;
    }
    if (find_object == sfTrue)
        fill_cell(a, b, map_t, &area);
}

void get_string(char *buffer, int *c, char *string)
{
    string[0] = buffer[*c];
    if (buffer[*c + 1] != 44 && buffer[*c + 1] != '\n') {
        string[1] = buffer[*c + 1];
        string[2] = '\0';
        *c += 3;
    } else {
        string[1] = '\0';
        *c += 2;
    }
}