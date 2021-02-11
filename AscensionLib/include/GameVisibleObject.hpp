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
    struct transform
    {
        SDL_Point position;
        
        double rotate;
        double scale;
        
    }_transform;
    
    
    
    
    void _transformSwitch()
    {
        _transform.position.x = 100;
    }
    
    
};




#endif /* gameVisibleObject_hpp */
