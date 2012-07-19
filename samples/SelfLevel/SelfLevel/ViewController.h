//
//  ViewController.h
//  SelfLevel
//
//  Created by Michael DePhillips on 7/14/12.
//  Copyright (c) 2012 Orbotix Inc. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <RobotUIKit/RobotUIKit.h>

@interface ViewController : UIViewController {
    BOOL ledON;
    BOOL robotOnline;
    RUICalibrateGestureHandler *calibrateHandler;
}

-(void)setupRobotConnection;
-(void)handleRobotOnline;
-(void)toggleLED;

@end

