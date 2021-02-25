//
//  Util.hpp
//  AscensionLib
//
//  Created by shan on 2021/2/25.
//  Copyright © 2021 TeamAscension. All rights reserved.
//

#ifndef Util_hpp
#define Util_hpp

#include <stdio.h>
#include "STG.hpp"



class AL_Point
{
public:
    double_t x;
    double_t y;
    
    double_t GetXPosition();
    double_t GetYPosition();
    
    
    
private:
    
    
    SDL_Point* convertToSDLPoint();
    
    
    
    
};











#endif /* Util_hpp */
