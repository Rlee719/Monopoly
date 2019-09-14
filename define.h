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

#define CLEAN_GAME_FACE() do { \
    for(int i = 0; i < 16; ++ i){ \
        for(int j = START_X; j < 140; ++ j){ \
            GOTOXY(j,i); \
            printf(" "); \
        } \
    } \
}while(0);

typedef struct _PLAYER
{
    int player_id;
    char player_name[16];
    int pos;
    int bomb_num;
    int robot_num;
    int block_num;
    int sleep_time;
    int money;
    int point;
    struct _PLAYER *next;
}PLAYER;

typedef int player_id;

typedef struct _MAP_UNIT
{
    int unit_owner_id;//0,1,2,3,4
    int house_level;//0,1,2,3
    int unit_value;//
}MAP_UNIT;

typedef struct _GAME
{
    int player_num;
    PLAYER *current_player;
    PLAYER *player;
    char path[50];
    MAP_UNIT map[70];
}GAME_STATUS;
#endif