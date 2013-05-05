//
//  UIView+UIView_Gestures.h
//  UIView
//
//  Created by Ali Nakipoğlu on 5/5/13.
//  Copyright (c) 2013 Ali Nakipoğlu. All rights reserved.
//

#import <UIKit/UIKit.h>

#include <vector>

#include "SwipeGestureRecognizerInfo.h"

@interface UIView (UIView_Gestures)

- (void)addSwipeGestures:(std::vector<SwipeGestureRecognizerInfo*>)gestureRecognizerInfos;

@end
