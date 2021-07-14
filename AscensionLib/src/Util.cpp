//
//  Util.cpp
//  TestGame
//
//  Created by shan on 2021/7/14.
//  Copyright © 2021 TeamAscension. All rights reserved.
//

#include "../include/Util.hpp"


namespace AscensionLib {
bool AL_Collision(Vector2D point, Rectangle rect)
{
    if(point.x >= rect.x && point.y <= rect.y)
    {
        if(point.x <= rect.x + rect.width && point.y <= rect.y - rect.height)
        {
            return true;
        }
    }
    
    return false;
}

}


