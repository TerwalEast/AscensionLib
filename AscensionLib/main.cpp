//
//  main.cpp
//  AscensionLib
//
//  Created by shan on 2021/5/10.
//  Copyright © 2021 TeamAscension. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "Splash.hpp"
#include "MainMenu.hpp"
#include "GameManager.hpp"

int main(int argc, const char * argv[])
{
    GameManager *game = new GameManager();
    game->InitGame();
    return 0;
}
