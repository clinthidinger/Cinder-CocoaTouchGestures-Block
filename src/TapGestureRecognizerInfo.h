//
//  TapGestureRecognizerInfo.h
//  UIView
//
//  Created by eight_io on 04/19/14.
//  Copyright (c) 2014 eight_io. All rights reserved.
//

#pragma once

#include <functional>

using TapGestureRecognizerCallBack = std::function<void()>;

class TapGestureRecognizerInfo
{
public:
    TapGestureRecognizerInfo( TapGestureRecognizerCallBack callback )
        : callback( callback )
    {
        
    }
    
//    TapGestureRecognizerInfo()
//    {
//        
//    }
    
    TapGestureRecognizerCallBack & getCallback()
    {
        return callback;
    }
    
    void setTapLocation( float x, float y )
    {
        mTouchLocation = ci::vec2( x, y );
    }
    
    const ci::vec2 &getTouchLocation() const { return mTouchLocation; }
    
    float x{ 0.0f };
    float y{ 0.0f };

private:
    ci::vec2 mTouchLocation{ 0.0f };
    TapGestureRecognizerCallBack callback;
};
