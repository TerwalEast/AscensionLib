//
//  ChessBoard.cpp
//  AscensionLib
//
//  Created by shan on 2021/2/21.
//  Copyright © 2021 TeamAscension. All rights reserved.
//

#include "ChessBoard.hpp"
#include "AeroPlaneGame.hpp"

#define TOTAL_GRID_NUMBER 92
#define HANGER_NUMBER 16

/*
 public:
 ChessBoard();
 ~ChessBoard();
 //标准棋盘：92个。其中16个机库
 uint32_t _totalGridNumber;
 AL_Texture BoardImage;
 vector<SDL_Point> _grids;
 
 SDL_Point GetGridPoint(int gridNumber);
 
 
 
 ChessBoard(int GridNumber);
 
 */

void ChessBoard :: Init()
{
    cout << "ChessBoard Init!" << endl;
    
    _totalGridNumber = 92;
    
    SDL_Point* targetPoint = new SDL_Point();
    
    //0~16号：机库
    
    targetPoint->x = 31;
    targetPoint->y = 31;
    _grids.push_back(*targetPoint);
    
    
    targetPoint->x = 91;
    targetPoint->y = 30;
    _grids.push_back(*targetPoint);
    
    targetPoint->x = 31;
    targetPoint->y = 91;
    _grids.push_back(*targetPoint);
    
    targetPoint->x = 91;
    targetPoint->y = 91;
    _grids.push_back(*targetPoint);
    
    
    for(int i = 4; i < 15; i++)
    {
        targetPoint->x = 0;
        targetPoint->y = 0;
        _grids.push_back(*targetPoint);
    }
    
    //16
    targetPoint->x = 151;
    targetPoint->y = 105;
    _grids.push_back(*targetPoint);
    
    //17
    targetPoint->x = 163;
    targetPoint->y = 140;
    _grids.push_back(*targetPoint);
    
    //18
    targetPoint->x = 140;
    targetPoint->y = 163;
    _grids.push_back(*targetPoint);
    
    //19
    targetPoint->x = 106;
    targetPoint->y = 151;
    _grids.push_back(*targetPoint);
    
    //20
    targetPoint->x = 76;
    targetPoint->y = 151;
    _grids.push_back(*targetPoint);
    
    //21
    targetPoint->x = 43;
    targetPoint->y = 162;
    _grids.push_back(*targetPoint);
    
    for(int i = 22 ; i < 92; i+=6)
    {
    
        targetPoint->x = 151;
        targetPoint->y = 105;
        _grids.push_back(*targetPoint);
        
        //17
        targetPoint->x = 163;
        targetPoint->y = 140;
        _grids.push_back(*targetPoint);
        
        //18
        targetPoint->x = 140;
        targetPoint->y = 163;
        _grids.push_back(*targetPoint);
        
        //19
        targetPoint->x = 106;
        targetPoint->y = 151;
        _grids.push_back(*targetPoint);
        
        //20
        targetPoint->x = 76;
        targetPoint->y = 151;
        _grids.push_back(*targetPoint);
        
        //21
        targetPoint->x = 43;
        targetPoint->y = 162;
        _grids.push_back(*targetPoint);
        
        
        
    }
    
    
    
    SDL_free(targetPoint);
    
}

int ChessBoard :: GetNextPoint(int gridNumber)
{
    if(gridNumber <= 15)
        return 16;
    
    return (gridNumber + 1 - HANGER_NUMBER) % (TOTAL_GRID_NUMBER - HANGER_NUMBER) + 16;
}

SDL_Point ChessBoard:: GetGridPoint(int gridNumber)
{
    return _grids[gridNumber];
}


ChessBoard :: ChessBoard()
{
    Init();
    
    
    
}

ChessBoard::~ChessBoard()
{
    
}
