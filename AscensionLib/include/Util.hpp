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

namespace AscensionLib {




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


class Vector2D
{
public:
    
    const double GetX();
    const double GetY();
    
    Vector2D()
    {
        
    };
    
    Vector2D(double givenX, double givenY)
    {
        this->x = givenX;
        this->y = givenY;
    };
    
    ~Vector2D()
    {
        
    };
    
    Vector2D operator +(Vector2D secondPoint)
    {
        Vector2D resultPoint(this->x + secondPoint.x, this->y + secondPoint.y);
        return resultPoint;
    };
    
    void operator =(Vector2D secondPoint)
    {
        this->x = secondPoint.x;
        this->y = secondPoint.y;
    };
    
private:
    
    double x;
    double y;
    //SDL_Point* convertToSDLPoint();
};


class Transform
{
public:
    Vector2D position;
    double rotation;
    double scale;
    Transform();
    ~Transform();
private:
};


class Rectangle
{
public:
    
    double x;
    double y;
    double width;
    double height;
    
    
    Rectangle()
    {
        
    };
    
    Rectangle(double x, double y, double width, double height)
    {
        this->x = x;
        this->y = y;
        this->width = width;
        this->height = height;
    };
    
    ~Rectangle()
    {
        
    };
    
    SDL_Rect getSDLRect()
    {
        SDL_Rect tar;
        tar.x = x;
        tar.y = y;
        tar.h = height;
        tar.w = width;
        return tar;
    }
    
private:
    
    
    
};







}




#endif /* Util_hpp */
