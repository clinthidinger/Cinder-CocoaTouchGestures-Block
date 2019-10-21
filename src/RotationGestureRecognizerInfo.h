//
//  RotationGestureRecognizerInfo.h
//  Gesture
//
//  Created by clint hidinger on 10/21/19.
//

#pragma once

#include <functional>

using RotationGestureRecognizerCallBack = std::function<void()>;

class RotationGestureRecognizerInfo
{
public:
    RotationGestureRecognizerInfo( const PanGestureRecognizerCallBack &callback )
        : callback( callback )
    {
        
    }
    
    RotationGestureRecognizerCallBack &getCallback()
    {
        return callback;
    }

    float getRotation() const { return mRotation; }
    
    void setRotation( float rotation ) { mRotation = rotation; }
    
private:
    float mRotation{ 0.0f };
    RotationGestureRecognizerCallBack callback;
};
