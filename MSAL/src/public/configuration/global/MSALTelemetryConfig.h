//------------------------------------------------------------------------------
//
// Copyright (c) Microsoft Corporation.
// All rights reserved.
//
// This code is licensed under the MIT License.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files(the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and / or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions :
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
//------------------------------------------------------------------------------

#import <Foundation/Foundation.h>


/*!
 @protocol MSALTelemetryDispatcher
 
 Developer should implement it in order to receive telemetry events.
 
 Usage: an instance of MSALTelemetryDispatcher implementation is required when registerring dispatcher for MSALTelemetry.
 */
@protocol MSALTelemetryDispatcher <NSObject>

/*!
 Callback function that will be called by MSAL when telemetry events are flushed.
 @param events events is represented by an array of dictionary of key-value pair of event property name/value.
 */
- (void)dispatchEvent:(nonnull NSArray<NSDictionary<NSString *, NSString *> *> *)events;
/*!
 Configuration to dispatch only for failures.
 */
- (BOOL)onFailureOnly;

@end



NS_ASSUME_NONNULL_BEGIN

@interface MSALTelemetryConfig : NSObject

/*!
 Setting piiEnabled to YES, will allow MSAL to return fields with user information in the telemetry events. MSAL does not send telemetry data by itself to any server. If apps want to collect MSAL telemetry with user information they must setup the telemetry callback and set this flag on. By default MSAL will not return any user information in telemetry.
 */
@property BOOL piiEnabled;

/*!
 Register a telemetry dispatcher for receiving telemetry events.
 @param dispatcher              An instance of MSALTelemetryDispatcher implementation.
 @param setTelemetryOnFailure   If set YES, telemetry events are only dispatched when errors occurred;
 If set NO, MSAL will dispatch will dispatch all events.
 */
- (void)addDispatcher:(nonnull id<MSALTelemetryDispatcher>)dispatcher setTelemetryOnFailure:(BOOL)setTelemetryOnFailure;

/*!
 Remove a telemetry dispatcher added for receiving telemetry events.
 @param dispatcher An instance of MSALTelemetryDispatcher implementation added to the dispatches before.
 */
- (void)removeDispatcher:(nonnull id<MSALTelemetryDispatcher>)dispatcher;

/*!
 Remove all telemetry dispatchers added to the dispatchers collection.
 */
- (void)removeAllDispatchers;

- (nonnull instancetype)init NS_UNAVAILABLE;
+ (nonnull instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
