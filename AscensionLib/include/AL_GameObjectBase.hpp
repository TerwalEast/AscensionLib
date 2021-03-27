//
//  gameObject.hpp
//  STG_Demo
//
//  Created by shan on 2021/1/18.
//  Copyright © 2021 Terwal. All rights reserved.
//

#ifndef gameObject_hpp
#define gameObject_hpp

#include "STG.hpp"

class AL_GameObjectBase
{
public:
    
    void Update();
    
    
    
    
private:
    
    bool _isActive;
    bool _isRendered;
    
    
};


#endif /* gameObject_hpp */
