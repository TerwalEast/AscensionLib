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
#include "AeroPlaneGame.hpp"

class Splash:AL_VisibleObject
{
public:
    
    Splash();
    
    ~Splash();
    
    void SplashLoop();
    
    
    
    
private:
    
    AL_Texture* _pSplashTexture;
    
    
};


#endif /* Splash_hpp */
