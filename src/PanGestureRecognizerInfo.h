//
//  PanGestureRecognizerInfo.h
//  Gesture
//
//  Created by clint hidinger on 10/13/19.
//

#pragma once

#include <functional>

using PanGestureRecognizerCallBack = std::function<void( float x, float y )>;

class PanGestureRecognizerInfo
{
public:
    PanGestureRecognizerInfo( const PanGestureRecognizerCallBack &callback )
        : mCallback( callback )
    {
        
    }
    
    PanGestureRecognizerCallBack &getCallback()
    {
        return mCallback;
    }

    void setTouchLocation( float x, float y )
    {
        mTouchLocation = ci::vec2( x, y );
    }
    
    const ci::vec2 &getTouchLocation() const { return mTouchLocation; }
        
private:
    PanGestureRecognizerCallBack mCallback;
    ci::vec2 mTouchLocation{ 0.0f };
};
