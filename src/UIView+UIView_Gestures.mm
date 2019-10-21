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
@property (nonatomic) PanGestureRecognizerInfo* panInfo;
@property (nonatomic) PinchGestureRecognizerInfo* pinchInfo;
@property (nonatomic) RotationGestureRecognizerInfo* rotationInfo;

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
        
        [gestureRecognizer release];
    }
}

- (void)addTapGestures:(TapGestureRecognizerInfo*)singleTapInfo :(TapGestureRecognizerInfo*)doubleTapInfo
{
    UITapGestureRecognizer *singleTapRecognizer = [[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(handleTapGestureRecognizer:)];
    [singleTapRecognizer setTapInfo:singleTapInfo];
    [singleTapRecognizer setNumberOfTapsRequired:1];
    [self addGestureRecognizer:singleTapRecognizer];
    
    UITapGestureRecognizer *doubleTapRecognizer = [[UITapGestureRecognizer alloc] initWithTarget : self action:@selector(handleTapGestureRecognizer:)];
    [doubleTapRecognizer setTapInfo:doubleTapInfo];
    [doubleTapRecognizer setNumberOfTapsRequired:2];
    [self addGestureRecognizer:doubleTapRecognizer];
    
    [singleTapRecognizer requireGestureRecognizerToFail : doubleTapRecognizer];
    
    [singleTapRecognizer release];
    [doubleTapRecognizer release];
}

- (void)addPinchGestures:(PinchGestureRecognizerInfo*)pinchInfo
{
    UIPinchGestureRecognizer *pinchGestureRecognizer = [[UIPinchGestureRecognizer alloc] initWithTarget:self action:@selector(handlePinchGestureRecognizer:)];
    [pinchGestureRecognizer setPinchInfo:pinchInfo];
    [self addGestureRecognizer:pinchGestureRecognizer];
}

- (void)addPanGestures:(PanGestureRecognizerInfo*)panInfo
{
    UIPanGestureRecognizer *panGestureRecognizer = [[UIPanGestureRecognizer alloc] initWithTarget:self action:@selector(handlePanGestureRecognizer:)];
    [panGestureRecognizer setPanInfo:panInfo];
    [self addGestureRecognizer:panGestureRecognizer];

}

- (void)addRotationGestures:(RotationGestureRecognizerInfo*)rotationInfo
{
    UIRotationGestureRecognizer *rotateGestureRecognizer = [[UIRotationGestureRecognizer alloc] initWithTarget:self action:@selector(handleRotationGestureRecognizer:)];
    [rotateGestureRecognizer setRotationInfo:rotationInfo];
    [self addGestureRecognizer:rotateGestureRecognizer];
}

@end

@implementation UIView (UIView_Gestures_Internal)

- (void)handleSwipeGestureRecognizer:(UISwipeGestureRecognizer *)gestureRecognizer
{
    gestureRecognizer.swipeInfo->getCallback()();
}

- (void)handleTapGestureRecognizer:(UITapGestureRecognizer *)gestureRecognizer
{
    CGPoint pointInView = [gestureRecognizer locationInView:gestureRecognizer.view];
    gestureRecognizer.tapInfo->setTapLocation(pointInView.x, pointInView.y);
    gestureRecognizer.tapInfo->getCallback()();
}

- (void)handlePanGestureRecognizer:(UIPanGestureRecognizer *)gestureRecognizer
{
    CGPoint touchLocation = [gestureRecognizer locationInView:gestureRecognizer.view];
    gestureRecognizer.panInfo->setTapLocation(touchLocation.x, touchLocation.y);
    gestureRecognizer.panInfo->getCallback()();
}

- (void)handlePinchGestureRecognizer:(UIPinchGestureRecognizer *)gestureRecognizer
{
    //self.transform = CGAffineTransformScale(self.transform, gestureRecognizer.scale, gestureRecognizer.scale);
    
    
    //gestureRecognizer.view.transform = CGAffineTransformScale(gestureRecognizer.view.transform, gestureRecognizer.scale, gestureRecognizer.scale);
    
    //float s = gestureRecognizer.scale;
    
    //gestureRecognizer.scale = 1.0;
    
    
    gestureRecognizer.pinchInfo->setScale(gestureRecognizer.scale);
    gestureRecognizer.pinchInfo->getCallback()();
}

-(void)handleRotationGestureRecognizer:(UIRotationGestureRecognizer *)gestureRecognizer
{
    //self.testView.transform = CGAffineTransformRotate(self.testView.transform, gestureRecognizer.rotation);
 
    //gestureRecognizer.rotation = 0.0;
    gestureRecognizer.rotationInfo->setRotation(gestureRecognizer.rotation);
    gestureRecognizer.rotationInfo->getCallback()();
}


@end
