//
//  TechSee.h
//  TechSeeLiveFramework
//
//  Created by TechSee Shlomi on 16/11/2017.
//  Copyright © 2017 techsee. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ReplayKit/ReplayKit.h>

typedef NS_ENUM(NSUInteger, enviroments) {
    none = 0,
    app = 1,
    app1 = 2,
    demo = 3,
    staging = 4,
    rc = 5,
    test = 6,
    pretest = 7,
    hagrid = 8
};

typedef enum : NSUInteger {
    BroadcastStarted,
    BroadcastPaused,
    BroadcastResumed,
    BroadcastFinished,
} BroadcastStatus;

@protocol AuthenticationProtool <NSObject>
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



@interface TechSee : NSObject


#pragma mark - TechSee API's -


@property (weak, nonatomic) id <AuthenticationProtool> _Nullable delegate;
@property (weak, nonatomic) id <StartSessionProtocol> _Nullable delegateStartSession;
@property (weak, nonatomic) id <JoinSessionProtocol> _Nullable delegateJoinSession;
+ (instancetype _Nonnull )shared;
- (void)authenticate: (NSString *_Nonnull)apiKey apiSecret: (NSString *_Nullable)apiSecret env:(NSString *_Nonnull)env;
//- (void)authenticate:(NSString *)apiKey apiSecret:(NSString *)apiSecret;
// (void)authenticate: (NSString *)username password: (NSString *)password env:(NSString *)env;
- (void)joinSession: (NSURL *_Nonnull)sessionLink;
- (NSMutableData *_Nullable)getLogs;
//- (void)startSession;
- (NSString *_Nonnull)closeSession;


#pragma mark - App extension API's -

- (void)broadcastStarted;
- (void)broadcastPaused;
- (void)broadcastResumed;
- (void)broadcastFinished;
- (void)processSampleBuffer:(CMSampleBufferRef _Nonnull )sampleBuffer WithSampleBufferType:(RPSampleBufferType)sampleBufferType;
- (void)userDidFinishSetup;
- (void)userDidCancelSetup;
@end
