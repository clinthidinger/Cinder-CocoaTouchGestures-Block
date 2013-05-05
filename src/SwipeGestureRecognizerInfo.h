//
//  SwipeGestureRecognizerInfo.h
//  UIView
//
//  Created by Ali Nakipoğlu on 5/5/13.
//  Copyright (c) 2013 Ali Nakipoğlu. All rights reserved.
//

#ifndef UIView_SwipeGestureRecognizerInfo_h
#define UIView_SwipeGestureRecognizerInfo_h

#include <boost/function.hpp>
#include <boost/bind.hpp>
#include <functional>

class SwipeGestureRecognizerInfo;

typedef boost::function<void()> GestureRecognizerCallBack;

class SwipeGestureRecognizerInfo
{
    
public:
    
    SwipeGestureRecognizerInfo( GestureRecognizerCallBack callback_, bool right_ = false, bool left_ = false, bool up_ = false, bool down_ = false )
    
    :callback( callback_ )
    ,right( right_ )
    ,left( left_ )
    ,up( up_ )
    ,down( down_ )
    
    {};
    
    ~SwipeGestureRecognizerInfo()
    {};
    
    GestureRecognizerCallBack & getCallback()
    {
        return callback;
    };
    
    bool getRight()
    {
        return right;
    };
    
    bool getLeft()
    {
        return left;
    };
    
    bool getUp()
    {
        return up;
    };
    
    bool getDown()
    {
        return down;
    };
    
private:
    
    GestureRecognizerCallBack   callback;
    
    bool    right;
    bool    left;
    bool    up;
    bool    down;
    
};

#endif
