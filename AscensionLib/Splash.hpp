//
//  Splash.hpp
//  AscensionLib
//
//  Created by shan on 2021/2/27.
//  Copyright © 2021 TeamAscension. All rights reserved.
//

#ifndef Splash_hpp
#define Splash_hpp

#include <stdio.h>
#include "Util.hpp"
#include "AeroPlaneGame.hpp"

class Splash
{
public:
    
    Splash();
    ~Splash();
    
    void SplashLoop();
    
    
private:
    
    AL_Texture _splashTexture;
    
    
};


#endif /* Splash_hpp */
