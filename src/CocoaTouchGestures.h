//
//  CocoaTouchGestures.h
//  Gesture
//
//  Created by Ali Nakipoğlu on 5/5/13.
//
//

#pragma once

#include <vector>

#include "cinder/app/Window.h"

#include "LongPressGestureRecognizerInfo.h"
#include "PanGestureRecognizerInfo.h"
#include "PinchGestureRecognizerInfo.h"
#include "RotationGestureRecognizerInfo.h"
#include "ScreenEdgePanGestureRecognizerInfo.h"
#include "TapGestureRecognizerInfo.h"
#include "SwipeGestureRecognizerInfo.h"


void addSwipeGestures( const std::vector<SwipeGestureRecognizerInfo*> &gestureInfos,
                       ci::app::WindowRef windowRef );

void addTapGestures( TapGestureRecognizerInfo *singleTapInfo,
                     TapGestureRecognizerInfo *doubleTapInfo,
                     ci::app::WindowRef windowRef );

void addLongPressGestures( LongPressGestureRecognizerInfo *panInfo,
                           ci::app::WindowRef windowRef );

void addPanGestures( PanGestureRecognizerInfo *panInfo,
                     ci::app::WindowRef windowRef );

void addPinchGestures( PinchGestureRecognizerInfo *panInfo,
                       ci::app::WindowRef windowRef );

void addRotationGestures( RotationGestureRecognizerInfo *rotationInfo,
                        ci::app::WindowRef windowRef );

void addScreenEdgePanGestures( ScreenEdgePanGestureRecognizerInfo *sepanInfo,
                               ci::app::WindowRef windowRef );
