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

    while(1)
    {
        display(game_status);
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
    char player[PLAYER_MAX_NUM];
    short id;

    printf("Chose your roles.\n1.钱夫人   2.阿土伯   3.金贝贝   4.孙小美\n");

    fgets(player, PLAYER_MAX_NUM, stdin);
    for (int i = 0; i < PLAYER_MAX_NUM; ++i)
    {
        if (player[i] == '\r' ||
            player[i] == '\n' ||
            player[i] == ' '  ||
            player[i] == '\t' ||
            player[i] == '\v' ||
            player[i] == '\f' )
            {
            player[i] = '\0';
            break;
            }  
    }

    game_status->current_player = (PLAYER*) malloc(sizeof(PLAYER));

    id = player[player_num] - '0';
    game_status->current_player->pos = 0;
    game_status->current_player->money = INIT_MONEY;
    game_status->current_player->player_id = id;
    memcpy(game_status->current_player->player_name, name_list[id], 20);
    player_num = 1;

    temp_player = game_status->current_player;    
    while(player[player_num!='\0'])
    {
        temp_player->next = (PLAYER*) malloc(sizeof(PLAYER));
        id = player[player_num] - '0';
        temp_player->next->pos = 0;
        temp_player->next->money = INIT_MONEY;
        temp_player->next->player_id = id;
        memcpy(temp_player->next->player_name, name_list[id], 20);
        temp_player = temp_player->next;
        player_num++;
    }
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
    step = rand() % 6;
    game_status->current_player->pos = (game_status->current_player->pos + step) % 70;
    display(game_status);
    printf("%s前进%d步\n", game_status->current_player->player_name, step);

    return;
}