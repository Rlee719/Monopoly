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
    }els
    

}

void roll();
void robot();


#endif