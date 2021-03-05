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
#include "AL_Texture.hpp"

enum RenderMode
{
    DisableRendering = 1,
    Culling = 2
    
};





class AL_VisibleObject : AL_GameObjectBase
{
    
public:

    
    
    void Draw();
    
    
    
private:
    
    AL_Texture* _pTargetTexture;
    
    AL_Rectangle _clipRect;
    
    RenderMode _renderMode;
    
    

    
};




#endif /* gameVisibleObject_hpp */
