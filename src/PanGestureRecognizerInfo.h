//
//  PanGestureRecognizerInfo.h
//  Gesture
//
//  Created by clint hidinger on 10/13/19.
//

#pragma once

#include <functional>

using PanGestureRecognizerCallBack = std::function<void()>;

class PanGestureRecognizerInfo
{
public:
    PanGestureRecognizerInfo( const PanGestureRecognizerCallBack &callback )
        : callback( callback )
    {
        
    }
    
    PanGestureRecognizerCallBack &getCallback()
    {
        return callback;
    }

    void setTapLocation( float x, float y )
    {
        mTouchLocation = ci::vec2( x, y );
    }
    
    const ci::vec2 &getTouchLocation() const { return mTouchLocation; }
        
private:
    PanGestureRecognizerCallBack callback;
    ci::vec2 mTouchLocation{ 0.0f };
};
