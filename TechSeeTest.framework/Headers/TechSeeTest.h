//
//  TechSeeTest.h
//  TechSeeTest
//
//  Created by Shlomi Sharon on 24/04/2020.
//  Copyright © 2020 TechSee. All rights reserved.
//

#import <Foundation/Foundation.h>

//! Project version number for TechSeeTest.
FOUNDATION_EXPORT double TechSeeTestVersionNumber;

typedef enum : NSUInteger {
    BroadcastStarted,
    BroadcastPaused,
    BroadcastResumed,
    BroadcastFinished,
} BroadcastStatus;

@protocol AuthenticationProtocol <NSObject>
- (void)authenticateSuccessful;
- (void)authenticateFailure:(NSString * _Nullable)error internalError :(NSString * _Nullable)internalError;
@end

@protocol JoinSessionProtocol <NSObject>
- (void)joinSessionSuccessful:(NSString * _Nullable)sdkVersionStatus newSDKVersion:(NSString *_Nullable)newSDKVersion;
- (void)joinSessionFailure:(NSString *_Nonnull)error sdkVersionStatus:(NSString * _Nullable)sdkVersionStatus newSDKVersion:(NSString * _Nullable)newSDKVersion;
@end

@protocol StartSessionProtocol <NSObject>
- (void)startSession:(NSString *_Nonnull)roomCode;
- (void)startSessionFailure:(NSString *_Nullable)error;
@end

@protocol ScreenTOS <NSObject>
- (void)tosApproval:(BOOL)isApprove;
@end

@protocol Cursor <NSObject>
- (void)moveCursor:(CGRect)frame;
- (void)hideCursor;
@end


@interface TechSeeTest : NSObject


#pragma mark - TechSee API's -


@property (weak, nonatomic) id <AuthenticationProtocol> _Nullable delegate;
@property (weak, nonatomic) id <StartSessionProtocol> _Nullable delegateStartSession;
@property (weak, nonatomic) id <JoinSessionProtocol> _Nullable delegateJoinSession;
@property (weak, nonatomic) id <ScreenTOS> _Nullable screenTOS;
@property (weak, nonatomic) id <Cursor> _Nullable cursor;
@property (nonatomic, strong) NSString * _Nullable backendURL;
+ (instancetype _Nonnull )shared;
//- (void)authenticate: (NSString *_Nonnull)apiKey apiSecret: (NSString *_Nullable)apiSecret env:(NSString *_Nonnull)env;
- (void)authenticate:(NSString *_Nonnull)apiKey apiSecret:(NSString *_Nonnull)apiSecret;
- (void)joinSession: (NSURL *_Nonnull)sessionLink;
- (NSMutableData *_Nullable)getLogs;
//- (void)startSession;
- (NSString *_Nonnull)closeSession;


#pragma mark - App extension API's -

- (void)broadcastStarted:(RPBroadcastSampleHandler *_Nonnull)handler;
- (void)broadcastPaused;
- (void)broadcastResumed;
- (void)broadcastFinished;
- (void)processSampleBuffer:(CMSampleBufferRef _Nonnull )sampleBuffer WithSampleBufferType:(RPSampleBufferType)sampleBufferType;
- (void)userDidFinishSetup;
- (void)userDidCancelSetup;
@end



//! Project version string for TechSeeTest.
FOUNDATION_EXPORT const unsigned char TechSeeTestVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <TechSeeTest/PublicHeader.h>


