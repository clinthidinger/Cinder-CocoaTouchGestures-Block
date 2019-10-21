//
//  UIView+UIView_Gestures.h
//  UIView
//
//  Created by Ali Nakipoğlu on 5/5/13.
//  Copyright (c) 2013 Ali Nakipoğlu. All rights reserved.
//

#import <UIKit/UIKit.h>

#include <vector>
#include "PanGestureRecognizerInfo.h"
#include "PinchGestureRecognizerInfo.h"
#include "RotationGestureRecognizerInfo.h"
#include "SwipeGestureRecognizerInfo.h"
#include "TapGestureRecognizerInfo.h"

@interface UIView (UIView_Gestures)

- (void)addSwipeGestures:(std::vector<SwipeGestureRecognizerInfo*>) gestureRecognizerInfos;

- (void)addTapGestures:(TapGestureRecognizerInfo*)singleTapInfo : (TapGestureRecognizerInfo*)doubleTapInfo;

- (void)addPanGestures:(PanGestureRecognizerInfo*)panInfo;

- (void)addPinchGestures:(PinchGestureRecognizerInfo*)pinchInfo;

- (void)addRotationGestures:(RotationGestureRecognizerInfo*)rotationInfo;

@end
