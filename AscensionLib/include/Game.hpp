//
//  AL_Game.hpp
//  AscensionLib
//
//  Created by shan on 2021/3/7.
//  Copyright © 2021 TeamAscension. All rights reserved.
//

#ifndef AL_Game_hpp
#define AL_Game_hpp

#include "STG.hpp"

class AL_Window;


namespace AscensionLib {
class Game
{
    
public:
    
    static Game& GetGame()
    {
        return _game;
    }
    
    static void InitGame(std::string windowTitle, uint32_t height, uint32_t width);
    
    static void HandleInput();
    
    static void UpdateGame();
    
    static void RenderGame();
    
private:
    
    Game(){};
    ~Game(){IMG_Quit();SDL_Quit();TTF_Quit();};
    Game(const Game& game) = delete;
    Game& operator = (const Game game) = delete;
    
    
    
    
    static Game _game;
    

};



}




#endif /* AL_Game_hpp */
