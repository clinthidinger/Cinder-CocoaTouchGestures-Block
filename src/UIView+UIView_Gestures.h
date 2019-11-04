//
//  UIView+UIView_Gestures.h
//  UIView
//
//  Created by Ali Nakipoğlu on 5/5/13.
//  Copyright (c) 2013 Ali Nakipoğlu. All rights reserved.
//

#import <UIKit/UIKit.h>

#include <vector>
#include "LongPressGestureRecognizerInfo.h"
#include "PanGestureRecognizerInfo.h"
#include "PinchGestureRecognizerInfo.h"
#include "RotationGestureRecognizerInfo.h"
#include "ScreenEdgePanGestureRecognizerInfo.h"
#include "SwipeGestureRecognizerInfo.h"
#include "TapGestureRecognizerInfo.h"

@interface UIView (UIView_Gestures)

- (void)addSwipeGestures:(std::vector<SwipeGestureRecognizerInfo*>) gestureRecognizerInfos;

- (void)addTapGestures:(TapGestureRecognizerInfo*)singleTapInfo:(TapGestureRecognizerInfo*)doubleTapInfo;

- (void)addPanGesture:(PanGestureRecognizerInfo*)panInfo;

- (void)addPinchGesture:(PinchGestureRecognizerInfo*)pinchInfo;

- (void)addRotationGesture:(RotationGestureRecognizerInfo*)rotationInfo;

- (void)addScreenEdgePanGesture:(ScreenEdgePanGestureRecognizerInfo*)screenEdgePanInfo;

- (void)addScreenEdgePanAndPanGesture:(ScreenEdgePanGestureRecognizerInfo*)screenEdgePanInfo:
                                      (PanGestureRecognizerInfo*)panInfo;

- (void)addLongPressGesture:(LongPressGestureRecognizerInfo*)longPressInfo;


// https://developer.apple.com/documentation/uikit/touches_presses_and_gestures/coordinating_multiple_gesture_recognizers/preferring_one_gesture_over_another

-(void)enableSwipegeGestures:(bool)state;

- (void)removeSwipeGesture;

- (void)removeTapGestures;

- (void)removePanGestures;

- (void)removePinchGestures;

- (void)removeRotationGestures;

- (void)removeScreenEdgePanGesture;

- (void)removeLongPressGesture;

- (void)removeAllGestures;

@end
