//
//  PinchGestureRecognizerInfo.h
//  Gesture
//
//  Created by clint hidinger on 10/13/19.
//

#pragma once

#include <functional>

using PinchGestureRecognizerCallBack = std::function<void()>;

class PinchGestureRecognizerInfo
{
public:
    PinchGestureRecognizerInfo( const PanGestureRecognizerCallBack &callback )
        : callback( callback )
    {
        
    }
    
    PinchGestureRecognizerCallBack &getCallback()
    {
        return callback;
    }

    float getScale() const { return mScale; }
    
    void setScale( float scale ) { mScale = scale; }
    
private:
    float mScale{ 1.0f };
    PinchGestureRecognizerCallBack callback;
};
