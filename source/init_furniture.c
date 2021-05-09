/*
** EPITECH PROJECT, 2021
** init_furniture
** File description:
** rpg
*/

#include "taya.h"
#include "rpg.h"
#include <SFML/Graphics.h>
#include <stdlib.h>

void make_couch(enum house_furniture *cell, char *string)
{
    if (my_strcmp(string, "t1") == 0)
        *cell = CANAPE_TL;
    if (my_strcmp(string, "t2") == 0)
        *cell = CANAPE_TM;
    if (my_strcmp(string, "t3") == 0)
        *cell = CANAPE_TR;
    if (my_strcmp(string, "b1") == 0)
        *cell = CANAPE_BL;
    if (my_strcmp(string, "b2") == 0)
        *cell = CANAPE_BM;
    if (my_strcmp(string, "b3") == 0)
        *cell = CANAPE_BR;
    if (my_strcmp(string, "b3") == 0)
        *cell = CANAPE_BR;
}

void make_carpet(enum house_furniture *cell, char *string)
{
    if (my_strcmp(string, "c1") == 0)
        *cell = CARPET1_TL;
    if (my_strcmp(string, "c2") == 0)
        *cell = CARPET1_TM;
    if (my_strcmp(string, "c3") == 0)
        *cell = CARPET1_TR;
    if (my_strcmp(string, "m1") == 0)
        *cell = CARPET1_ML;
    if (my_strcmp(string, "m2") == 0)
        *cell = CARPET1_MM;
    if (my_strcmp(string, "m3") == 0)
        *cell = CARPET1_MR;
    if (my_strcmp(string, "d1") == 0)
        *cell = CARPET1_BL;
    if (my_strcmp(string, "d2") == 0)
        *cell = CARPET1_BM;
    if (my_strcmp(string, "d3") == 0)
        *cell = CARPET1_BR;
}

void make_table(enum house_furniture *cell, char *string)
{
    if (my_strcmp(string, "l1") == 0)
        *cell = TABLE_TL;
    if (my_strcmp(string, "l2") == 0)
        *cell = TABLE_TR;
    if (my_strcmp(string, "a1") == 0)
        *cell = TABLE_BL;
    if (my_strcmp(string, "a2") == 0)
        *cell = TABLE_BR;
    if (my_strcmp(string, "h1") == 0)
        *cell = CHAIR;
}

void make_draco(enum house_furniture *cell, char *string)
{
    if (my_strcmp(string, "r1") == 0)
        *cell = DRACO_TL;
    if (my_strcmp(string, "r2") == 0)
        *cell = DRACO_TR;
    if (my_strcmp(string, "f1") == 0)
        *cell = DRACO_BL;
    if (my_strcmp(string, "f2") == 0)
        *cell = DRACO_BR;
}