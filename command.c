#include "command.h"

void roll(){}
void robot(){}
void sell(int n){}
void block(int n){}
void bomb(int n){}
void query(){}
void help(){}
void quit(){}
void preset_players(player_id id_t){}
void preset_where(player_id id_t,int location_t){}
void preset_points(player_id id_t,int points_t){}
void preset_block(player_id id_t,int block_t){}
void preset_bomb(player_id id_t,int bomb_t){}
void preset_robot(player_id id_t,int robot_t){}
void preset_loc(int location_t,player_id id_t,int level_t){}
void preset_clear(int location_t){}
void preset_presion(player_id id_t,int day_t){}
void preset_bless(player_id id_t,int day_t){}
void preset_hospital(player_id id_t,int day_t){}
void preset_nextplayer(player_id id_t){}
void preset_bomb_or_not(int location_t){}
void preset_block_or_not(int location_t){}
void step(int location_t){}
void preset_rounds(int rounds){}
void preset_is_bankrupt(player_id id_t,int flag){}

void command_pre_process(char *command){
    for (int i = 0; i<strlen(command); i++)
    {
        if (command[i]>='A' && command[i]<='z')
            command[i] = command[i] <='Z'?command[i]+26:command[i];
    }   
}

void excut_command(){
    char command[50];
    scanf("%s",command);
    if(0 == strcmp(command,"roll")){
        roll();
    }else if (0 == strcmp(command,"robot"))
    {
        robot();
    }else if (0 == strcmp(command,"query"))
    {
        query();
    }else if (0 == strcmp(command,"help"))
    {
        help();
    }else if (0 == strcmp(command,"quit"))
    {
        quit();
    }else if (0 == strcmp(command,"sell"))
    {
        int n;
        scanf("%d",&n);
        if (n>=0 || n<=69)
        {
            sell(n);
        }
    }else if (0 == strcmp(command,"block"))
    {
        int n;
        scanf("%d",&n);
        if (n>=-10 || n<=10)
        {
            block(n);
        }
      
    }else if (0 == strcmp(command,"bomb"))
    {
        int n;
        scanf("%d",&n);
        if(n>=-10 || n<=10){
            bomb(n);
        }
    }else if (0 == strcmp(command,"step"))
    {
        int n;
        scanf("%d",&n);
        if (n>=0 && n<=69)
        {
            step(n);
        }
        
    }else if(0 == strcmp(command,"preset"))
    {
        scanf("%s",command);
        if (!strcmp(command,"players"))
        {
            player_id id;
            scanf("%c",&id);
            preset_players(id);
            
        }else if (!strcmp(command,"where"))
        {
            player_id id;
            int location;
            scanf("%c",&id);
            scanf("%d",&location);
            if ( location >= 0 && location<=69 )
            {
                preset_where(id,location);
            }
        }else if (!strcmp(command,"point"))
        {
            player_id id;
            int points;
            scanf("%c",&id);
            scanf("%d",&points);
            if ( points>=0 && points<=50)
            {
                preset_points(id,points);
            }
        }else if (!strcmp(command,"block"))
        {
            player_id id;
            int block;
            scanf("%c",&id);
            scanf("%d",&block);
            if (block>=0 && block<=10)
            {
                preset_block(id,block);
            }
        }else if (!strcmp(command,"bomb"))
        {
            player_id id;
            int bomb;
            scanf("%c",&id);
            scanf("%d",&bomb);
            if ( bomb>=0 && bomb<=10)
            {
                preset_bomb(id,bomb);
            }
            
        }else if (!strcmp(command,"robot"))
        {
            player_id id;
            int robot;
            scanf("%c",&id);
            scanf("%d",&robot);
            if ( robot>=0 && robot<=10)
            {
                preset_robot(id,robot);
            }
            
        }else if (!strcmp(command,"loc"))
        {
            int location;
            player_id id;
            int level;
            scanf("%d",&location);
            scanf("%c",&id);
            scanf("%d",&level);
            if ( level>=0 && level<=3 && location >=0 && location<=69)
            {
                preset_loc(location,id,level);
            } 
        }else if (!strcmp(command,"clear"))
        {
            int location;
            scanf("%d",&location);
            if (location >=0 && location<=69)
            {
                preset_clear(location);
            }   
        }else if (!strcmp(command,"presion"))
        {
            player_id id;
            int day;
            scanf("%c",&id);
            scanf("%d",&day);
            if (day>=0 && day<=2)
            {
                preset_presion(id,day);
            }   
        }else if (!strcmp(command,"bless"))
        {
            player_id id;
            int day;
            scanf("%c",&id);
            scanf("%d",&day);
            if (day>=0 && day<=5)
            {
                preset_bless(id,day);
            }
        }else if (!strcmp(command,"hospital"))
        {
            player_id id;
            int day;
            scanf("%c",&id);
            scanf("%d",&day);
            if(day >=0 && day <= 3){
                preset_hospital(id,day);
            }
        }else if (!strcmp(command,"nextplayer"))
        {
            player_id id;
            scanf("%c",&id);
            preset_nextplayer(id);
        }else if (!strcmp(command,"bomb_or_not"))
        {
            int location;
            scanf("%d",&location);
            if (location>=0 && location <=69)
            {
                preset_bomb_or_not(location);
            }   
        }else if (!strcmp(command,"block_or_not"))
        {
            int location;
            scanf("%d",&location);
            if (location>=0 && location<=69)
            {
                preset_block_or_not(location);
            }
            
        }else if (!strcmp(command, "rounds"))
        {
            int rounds;
            scanf("%d",&rounds);
            if (rounds>=1 && rounds<=20)
            {
                preset_rounds(rounds);
            }
            
        }else if (!strcmp(command,"is_bankrupt"))
        {
            player_id id;
            int flag;
            scanf("%c",&id);
            scanf("%d",&flag);
            preset_is_bankrupt(id,flag);
        }
        
           
    }
}