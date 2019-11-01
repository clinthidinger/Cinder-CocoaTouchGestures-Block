//
//  LongPressGestureRecognizerInfo.h
//  Gesture
//
//  Created by clint hidinger on 10/31/19.
//

#pragma once

#include <functional>

using LongPressGestureRecognizerCallBack = std::function<void( float, float )>;

class LongPressGestureRecognizerInfo
{
public:
    LongPressGestureRecognizerInfo( const LongPressGestureRecognizerCallBack &callback )
        : mCallback( callback )
    {
        
    }
    
    LongPressGestureRecognizerCallBack &getCallback()
    {
        return mCallback;
    }

    void setTouchLocation( float x, float y )
    {
        mTouchLocation = ci::vec2( x, y );
    }
    
    const ci::vec2 &getTouchLocation() const { return mTouchLocation; }
        
private:
    LongPressGestureRecognizerCallBack mCallback;
    ci::vec2 mTouchLocation{ 0.0f };
};
