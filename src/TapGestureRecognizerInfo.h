//
//  TapGestureRecognizerInfo.h
//  UIView
//
//  Created by eight_io on 04/19/14.
//  Copyright (c) 2014 eight_io. All rights reserved.
//

#ifndef UIView_SwipeGestureRecognizerInfo_h
#define UIView_SwipeGestureRecognizerInfo_h

#include <boost/function.hpp>
#include <boost/bind.hpp>
#include <functional>

class TapGestureRecognizerInfo;

typedef boost::function<void()> GestureRecognizerCallBack;

class TapGestureRecognizerInfo
{
    
public:
    
    TapGestureRecognizerInfo( GestureRecognizerCallBack callback_, bool right_ = false, bool left_ = false, bool up_ = false, bool down_ = false )
    
    :callback( callback_ )
    ,right( right_ )
    ,left( left_ )
    ,up( up_ )
    ,down( down_ )
    
    {};
    
    TapGestureRecognizerInfo()
    {};
    
    TapGestureRecognizerInfo & getCallback()
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
