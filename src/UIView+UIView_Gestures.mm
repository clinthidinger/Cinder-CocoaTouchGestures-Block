//
//  UIView+UIView_Gestures.m
//  UIView
//
//  Created by Ali Nakipoğlu on 5/5/13.
//  Copyright (c) 2013 Ali Nakipoğlu. All rights reserved.
//

#import "UIView+UIView_Gestures.h"
#import <objc/runtime.h>

static char const * const GESTUREINFOKEY = "GESTUREINFOKEY";

@interface UIGestureRecognizer (UIView_Gestures)

@property (nonatomic) SwipeGestureRecognizerInfo* swipeInfo;
@property (nonatomic) TapGestureRecognizerInfo* tapInfo;
@property (nonatomic) LongPressGestureRecognizerInfo* longPressInfo;
@property (nonatomic) PanGestureRecognizerInfo* panInfo;
@property (nonatomic) PinchGestureRecognizerInfo* pinchInfo;
@property (nonatomic) RotationGestureRecognizerInfo* rotationInfo;
@property (nonatomic) ScreenEdgePanGestureRecognizerInfo* screenEdgePanInfo;

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

@dynamic longPressInfo;

- (void)setLongPressInfo:(LongPressGestureRecognizerInfo *)info
{
    objc_setAssociatedObject(self, GESTUREINFOKEY, [NSValue valueWithPointer:info], OBJC_ASSOCIATION_RETAIN_NONATOMIC);
}

- (LongPressGestureRecognizerInfo *)longPressInfo
{
    return (LongPressGestureRecognizerInfo *)[(NSValue *)objc_getAssociatedObject(self, GESTUREINFOKEY) pointerValue];
}


@dynamic panInfo;

- (void)setPanInfo:(PanGestureRecognizerInfo *)info
{
    objc_setAssociatedObject(self, GESTUREINFOKEY, [NSValue valueWithPointer:info], OBJC_ASSOCIATION_RETAIN_NONATOMIC);
}

- (PanGestureRecognizerInfo *)panInfo
{
    return (PanGestureRecognizerInfo *)[(NSValue *)objc_getAssociatedObject(self, GESTUREINFOKEY) pointerValue];
}

@dynamic pinchInfo;

- (void)setPinchInfo:(PinchGestureRecognizerInfo *)info
{
    objc_setAssociatedObject(self, GESTUREINFOKEY, [NSValue valueWithPointer:info], OBJC_ASSOCIATION_RETAIN_NONATOMIC);
}

- (PinchGestureRecognizerInfo *)pinchInfo
{
    return (PinchGestureRecognizerInfo *)[(NSValue *)objc_getAssociatedObject(self, GESTUREINFOKEY) pointerValue];
}

@dynamic rotationInfo;

- (void)setRotationInfo:(RotationGestureRecognizerInfo *)info
{
    objc_setAssociatedObject(self, GESTUREINFOKEY, [NSValue valueWithPointer:info], OBJC_ASSOCIATION_RETAIN_NONATOMIC);
}

- (RotationGestureRecognizerInfo *)rotationInfo
{
    return (RotationGestureRecognizerInfo *)[(NSValue *)objc_getAssociatedObject(self, GESTUREINFOKEY) pointerValue];
}

@dynamic screenEdgePanInfo;

- (void)setScreenEdgePanInfo:(ScreenEdgePanGestureRecognizerInfo *)info
{
    objc_setAssociatedObject(self, GESTUREINFOKEY, [NSValue valueWithPointer:info], OBJC_ASSOCIATION_RETAIN_NONATOMIC);
}

- (ScreenEdgePanGestureRecognizerInfo *)screenEdgePanInfo
{
    return (ScreenEdgePanGestureRecognizerInfo *)[(NSValue *)objc_getAssociatedObject(self, GESTUREINFOKEY) pointerValue];
}


@end

@interface UIView(UIView_Gestures_Internal)

- (void)handleSwipeGestureRecognizer:(UIGestureRecognizer *)gestureRecognizer;

- (void)handleTapGestureRecognizer:(UIGestureRecognizer *)gestureRecognizer;

- (void)handlePanGestureRecognizer:(UIGestureRecognizer *)gestureRecognizer;

- (void)handlePinchGestureRecognizer:(UIGestureRecognizer *)gestureRecognizer;

- (void)handleRotationGestureRecognizer:(UIGestureRecognizer *)gestureRecognizer;

@end

@implementation UIView (UIView_Gestures)

- (void)addSwipeGestures:(std::vector<SwipeGestureRecognizerInfo*>)SwipeGestureRecognizerInfos
{
    for( auto *rec : SwipeGestureRecognizerInfos )
    {
        UISwipeGestureRecognizerDirection direction = 0;
        
        if( rec->getRight() )
        {
            direction |= UISwipeGestureRecognizerDirectionRight;
        }
        if( rec->getLeft() )
        {
            direction |= UISwipeGestureRecognizerDirectionLeft;
        }
        if( rec->getUp() )
        {
            direction |= UISwipeGestureRecognizerDirectionUp;
        }
        if( rec->getDown() )
        {
            direction |= UISwipeGestureRecognizerDirectionDown;
        }
        
        UISwipeGestureRecognizer *gestureRecognizer = [[UISwipeGestureRecognizer alloc] initWithTarget:self action:@selector(handleSwipeGestureRecognizer:)];
        
        [gestureRecognizer setSwipeInfo:rec];
        [gestureRecognizer setDirection:direction];
        
        [self addGestureRecognizer:gestureRecognizer];
#if  ! __has_feature(objc_arc)
        [gestureRecognizer release];
#endif
    }
}

- (void)addTapGestures:(TapGestureRecognizerInfo*)singleTapInfo :(TapGestureRecognizerInfo*)doubleTapInfo
{
    UITapGestureRecognizer *singleTapRecognizer = nil;
    if( singleTapInfo != nil )
    {
        singleTapRecognizer = [[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(handleTapGestureRecognizer:)];
        [singleTapRecognizer setTapInfo:singleTapInfo];
        [singleTapRecognizer setNumberOfTapsRequired:1];
        [self addGestureRecognizer:singleTapRecognizer];
    }
    
    UITapGestureRecognizer *doubleTapRecognizer = nil;
    if( doubleTapInfo != nil )
    {
        doubleTapRecognizer = [[UITapGestureRecognizer alloc] initWithTarget : self action:@selector(handleTapGestureRecognizer:)];
        [doubleTapRecognizer setTapInfo:doubleTapInfo];
        [doubleTapRecognizer setNumberOfTapsRequired:2];
        [self addGestureRecognizer:doubleTapRecognizer];
    }
    
    if( ( singleTapRecognizer != nil ) && ( doubleTapRecognizer != nil ) )
    {
        [singleTapRecognizer requireGestureRecognizerToFail : doubleTapRecognizer]; // Allow both gestures to exist.
    }
#if  ! __has_feature(objc_arc)
    if( singleTapRecognizer != nil )
    {
        [singleTapRecognizer release];
    }
    if( doubleTapRecognizer != nil )
    {
        [doubleTapRecognizer release];
    }
#endif
}

- (void)addLongPressGesture:(LongPressGestureRecognizerInfo*)longPressInfo
{
    UILongPressGestureRecognizer *longPressGestureRecognizer = [[UILongPressGestureRecognizer alloc] initWithTarget:self action:@selector(handleLongPressGestureRecognizer:)];
    [longPressGestureRecognizer setLongPressInfo:longPressInfo];
    [self addGestureRecognizer:longPressGestureRecognizer];
#if  ! __has_feature(objc_arc)
    [longPressGestureRecognizer release];
#endif
}


- (void)addPinchGesture:(PinchGestureRecognizerInfo*)pinchInfo
{
    UIPinchGestureRecognizer *pinchGestureRecognizer = [[UIPinchGestureRecognizer alloc] initWithTarget:self action:@selector(handlePinchGestureRecognizer:)];
    [pinchGestureRecognizer setPinchInfo:pinchInfo];
    [self addGestureRecognizer:pinchGestureRecognizer];
#if  ! __has_feature(objc_arc)
    [pinchGestureRecognizer release];
#endif
}

- (void)addPanGesture:(PanGestureRecognizerInfo*)panInfo
{
    UIPanGestureRecognizer *panGestureRecognizer = [[UIPanGestureRecognizer alloc] initWithTarget:self action:@selector(handlePanGestureRecognizer:)];
    [panGestureRecognizer setPanInfo:panInfo];
    [self addGestureRecognizer:panGestureRecognizer];
    
#if  ! __has_feature(objc_arc)
    [panGestureRecognizer release];
#endif
}

- (void)addRotationGesture:(RotationGestureRecognizerInfo*)rotationInfo
{
    UIRotationGestureRecognizer *rotateGestureRecognizer = [[UIRotationGestureRecognizer alloc] initWithTarget:self action:@selector(handleRotationGestureRecognizer:)];
    [rotateGestureRecognizer setRotationInfo:rotationInfo];
    [self addGestureRecognizer:rotateGestureRecognizer];
#if  ! __has_feature(objc_arc)
    [rotateGestureRecognizer release];
#endif
}

- (void)addScreenEdgePanGesture:(ScreenEdgePanGestureRecognizerInfo*)screenEdgePanInfo
{
    UIScreenEdgePanGestureRecognizer *screenEdgePanGestureRecognizer = [[UIScreenEdgePanGestureRecognizer alloc] initWithTarget:self action:@selector(handleScreenEdgePanGestureRecognizer:)];
    screenEdgePanGestureRecognizer.edges = UIRectEdgeLeft;
    [screenEdgePanGestureRecognizer setScreenEdgePanInfo:screenEdgePanInfo];
    [self addGestureRecognizer:screenEdgePanGestureRecognizer];
#if  ! __has_feature(objc_arc)
    [screenEdgePanGestureRecognizer release];
#endif
}

- (void)addScreenEdgePanAndPanGesture:(ScreenEdgePanGestureRecognizerInfo*)screenEdgePanInfo:
(PanGestureRecognizerInfo*)panInfo
{
    UIPanGestureRecognizer *panGestureRecognizer = [[UIPanGestureRecognizer alloc] initWithTarget:self action:@selector(handlePanGestureRecognizer:)];
    [panGestureRecognizer setPanInfo:panInfo];
    [self addGestureRecognizer:panGestureRecognizer];
    
    
    UIScreenEdgePanGestureRecognizer *screenEdgePanGestureRecognizer = [[UIScreenEdgePanGestureRecognizer alloc] initWithTarget:self action:@selector(handleScreenEdgePanGestureRecognizer:)];
    screenEdgePanGestureRecognizer.edges = UIRectEdgeLeft;// UIRectEdgeRight;
    [screenEdgePanGestureRecognizer setScreenEdgePanInfo:screenEdgePanInfo];
    [self addGestureRecognizer:screenEdgePanGestureRecognizer];
    
    [panGestureRecognizer requireGestureRecognizerToFail : screenEdgePanGestureRecognizer];
#if  ! __has_feature(objc_arc)
    [screenEdgePanGestureRecognizer release];
    [panGestureRecognizer release];
#endif
}

-(void)enableSwipegeGestures:(bool)state
{
    for (UIGestureRecognizer *recognizer in self.gestureRecognizers) {
      if([recognizer isKindOfClass:[UISwipeGestureRecognizer class]]) {
        recognizer.enabled = state;
      }
    }
}

- (void)removeSwipeGestures
{
    for (UIGestureRecognizer *recognizer in self.gestureRecognizers) {
      if([recognizer isKindOfClass:[UISwipeGestureRecognizer class]]) {
        [self removeGestureRecognizer:recognizer];
      }
    }
}

- (void)removeTapGestures
{
    for (UIGestureRecognizer *recognizer in self.gestureRecognizers) {
      if([recognizer isKindOfClass:[UITapGestureRecognizer class]]) {
        [self removeGestureRecognizer:recognizer];
      }
    }
}

- (void)removePanGestures
{
    for (UIGestureRecognizer *recognizer in self.gestureRecognizers) {
      if([recognizer isKindOfClass:[UIPanGestureRecognizer class]]) {
        [self removeGestureRecognizer:recognizer];
      }
    }
}

- (void)removePinchGestures
{
    for (UIGestureRecognizer *recognizer in self.gestureRecognizers) {
      if([recognizer isKindOfClass:[UIPinchGestureRecognizer class]]) {
        [self removeGestureRecognizer:recognizer];
      }
    }
}

- (void)removeRotationGestures
{
    for (UIGestureRecognizer *recognizer in self.gestureRecognizers) {
      if([recognizer isKindOfClass:[UIRotationGestureRecognizer class]]) {
        [self removeGestureRecognizer:recognizer];
      }
    }
}

- (void)removeScreenEdgePanGesture
{
    for (UIGestureRecognizer *recognizer in self.gestureRecognizers) {
      if([recognizer isKindOfClass:[UIScreenEdgePanGestureRecognizer class]]) {
        [self removeGestureRecognizer:recognizer];
      }
    }
}

- (void)removeLongPressGesture
{
    for (UIGestureRecognizer *recognizer in self.gestureRecognizers) {
      if([recognizer isKindOfClass:[UILongPressGestureRecognizer class]]) {
        [self removeGestureRecognizer:recognizer];
      }
    }
}

- (void)removeAllGestures
{
    for (UIGestureRecognizer *recognizer in self.gestureRecognizers)
    {
        [self removeGestureRecognizer:recognizer];
    }
}

@end

@implementation UIView (UIView_Gestures_Internal)

- (void)handleSwipeGestureRecognizer:(UISwipeGestureRecognizer *)gestureRecognizer
{
    CGPoint touchLocation = [gestureRecognizer locationInView:gestureRecognizer.view];
    gestureRecognizer.swipeInfo->getCallback()(touchLocation.x, touchLocation.y);
}

- (void)handleTapGestureRecognizer:(UITapGestureRecognizer *)gestureRecognizer
{
    CGPoint touchLocation = [gestureRecognizer locationInView:gestureRecognizer.view];
    gestureRecognizer.tapInfo->setTouchLocation(touchLocation.x, touchLocation.y);
    gestureRecognizer.tapInfo->getCallback()(touchLocation.x, touchLocation.y);
}

- (void)handleLongPressGestureRecognizer:(UILongPressGestureRecognizer *)gestureRecognizer
{
    CGPoint touchLocation = [gestureRecognizer locationInView:gestureRecognizer.view];
    gestureRecognizer.longPressInfo->setTouchLocation(touchLocation.x, touchLocation.y);
    gestureRecognizer.longPressInfo->getCallback()(touchLocation.x, touchLocation.y);
}

- (void)handlePanGestureRecognizer:(UIPanGestureRecognizer *)gestureRecognizer
{
    CGPoint touchLocation = [gestureRecognizer locationInView:gestureRecognizer.view];
    gestureRecognizer.panInfo->setTouchLocation(touchLocation.x, touchLocation.y);
    gestureRecognizer.panInfo->getCallback()(touchLocation.x, touchLocation.y);
}

- (void)handlePinchGestureRecognizer:(UIPinchGestureRecognizer *)gestureRecognizer
{
    //self.transform = CGAffineTransformScale(self.transform, gestureRecognizer.scale, gestureRecognizer.scale);
    
    
    //gestureRecognizer.view.transform = CGAffineTransformScale(gestureRecognizer.view.transform, gestureRecognizer.scale, gestureRecognizer.scale);
    
    //float s = gestureRecognizer.scale;
    
    //gestureRecognizer.scale = 1.0;
    
    CGPoint touchLocation = [gestureRecognizer locationInView:gestureRecognizer.view];
    gestureRecognizer.pinchInfo->setScale(gestureRecognizer.scale);
    gestureRecognizer.pinchInfo->getCallback()(touchLocation.x, touchLocation.y, gestureRecognizer.scale);
}

-(void)handleRotationGestureRecognizer:(UIRotationGestureRecognizer *)gestureRecognizer
{
    //self.testView.transform = CGAffineTransformRotate(self.testView.transform, gestureRecognizer.rotation);
 
    //gestureRecognizer.rotation = 0.0;
    CGPoint touchLocation = [gestureRecognizer locationInView:gestureRecognizer.view];
    gestureRecognizer.rotationInfo->setRotation(gestureRecognizer.rotation);
    gestureRecognizer.rotationInfo->getCallback()(touchLocation.x, touchLocation.y, gestureRecognizer.rotation);
}

- (void)handleScreenEdgePanGestureRecognizer:(UIScreenEdgePanGestureRecognizer *)gestureRecognizer
{
    CGPoint touchLocation = [gestureRecognizer locationInView:gestureRecognizer.view];
    gestureRecognizer.panInfo->setTouchLocation(touchLocation.x, touchLocation.y);
    gestureRecognizer.panInfo->getCallback()(touchLocation.x, touchLocation.y);
}


@end
