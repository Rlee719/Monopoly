#ifndef MONOPOLY_MAIN_H
#define MONOPOLY_MAIN_H

#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "define.h"

#define INIT_MONEY 1000
#define COMMAND_SIZE 10
#define COMMAND_ROLL "roll"
#define PLAYER_MAX_NUM 4

char command[COMMAND_SIZE];
char name_list[4][16] = {"钱夫人", "阿土伯", "金贝贝", "孙小美"};

GAME_STATUS *game_status = NULL;
void Start();
void set_role();
void init_map();
void roll();

#endif