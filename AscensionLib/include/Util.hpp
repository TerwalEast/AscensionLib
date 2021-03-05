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



class AL_Point
{
public:
    
    double_t x;
    double_t y;
    
    double_t GetX();
    double_t GetY();
    
    AL_Point()
    {
        
    };
    
    AL_Point(double givenX, double givenY)
    {
        this->x = givenX;
        this->y = givenY;
    };
    
    ~AL_Point()
    {
        
    };
    
    AL_Point operator +(AL_Point secondPoint)
    {
        AL_Point resultPoint(this->x + secondPoint.x, this->y + secondPoint.y);
        return resultPoint;
    };
    
    void operator =(AL_Point secondPoint)
    {
        this->x = secondPoint.x;
        this->y = secondPoint.y;
    };
    
private:
    
    
    SDL_Point* convertToSDLPoint();

};


class AL_Transform
{
public:
    
    AL_Point position;
    double_t rotation;
    double_t scale;
    
    AL_Transform();
    
    ~AL_Transform();
    
    
    
    
private:
    
    
    
    
    
};


class AL_Rectangle
{
public:
    
    double_t x;
    double_t y;
    double_t width;
    double_t height;
    
    
    AL_Rectangle()
    {
        
    };
    
    AL_Rectangle(double_t x, double_t y, double_t width, double_t height)
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
