//
//  SwipeGestureRecognizerInfo.h
//  UIView
//
//  Created by Ali Nakipoğlu on 5/5/13.
//  Copyright (c) 2013 Ali Nakipoğlu. All rights reserved.
//

#pragma once
#include <functional>

using GestureRecognizerCallBack = std::function<void()>;

class SwipeGestureRecognizerInfo
{
public:
    SwipeGestureRecognizerInfo( const GestureRecognizerCallBack &callback_,
                                bool right_ = false,
                                bool left_ = false,
                                bool up_ = false,
                                bool down_ = false )
    : callback( callback_ )
    , right( right_ )
    , left( left_ )
    , up( up_ )
    , down( down_ )
    {
        
    }
    
    //~SwipeGestureRecognizerInfo() = default;
    
    GestureRecognizerCallBack &getCallback()
    {
        return callback;
    }
    
    bool getRight()
    {
        return right;
    }
    
    bool getLeft()
    {
        return left;
    }
    
    bool getUp()
    {
        return up;
    }
    
    bool getDown()
    {
        return down;
    }
    
private:
    GestureRecognizerCallBack callback;
    
    bool right{ false };
    bool left{ false };
    bool up{ false };
    bool down{ false };
};
