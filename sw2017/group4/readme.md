# 第四组软件工程大富翁项目使用说明

### todo 

### doing 
   * 房屋买卖
   * 命令解析
   * 用户命令测试
   * debug接口

### done
   * debug测试用例
   * 玩家移动
   * 测试脚本
   * excel导出

---
### Introduction to the *runTest.sh*
* **command** folder contains the test command
* **dump** folder contains the ground truth
* **test_status** in the folder cmake-build-debug is the final result of the comparision

typedef struct _PLAYER
{
    //char name_list[4][16] = {"钱夫人", "阿土伯", "金贝贝", "孙小美"};
    
    int player_id;
    char player_name[16];
    int pos;
    int money;
    struct _PLAYER *next;   //下一个玩家
}PLAYER;

typedef struct _MAP_UNIT
{
    int unit_owner_id;      //0即为无人购买,1,2,3,4对应四个玩家
    int house_level;        //房屋等级
    int unit_value;         //单元格初始价格
}MAP_UNIT;

typedef struct _GAME
{
    int player_num;         //玩家数量
    PLAYER *current_player; //定义当前玩家，下一玩家由current_player->next指针指向
    MAP_UNIT map_unit[70];  //定义70个单元格
}GAME_STATUS;
