//
//  TapGestureRecognizerInfo.h
//  UIView
//
//  Created by eight_io on 04/19/14.
//  Copyright (c) 2014 eight_io. All rights reserved.
//

#pragma once

#include <functional>

using TapGestureRecognizerCallBack = std::function<void( float x, float y )>;

class TapGestureRecognizerInfo
{
public:
    TapGestureRecognizerInfo( const TapGestureRecognizerCallBack &callback )
        : mCallback( callback )
    {
        
    }
    
//    TapGestureRecognizerInfo()
//    {
//        
//    }
    
    TapGestureRecognizerCallBack &getCallback()
    {
        return mCallback;
    }
    
    void setTouchLocation( float x, float y )
    {
        mTouchLocation = ci::vec2( x, y );
    }
    
    const ci::vec2 &getTouchLocation() const { return mTouchLocation; }
    
private:
    ci::vec2 mTouchLocation{ 0.0f };
    TapGestureRecognizerCallBack mCallback;
};
