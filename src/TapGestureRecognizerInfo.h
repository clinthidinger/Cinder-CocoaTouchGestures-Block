//
//  TapGestureRecognizerInfo.h
//  UIView
//
//  Created by eight_io on 04/19/14.
//  Copyright (c) 2014 eight_io. All rights reserved.
//

#ifndef UIView_TapGestureRecognizerInfo_h
#define UIView_TapGestureRecognizerInfo_h

#include <boost/function.hpp>
#include <boost/bind.hpp>
#include <functional>

class TapGestureRecognizerInfo;

typedef boost::function<void()> GestureRecognizerCallBack;

class TapGestureRecognizerInfo
{
    
public:
    
    TapGestureRecognizerInfo( GestureRecognizerCallBack callback_)
    
    :callback( callback_ )   {};
    
    TapGestureRecognizerInfo()
    {};
    
    GestureRecognizerCallBack & getCallback()
    {
        return callback;
    };

    
private:
    
    GestureRecognizerCallBack   callback;
    
};

#endif
