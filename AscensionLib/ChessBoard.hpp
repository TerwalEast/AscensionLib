//
//  ChessBoard.hpp
//  AscensionLib
//
//  Created by shan on 2021/2/21.
//  Copyright © 2021 TeamAscension. All rights reserved.
//

#ifndef ChessBoard_hpp
#define ChessBoard_hpp

#include <stdio.h>
#include "AeroPlaneGame.hpp"






class ChessBoard
{
public:
    ChessBoard();
    ~ChessBoard();
    //标准棋盘：92个。其中16个机库
    SDL_Point GetGridPoint(int gridNumber);
    int GetNextPoint(int gridNumber);
    void Init();
    
    uint32_t _totalGridNumber;
    vector<SDL_Point> _grids;

    
    
    
    
};






#endif /* ChessBoard_hpp */
