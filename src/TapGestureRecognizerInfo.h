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

typedef boost::function<void ()> TapGestureRecognizerCallBack;

class TapGestureRecognizerInfo {
    
public:
    TapGestureRecognizerInfo( TapGestureRecognizerCallBack callback) : callback( callback )   {};
    
    TapGestureRecognizerInfo() {};
    
    TapGestureRecognizerCallBack & getCallback() {
        return callback;
    };
    
    void setTapLocation(float x, float y){
        this->x = x;
        this->y = y;
    }
    
    float x, y;

private:
    
    TapGestureRecognizerCallBack   callback;

    
};

#endif
