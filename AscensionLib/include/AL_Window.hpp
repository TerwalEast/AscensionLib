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
#include <string>

class AL_Window
{
public:
    
    AL_Window();
    
    ~AL_Window();
    
    void InitWindow();
    
    void SetBackgroundColour(uint8_t R, uint8_t G, uint8_t B, uint8_t A);
    
    friend class AL_GameObjectBase;
    
private:
    
    static SDL_Window* _pWindow;
    static SDL_Renderer* _pRenderer;
    static bool _isFullScreen;
    static double_t _height;
    static double_t _width;
    static std::string _headerText;
    
    
    
    
    static void free();
    
};



#endif /* AL_Window_hpp */
