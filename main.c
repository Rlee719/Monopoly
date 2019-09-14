#include "main.h"
#include "display.h"


int main()
{
    game_status = (GAME_STATUS*) malloc(sizeof(GAME_STATUS));
    set_role();
    init_map();

    Start();
}

void Start()
{
    int count = 0;
    while(1)
    {
        count ++;
        display(game_status);
        GOTOXY(MAP_START_X,MAP_START_Y+COL_COUNT+3);
        printf("输入指令");
        scanf("%s", command);
        if(strcasecmp((COMMAND_ROLL), (command)) == 0)
            roll();
        game_status->current_player = game_status->current_player->next;
    }
}

void set_role()
{
    int player_num = 0;
    PLAYER *temp_player;
    char *player = (char*)malloc(5*sizeof(char));
    short id;

    printf("Chose your roles. \n1.钱夫人   2.阿土伯   3.金贝贝   4.孙小美\n");
    fgets(player, PLAYER_MAX_NUM+2, stdin);

    game_status->current_player = (PLAYER*) malloc(sizeof(PLAYER));

    id = player[player_num] - '0' -1;
    game_status->current_player->pos = 0;
    game_status->current_player->money = INIT_MONEY;
    game_status->current_player->player_id = id;
    memcpy(game_status->current_player->player_name, name_list[id], 16);
    player_num = 1;
    temp_player = game_status->current_player;

    while(player[player_num]!=10)
    {
        temp_player->next = (PLAYER*) malloc(sizeof(PLAYER));
        id = player[player_num] - '0' -1;
        temp_player->next->pos = 0;
        temp_player->next->money = INIT_MONEY;
        temp_player->next->player_id = id;
        memcpy(temp_player->next->player_name, name_list[id], 16);
        temp_player = temp_player->next;
        player_num++;
    }

        temp_player->next = game_status->current_player;
}

void init_map()
{
    int i;
    for(i = 1; i < 69; ++i)
    {
        game_status->map_unit[i].unit_owner_id = 0;
        game_status->map_unit[i].house_level = 0;
        game_status->map_unit[i].unit_value = 0;
    }
}

void roll()
{
    short step;
    step = rand() % 7;
    
    GOTOXY(MAP_START_X+10,MAP_START_Y+COL_COUNT+10);    
    printf("%d", game_status->current_player->pos);

    game_status->current_player->pos = (game_status->current_player->pos + step) % 70;
    display(game_status);
    GOTOXY(MAP_START_X,MAP_START_Y+COL_COUNT+6);
    printf("%s前进%d步\n", game_status->current_player->player_name, step);
    return;
}