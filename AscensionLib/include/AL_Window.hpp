//
//  AL_Window.hpp
//  AscensionLib
//
//  Created by shan on 2021/2/25.
//  Copyright © 2021 TeamAscension. All rights reserved.
//

#ifndef AL_Window_hpp
#define AL_Window_hpp

#include <stdio.h>
#include "STG.hpp"

class AL_Window
{
public:
    
    AL_Window();
    
    ~AL_Window();
    
    
    
    
    
private:
    
    static SDL_Window* _window;
    static SDL_Renderer* _renderer;
    
    static void free();
    
};



#endif /* AL_Window_hpp */
