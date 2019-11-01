//
//  RotationGestureRecognizerInfo.h
//  Gesture
//
//  Created by clint hidinger on 10/21/19.
//

#pragma once

#include <functional>

using RotationGestureRecognizerCallBack = std::function<void(float, float , float)>;

class RotationGestureRecognizerInfo
{
public:
    RotationGestureRecognizerInfo( const RotationGestureRecognizerCallBack &callback )
        : mCallback( callback )
    {
        
    }
    
    RotationGestureRecognizerCallBack &getCallback()
    {
        return mCallback;
    }

    float getRotation() const { return mRotation; }
    
    void setRotation( float rotation ) { mRotation = rotation; }
    
private:
    float mRotation{ 0.0f };
    RotationGestureRecognizerCallBack mCallback;
};
