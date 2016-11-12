//
//  BFTaskCompletionSource+Expire.h
//  Umwho
//
//  Created by Felix Dumit on 3/29/15.
//  Copyright (c) 2015 Umwho. All rights reserved.
//

#import <Bolts/BFTaskCompletionSource.h>
#import <Bolts/BFTask.h>


extern NSInteger const kBFTimeoutError;


@interface BFTaskCompletionSource (Timeout)

/**
 *  Createas a task completion that expires after the provided timeout
 *
 *  @param timeout timeout in seconds
 *
 *  @return task completion source
 */
+ (instancetype)taskCompletionSourceWithExpiration:(NSTimeInterval)timeout;

@end


@interface BFTask (Timeout)



/**
 *   Whether this task has timed out
*/
@property (nonatomic, assign, readonly, getter=hasTimedOut) BOOL timedOut;

/**
 *  Sets a timeout for the current task
 *
 *  @param timeout timeout in seconds
 *
 *  @return the task that will be cancelled after the timeout
 */
- (instancetype)setTimeout:(NSTimeInterval)timeout;

@end


@interface NSError (TimeoutError)

/**
 If the error represents a Bolts timeout error
 */
@property (readonly, nonatomic) BOOL isTimeoutError;

@end


