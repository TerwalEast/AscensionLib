//
//  Util.hpp
//  AscensionLib
//
//  Created by shan on 2021/2/25.
//  Copyright © 2021 TeamAscension. All rights reserved.
//

#ifndef Util_hpp
#define Util_hpp

#include <stdio.h>
#include "STG.hpp"
#include <memory>

static void SDL_ResourceDestory(SDL_Window *pWindow)
{
    SDL_DestroyWindow(pWindow);
}

static void SDL_ResourceDestory(SDL_Renderer *pRenderer)
{
    SDL_DestroyRenderer(pRenderer);
}

static void SDL_ResourceDestory(SDL_Texture *pTexture)
{
    SDL_DestroyTexture(pTexture);
}

static void SDL_ResourceDestory(SDL_Surface *pSurface)
{
    SDL_FreeSurface(pSurface);
}


class AL_Log
{
    
};



//std::string GetTimeString()
//{
//    time_t nowtime;
//    nowtime = time(NULL); //获取日历时间
//    char tmp[64];
//    strftime(tmp,sizeof(tmp),"%Y-%m-%d %H:%M:%S",localtime(&nowtime));
//    return tmp;
//}


class AL_Vector2D
{
public:
    
    
    
    const double GetX();
    const double GetY();
    
    AL_Vector2D()
    {
        
    };
    
    AL_Vector2D(double givenX, double givenY)
    {
        this->x = givenX;
        this->y = givenY;
    };
    
    ~AL_Vector2D()
    {
        
    };
    
    AL_Vector2D operator +(AL_Vector2D secondPoint)
    {
        AL_Vector2D resultPoint(this->x + secondPoint.x, this->y + secondPoint.y);
        return resultPoint;
    };
    
    void operator =(AL_Vector2D secondPoint)
    {
        this->x = secondPoint.x;
        this->y = secondPoint.y;
    };
    
private:
    
    double x;
    double y;
    
    //SDL_Point* convertToSDLPoint();

};


class AL_Transform
{
public:
    
    AL_Vector2D position;
    double rotation;
    double scale;
    
    AL_Transform();
    
    ~AL_Transform();
    
    
    
    
private:
    
    
    
    
    
};


class AL_Rectangle
{
public:
    
    double x;
    double y;
    double width;
    double height;
    
    
    AL_Rectangle()
    {
        
    };
    
    AL_Rectangle(double x, double y, double width, double height)
    {
        this->x = x;
        this->y = y;
        this->width = width;
        this->height = height;
    };
    
    ~AL_Rectangle()
    {
        
    };
    
    
    
    
    
private:
    
    
    
    
};







#endif /* Util_hpp */
