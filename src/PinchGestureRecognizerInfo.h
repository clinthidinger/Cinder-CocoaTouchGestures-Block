//
//  PinchGestureRecognizerInfo.h
//  Gesture
//
//  Created by clint hidinger on 10/13/19.
//

#pragma once

#include <functional>

using PinchGestureRecognizerCallBack = std::function<void(float, float, float)>;

class PinchGestureRecognizerInfo
{
public:
    PinchGestureRecognizerInfo( const PinchGestureRecognizerCallBack &callback )
        : mCallback( callback )
    {
        
    }
    
    PinchGestureRecognizerCallBack &getCallback()
    {
        return mCallback;
    }

    float getScale() const { return mScale; }
    
    void setScale( float scale ) { mScale = scale; }
    
private:
    float mScale{ 1.0f };
    PinchGestureRecognizerCallBack mCallback;
};
