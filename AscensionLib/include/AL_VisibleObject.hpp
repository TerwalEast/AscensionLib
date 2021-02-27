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
#include "AL_GameObjectManager.hpp"
#include "Util.hpp"

enum RenderMode
{
    IsDisabled = 1;
    SimpleCulling = 2;
    
}



class AL_VisibleObject : AL_GameObjectBase
{
    
public:
    virtual void Draw();
    
    
private:
    
    
    RenderMode _renderMode;
    
    

    
};




#endif /* gameVisibleObject_hpp */
