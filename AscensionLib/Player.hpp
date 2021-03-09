//
//  Player.hpp
//  AscensionLib
//
//  Created by shan on 2021/2/21.
//  Copyright © 2021 TeamAscension. All rights reserved.
//

#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>
#include <vector>
#include "AeroPlaneGame.hpp"

class AeroPlane;



/*
 Player类，用于管理玩家角色。
 类下辖棋子类。
 
 
 */
class Player
{
    
public:
    //Player下辖的棋子序列。
    std::vector<int> position;
    uint32_t _startingPoint;
    
    
    Player();
    ~Player();
    
    
    
    
    
};



#endif /* Player_hpp */
