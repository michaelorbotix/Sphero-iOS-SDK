//
//  RKSelfLevelCompleteAsyncData.h
//  RobotKit
//
//  Created by Michael DePhillips on 7/14/12.
//  Copyright (c) 2012 Orbotix Inc. All rights reserved.
//

/*! @file */

#import "RKDeviceAsyncData.h"

/*!
 * The result byte can be: 00h = Unknown, 
 * 01h = Timed Out (level was not achieved),
 * 02h = Sensors Error, 
 * 03h = Self Level Disabled (see Option Flags), 
 * 04h = Aborted (by API call), 
 * 05h = Success
 */
enum RKSelfLevelCompleteResultCode {
    RKSelfLevelCompleteResultCodeUnknown          = 0x00,
    RKSelfLevelCompleteResultCodeTimeOut          = 0x01,
    RKSelfLevelCompleteResultCodeSensorsError     = 0x02,
    RKSelfLevelCompleteResultCodeSelfLevelDisable = 0x03,
    RKSelfLevelCompleteResultCodeAborted          = 0x04,
    RKSelfLevelCompleteResultCodeSuccess          = 0x05
};
/*! Type that is used for identifying the response code */
typedef enum RKSelfLevelCompleteResultCode RKSelfLevelCompleteResultCode;

/*!
 * @brief Class to represent the aync response after teh self level command has completed
 *
 * Async data packet sent when Device is done self leveling.  
 * Use the RKSelfLevelCompleteResultCode enum to determine the result of the command.
 *
 * @sa RKSelfLevelCommand
 *
 */
@interface RKSelfLevelCompleteAsyncData : RKDeviceAsyncData {
    @private
    RKSelfLevelCompleteResultCode resultCode;
}

/* Results code */
@property (nonatomic, readonly) RKSelfLevelCompleteResultCode resultCode;

@end
