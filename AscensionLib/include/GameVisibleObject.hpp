//
//  gameVisibleObject.hpp
//  STG_Demo
//
//  Created by shan on 2021/1/18.
//  Copyright © 2021 Terwal. All rights reserved.
//

#ifndef gameVisibleObject_hpp
#define gameVisibleObject_hpp

#include "STG.hpp"
#include "GameObjectManager.hpp"



class GameVisibleObject : GameObjectBase
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




#endif /* gameVisibleObject_hpp */
