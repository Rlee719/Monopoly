#include "define.h"

#ifndef MONOPOLY_DISPLAY_H
#define MONOPOLY_DISPLAY_H

#define MAP_START_X 40
#define MAP_START_Y 4
#define ROW_COUNT 29
#define COL_COUNT 6
#define HOSPITAL_LOCAL 14
#define PRISON_LOCAL 49

#define GOTOXY(x, y) do { \
    printf("\033[%d;%dH", y, x); \
}while(0);

#define CLEAR() printf("\033[2J")

#define CLEAR_SCREEN() do { \
    for(int i = 0; i < 16; ++ i){ \
        for(int j = 0; j < 140; ++ j){ \
            GOTOXY(j,i); \
            printf(" "); \
        } \
    } \
}while(0);

typedef struct _POS{
    int x;
    int y;
}POS;

void goto_select_loc(int i);

void display(GAME_STATUS *status);


void get_command(char *command);
#endif