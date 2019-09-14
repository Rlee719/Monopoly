#ifndef MONOPOLY_DEFINE_H
#define MONOPOLY_DEFINE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <string.h>

#define MAP_UNIT_COUNT

#define QFR 1
#define ATB 2
#define SXM 3
#define JBB 4
#define NUL 0

#define GOTOXY(x, y) do { \
    printf("\033[%d;%dH", y, x); \
}while(0);

typedef struct _PLAYER
{
    int player_id;
    char player_name[16];
    int pos;
    int money;
    struct _PLAYER *next;
}PLAYER;

typedef struct _MAP_UNIT
{
    int unit_owner_id;
    int house_level;
    int unit_value;
}MAP_UNIT;

typedef struct _GAME
{
    int player_num;
    PLAYER *current_player;
    //PLAYER *player;
    //char path[50];
    MAP_UNIT map_unit[70];
}GAME_STATUS;

#endif