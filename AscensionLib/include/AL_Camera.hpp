//
//  Camera.hpp
//  AscensionLib
//
//  Created by shan on 2021/2/24.
//  Copyright © 2021 TeamAscension. All rights reserved.
//

#ifndef Camera_hpp
#define Camera_hpp

#include <stdio.h>
#include "STG.hpp"


class AL_VisibleObject;

//Camera的Flag类。因为这些Flag肯定不重叠/同时使用，因此做成更为简单明了的Enum。
//这样的话编辑器也更容易高亮。
enum class CameraMovementMethod
{
    teleport,
    linear
};


class AL_Camera
{
    friend class AL_VisibleObject;
    
public:
    
    //构造
    Camera();
    
    //析构
    ~Camera();
    
    //设置摄像机移动的目标点
    void SetCameraDestination(float x, float y, CameraMovementMethod cameraMovementMethod);
    
    //
    
    
    
    //更新函数
    void Update();
    
    
    
private:
    
    //摄像机的现在位置
    SDL_Point _cameraPosition;
    
    
    
    
};

#endif /* Camera_hpp */
