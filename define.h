#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <string.h>

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
    PLAYER *player;
    char path[50];
    MAP_UNIT map[70];
}GAME_STATUS;