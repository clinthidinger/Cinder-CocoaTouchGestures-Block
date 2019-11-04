//
//  SwipeGestureRecognizerInfo.h
//  UIView
//
//  Created by Ali Nakipoğlu on 5/5/13.
//  Copyright (c) 2013 Ali Nakipoğlu. All rights reserved.
//

#pragma once
#include <functional>

using GestureRecognizerCallBack = std::function<void( float, float )>;

class SwipeGestureRecognizerInfo
{
public:
    SwipeGestureRecognizerInfo( const GestureRecognizerCallBack &callback,
                                bool right = false,
                                bool left = false,
                                bool up = false,
                                bool down = false )
    : mCallback( callback )
    , mRight( right )
    , mLeft( left )
    , mUp( up )
    , mDown( down )
    {
        
    }
    
    //~SwipeGestureRecognizerInfo() = default;
    
    GestureRecognizerCallBack &getCallback() { return mCallback; }
    
    bool getRight() const { return mRight; }
    
    bool getLeft() const { return mLeft; }
    
    bool getUp() const { return mUp; }
    
    bool getDown() const { return mDown; }
    
private:
    GestureRecognizerCallBack mCallback;
    
    bool mRight{ false };
    bool mLeft{ false };
    bool mUp{ false };
    bool mDown{ false };
};
