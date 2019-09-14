#include "display.h"

void goto_select_loc(int i)
{
    if (i>=0 && i<29)
    {
        GOTOXY(MAP_START_X+i-1,MAP_START_Y);
    }else if (i>=29 && i<35)
    {
        GOTOXY(MAP_START_X+28,MAP_START_Y+i+1-29)
    }else if (i>=35 && i<64)
    {
        GOTOXY(MAP_START_X+ROW_COUNT-(i-35),MAP_START_Y+6+1);
    }else if (i>=64 && i<70)
    {
        GOTOXY(MAP_START_X,MAP_START_Y+COL_COUNT-(i-64));
    }else
    {
        return;
    }
}

void display(GAME_STATUS *status)
{
    // set basic map
    CLEAR_SCREEN();
    int i = 0;
    for ( i = 0; i < ROW_COUNT; i++)
    {
        GOTOXY(MAP_START_X+i,MAP_START_Y);
        printf("0 ");
    }
    for ( i = 0; i < ROW_COUNT; i++)
    {
        GOTOXY(MAP_START_X+i,MAP_START_Y+COL_COUNT+1);
        printf("0 ");
    }
    for ( i = 0; i < COL_COUNT; i++)
    {
        GOTOXY(MAP_START_X,MAP_START_Y+i+1);
        printf("$");
    }
    for ( i = 0; i < COL_COUNT; i++)
    {
        GOTOXY(MAP_START_X+ROW_COUNT-1,MAP_START_Y+i+1);
        printf("$");
    }
    GOTOXY(MAP_START_X,MAP_START_Y);
    printf("S");
    GOTOXY(MAP_START_X+ROW_COUNT-1,MAP_START_Y);
    printf("T");
    GOTOXY(MAP_START_X,MAP_START_Y+COL_COUNT+1);
    printf("M");
    GOTOXY(MAP_START_X+ROW_COUNT-1,MAP_START_Y+COL_COUNT+1);
    printf("G");
    goto_select_loc(14);
    printf("H");
    goto_select_loc(49);
    printf("P");

    //set map house
    for (int i = 0; i < 70; i++)
    
    {
        switch (status->map_unit[i].unit_owner_id)
        {
        case NUL:
            break;

        case QFR:
            goto_select_loc(i);
            printf("\033[40;31m 0");
            break;

        case ATB:
            goto_select_loc(i);
            printf("\033[40;32m 0");
            break;
        case SXM:
            goto_select_loc(i);
            printf("\033[40;34m 0");
        case JBB:
            goto_select_loc(i);
            printf("\033[40;33m 0");
            break;
        default:
            break;
        }
        /* code */
    }

    int player_start_id = status->current_player->player_id;
    PLAYER *player = status->current_player;
    while (1)
    {
        GOTOXY(0,0);
GOTOXY(0,0);
                printf("%d\n",player->pos);

        goto_select_loc(player->pos);
        switch (player->player_id)
        {
        case NUL:
            break;

        case QFR:
            //goto_select_loc(i);
            printf("\033[40;31m Q");
            break;
        case ATB:
            //goto_select_loc(i);
            printf("\033[40;32m A");
            break;
        case SXM:
            //goto_select_loc(i);
            printf("\033[40;34m S");
        case JBB:
            //goto_select_loc(i);
            printf("\033[40;33m J");
            break;
        default:
            break;
        }
        printf("\033[40;37m");
        player = player->next;   
        if (player->player_id == player_start_id)
        {
            break;
        }     
    }
}

void get_command(char *command)
{
    //char command[10];
    GOTOXY(10,10);
    printf("please input your command:");
    scanf("%s",command);
}