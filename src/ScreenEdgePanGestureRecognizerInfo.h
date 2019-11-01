//
//  ScreenEdgePanGestureRecognizerInfo.h
//  Gesture
//
//  Created by clint hidinger on 10/31/19.
//

#pragma once

#include <functional>

using ScreenEdgePanGestureRecognizerCallBack = std::function<void( float, float )>;

class ScreenEdgePanGestureRecognizerInfo
{
public:
    ScreenEdgePanGestureRecognizerInfo( const ScreenEdgePanGestureRecognizerCallBack &callback )
        : mCallback( callback )
    {
        
    }
    
    ScreenEdgePanGestureRecognizerCallBack &getCallback()
    {
        return mCallback;
    }

    void setTouchLocation( float x, float y )
    {
        mTouchLocation = ci::vec2( x, y );
    }
    
    const ci::vec2 &getTouchLocation() const { return mTouchLocation; }
        
private:
    ScreenEdgePanGestureRecognizerCallBack mCallback;
    ci::vec2 mTouchLocation{ 0.0f };
};
