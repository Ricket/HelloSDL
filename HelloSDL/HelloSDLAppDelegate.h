//
//  HelloSDLAppDelegate.h
//  HelloSDL
//
//  Created by Ricky Carter on 5/30/11.
//  Copyright 2011 Student. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface HelloSDLAppDelegate : NSObject <NSApplicationDelegate> {
@private
    NSWindow *window;
}

@property (assign) IBOutlet NSWindow *window;

@end
