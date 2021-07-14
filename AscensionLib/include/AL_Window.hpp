//
//  AL_Window.hpp
//  AscensionLib
//
//  Created by shan on 2021/2/25.
//  Copyright © 2021 TeamAscension. All rights reserved.
//

#ifndef AL_Window_hpp
#define AL_Window_hpp

#include "STG.hpp"


namespace AscensionLib {
class AL_Texture;
class AL_Window
{
    
    friend AL_Texture;
    
    
public:
    
    static AL_Window& GetWindow()
    {
        return _window;
    }
        
    
    static void InitWindow(std::string windowTitle, uint32_t height, uint32_t width);
    
    static void SetBackgroundColour(uint R, uint G, uint B, uint A);
    
    static void ClearWindow();
    
    static void FlushRenderer();
    
    static void ShowCurrent();
    
    static void SetLogicalResolution(int width,int height);
    
    
    static SDL_Window* GetSDLWindow()
    {
        return _pWindow;
    }
    static SDL_Renderer* GetSDLRenderer()
    {
        return _pRenderer;
    }
    

protected:
    
    static SDL_Window* _pWindow;
    static SDL_Renderer* _pRenderer;
    
private:
    
    
    AL_Window(){};
    ~AL_Window(){free();};
    
    
    
    
    static bool _isFullScreen;
    static int _height;
    static int _width;
    static std::string _headerText;
    
    
    static AL_Window _window;
    
    static void free();
    
    static uint R;
    static uint G;
    static uint B;
    static uint A;
    
};
}






#endif /* AL_Window_hpp */
