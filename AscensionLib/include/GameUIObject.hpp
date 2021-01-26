//
//  GameUIObject.hpp
//  AscensionLib
//
//  Created by shan on 2021/1/26.
//  Copyright © 2021 TeamAscension. All rights reserved.
//

#ifndef GameUIObject_hpp
#define GameUIObject_hpp

#include "STG.hpp"
#include "GameVisibleObject.hpp"





class GameUIObject : GameVisibleObject
{
    
public:
    virtual void Draw();
    
    
private:
    struct _transform
    {
        double positionX;
        double positionY;
    };
    
    
    
    
    
};

#endif /* GameUIObject_hpp */
