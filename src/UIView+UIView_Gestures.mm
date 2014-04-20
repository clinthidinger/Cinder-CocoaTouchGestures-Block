//
//  UIView+UIView_Gestures.m
//  UIView
//
//  Created by Ali Nakipoğlu on 5/5/13.
//  Copyright (c) 2013 Ali Nakipoğlu. All rights reserved.
//

#import "UIView+UIView_Gestures.h"

#import <objc/runtime.h>

#include <iostream>

static char const * const GESTUREINFOKEY = "GESTUREINFOKEY";

@interface UIGestureRecognizer (UIView_Gestures)

@property (nonatomic) SwipeGestureRecognizerInfo* swipeInfo;
@property (nonatomic) TapGestureRecognizerInfo* tapInfo;

@end

@implementation UIGestureRecognizer (UIView_Gestures)

@dynamic swipeInfo;

- (void)setSwipeInfo:(SwipeGestureRecognizerInfo *)info
{
    objc_setAssociatedObject(self, GESTUREINFOKEY, [NSValue valueWithPointer:info], OBJC_ASSOCIATION_RETAIN_NONATOMIC);
}

- (SwipeGestureRecognizerInfo *)swipeInfo
{
    return (SwipeGestureRecognizerInfo *)[(NSValue *)objc_getAssociatedObject(self, GESTUREINFOKEY) pointerValue];
}



@dynamic tapInfo;

- (void)setTapInfo:(TapGestureRecognizerInfo *)info
{
    objc_setAssociatedObject(self, GESTUREINFOKEY, [NSValue valueWithPointer:info], OBJC_ASSOCIATION_RETAIN_NONATOMIC);
}

- (TapGestureRecognizerInfo *)tapInfo
{
    return (TapGestureRecognizerInfo *)[(NSValue *)objc_getAssociatedObject(self, GESTUREINFOKEY) pointerValue];
}


@end

@interface UIView(UIView_Gestures_Internal)

- (void)handleSwipeGestureRecognizer:(UIGestureRecognizer *)gestureRecognizer;

- (void)handleTapGestureRecognizer:(UIGestureRecognizer *)gestureRecognizer;
@end

@implementation UIView (UIView_Gestures)

- (void)addSwipeGestures:(std::vector<SwipeGestureRecognizerInfo*>)SwipeGestureRecognizerInfos
{
    for ( auto it = SwipeGestureRecognizerInfos.begin(); it != SwipeGestureRecognizerInfos.end(); ++it )
    {
        UISwipeGestureRecognizerDirection direction = 0;
        
        if( (*it)->getRight() ){ direction   |= UISwipeGestureRecognizerDirectionRight; }
        if( (*it)->getLeft() ){ direction   |= UISwipeGestureRecognizerDirectionLeft; }
        if( (*it)->getUp() ){ direction   |= UISwipeGestureRecognizerDirectionUp; }
        if( (*it)->getDown() ){ direction   |= UISwipeGestureRecognizerDirectionDown; }
        
        UISwipeGestureRecognizer *gestureRecognizer = [[UISwipeGestureRecognizer alloc] initWithTarget:self action:@selector(handleSwipeGestureRecognizer:)];
        
        [gestureRecognizer setSwipeInfo:*it];
        [gestureRecognizer setDirection:direction];
        
        [self addGestureRecognizer:gestureRecognizer];
        
        [gestureRecognizer release];
    }
}

- (void)addTapGestures:(TapGestureRecognizerInfo*)singleTapInfo :(TapGestureRecognizerInfo*)doubleTapInfo {

    UITapGestureRecognizer *singleTapRecognizer = [[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(handleTapGestureRecognizer:)];
    [singleTapRecognizer setTapInfo:singleTapInfo];
    [singleTapRecognizer setNumberOfTapsRequired:1];
    [self addGestureRecognizer:singleTapRecognizer];
    
    UITapGestureRecognizer *doubleTapRecognizer = [[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(handleTapGestureRecognizer:)];
    [doubleTapRecognizer setTapInfo:doubleTapInfo];
    [doubleTapRecognizer setNumberOfTapsRequired:2];
    [self addGestureRecognizer:doubleTapRecognizer];
    
    [singleTapRecognizer requireGestureRecognizerToFail : doubleTapRecognizer];
    
    [singleTapRecognizer release];
    [doubleTapRecognizer release];
}

@end

@implementation UIView (UIView_Gestures_Internal)

- (void)handleSwipeGestureRecognizer:(UIGestureRecognizer *)gestureRecognizer
{
    gestureRecognizer.swipeInfo->getCallback()();
}

- (void)handleTapGestureRecognizer:(UIGestureRecognizer *)gestureRecognizer
{
    gestureRecognizer.tapInfo->getCallback()();
}

@end
