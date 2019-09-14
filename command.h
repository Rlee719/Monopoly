#ifndef MONOPOLY_COMMAND_H
#define MONOPOLY_COMMAND_H

#include"define.h"

void command_pre_process(char * command){
    for (int i = 0; i<strlen(command); i++)
    {
        command[i] = command[i] >= 'A'?command[i]-26:command[i];
        /* code */
    }
    
}

void excut_command(char *command){
    command_pre_process(command);
    if(0 == strcmp(command,"roll")){
        roll();
    }else if (0 == strcmp(command,"robot"))
    {
        robot();
    }
}

void roll();
void robot();
void sell(int n);
void block(int n);
void bomb(int n);
void query();
void help();
void quit();
void preset_players(player_id id_t);
void preset_where(player_id id_t,int location_t);
void preset_points(player_id id_t,int points_t);
void preset_points(player_id id_t,int fond_t);
void preset_block(player_id id_t,int block_t);
void preset_bomb(player_id id_t,int bomb_t);
void preset_robot(player_id id_t,int robot_t);
void preset_loc(int location_t,player_id id_t,int level_t);
void preset_clear(int location_t);
void preset_presion(player_id id_t,int day_t);
void preset_bless(player_id id_t,int day_t);
void preset_hospital(player_id id_t,int day_t);
void preset_nextplayer(player_id id_t);
void preset_bomb_or_not(int location_t);
void preset_block_or_not(int location_t);
void step(int location_t);
void preset_rounds(int rounds);
void preset_is_bankrupt(player_id id_t,bool flag);



#endif