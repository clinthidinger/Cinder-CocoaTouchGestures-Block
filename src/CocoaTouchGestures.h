//
//  CocoaTouchGestures.h
//  Gesture
//
//  Created by Ali Nakipoğlu on 5/5/13.
//
//

#ifndef Gesture_CocoaTouchGestures_h
#define Gesture_CocoaTouchGestures_h

#include <vector>

#include "cinder/app/Window.h"

#include "TapGestureRecognizerInfo.h"
#include "SwipeGestureRecognizerInfo.h"


void addSwipeGestures( std::vector<SwipeGestureRecognizerInfo*> & gestureInfos, ci::app::WindowRef windowRef );

void addTapGestures(TapGestureRecognizerInfo* singleTapInfo, TapGestureRecognizerInfo* doubleTapInfo, ci::app::WindowRef windowRef );

#endif
