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
    
    static AL_Window& GetWindow()
    {
        return _window;
    }
    
    
    
    
    static void InitWindow(std::string windowTitle, uint32_t height, uint32_t width);
    
    //void SetBackgroundColour(uint16_t R, uint16_t G, uint16_t B, uint16_t A);
    
    
    
    static SDL_Window* GetSDLWindow();
    static SDL_Renderer* GetSDLRenderer();
    

    
private:
    
    
    AL_Window(){};
    ~AL_Window(){};
    
    
    
    static SDL_Window* _pWindow;
    static SDL_Renderer* _pRenderer;
    static bool _isFullScreen;
    static double_t _height;
    static double_t _width;
    static std::string _headerText;
    
    
    static AL_Window _window;
    
    static void free();
    
};



#endif /* AL_Window_hpp */
