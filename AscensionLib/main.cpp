//
//  main.cpp
//  STG_Demo
//
//  Created by shan on 2021/1/17.
//  Copyright © 2021 Terwal. All rights reserved.
//

#include <iostream>


#include <string>
#include "GameManager.hpp"

const int SCREEN_WIDTH = 612;
const int SCREEN_HEIGHT = 612;

//游戏本体
GameManager *gGameManager = NULL;



int main( int argc, char* args[] )
{
    //游戏模块初始化
    gGameManager = new GameManager();
    gGameManager->InitGame();
}
