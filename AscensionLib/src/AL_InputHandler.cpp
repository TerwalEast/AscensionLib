//
//  AL_InputHandler.cpp
//  AscensionLib
//
//  Created by shan on 2021/4/1.
//  Copyright © 2021 TeamAscension. All rights reserved.
//

#include "../include/AL_InputHandler.hpp"

enum mouse_buttons
{
    LEFT = 0,
    MIDDLE = 1,
    RIGHT = 2
};

class AL_InputHandler
{
public:
    
    static InputHandler& GetInputHandler()
    {
        if(_inputHandler == 0)
        {
            _inputHandler = new InputHandler();
        }
        
        return _inputHandler;
    }
    
    // init joysticks
    void initialiseJoysticks();
    bool joysticksInitialised() const { return m_bJoysticksInitialised; }
    
    void reset();
    
    // update and clean the input handler
    void update();
    void clean();
    
    // keyboard events
    bool isKeyDown(SDL_Scancode key) const;
    
    // joystick events
    int getAxisX(int joy, int stick) const;
    int getAxisY(int joy, int stick) const;
    bool getButtonState(int joy, int buttonNumber) const;
    
    // mouse events
    bool getMouseButtonState(int buttonNumber) const;
    Vector2D* getMousePosition() const;
    
private:
    
    AL_InputHandler();
    ~AL_InputHandler();
    
    AL_InputHandler(const AL_InputHandler&);
    AL_InputHandler& operator=(const AL_InputHandler&);
    
    // private functions to handle different event types
    
    // handle keyboard events
    void onKeyDown();
    void onKeyUp();
    
    // handle mouse events
    void onMouseMove(SDL_Event& event);
    void onMouseButtonDown(SDL_Event& event);
    void onMouseButtonUp(SDL_Event& event);
    
    // handle joysticks events
    void onJoystickAxisMove(SDL_Event& event);
    void onJoystickButtonDown(SDL_Event& event);
    void onJoystickButtonUp(SDL_Event& event);

    // member variables
    
    // keyboard specific
    const Uint8* m_keystates;
    
    // joystick specific
    std::vector<std::pair<Vector2D*, Vector2D*>> m_joystickValues;
    std::vector<SDL_Joystick*> m_joysticks;
    std::vector<std::vector<bool>> m_buttonStates;
    bool m_bJoysticksInitialised;
    static const int m_joystickDeadZone = 10000;
    
    // mouse specific
    std::vector<bool> m_mouseButtonStates;
    Vector2D* m_mousePosition;
    
    // singleton
    static AL_InputHandler _inputHandler;
};

