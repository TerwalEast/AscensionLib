//
//  Camera.hpp
//  AscensionLib
//
//  Created by shan on 2021/2/24.
//  Copyright © 2021 TeamAscension. All rights reserved.
//

#ifndef Camera_hpp
#define Camera_hpp


#include "STG.hpp"
#include "Util.hpp"




namespace AscensionLib {
class AL_VisibleObject;
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
    AL_Camera();
    
    //析构
    ~AL_Camera();
    
    //设置摄像机移动的目标点
    void SetCameraDestination(double x, double y, CameraMovementMethod cameraMovementMethod);
    
    //
    void SetCameraPosition(double x,double y);
    
    
    //更新函数
    void Update();
    
    
    
private:
    
    //摄像机的现在中心位置
    static Vector2D _cameraPosition;
    
    //现在设置的摄像机移动方式
    static CameraMovementMethod _currentMovementMethod;
    
    //移动目标
    static Vector2D _movementTarget;
    
    //旋转角度
    static double rotate;
    
    //
    static bool _hasFinishedMoving;
    
    
    
    
    
};
}

//Camera的Flag类。因为这些Flag肯定不重叠/同时使用，因此做成更为简单明了的Enum。
//这样的话编辑器也更容易高亮。


#endif /* Camera_hpp */
