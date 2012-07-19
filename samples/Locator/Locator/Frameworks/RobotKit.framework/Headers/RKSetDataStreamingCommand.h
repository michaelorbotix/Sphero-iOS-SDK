//
//  RKSetDataStreamingCommand.h
//  RobotKit
//
//  Created by Brian Smith on 7/7/11.
//  Copyright 2011 Orbotix Inc. All rights reserved.
//

/*! @file */

#import <Foundation/Foundation.h>
#import <RobotKit/RKDeviceCommand.h>

/*! Type that is used for setting the data streaming mask */
typedef uint32_t RKDataStreamingMask;
/*! Mask values that are used to enable the sensor data values that client
 * code is interested in.
 */
enum {
    /*! Turns off all data streaming. */
    RKDataStreamingMaskOff                          = 0x00000000,
    RKDataStreamingMaskLeftMotorBackEMFFiltered     = 0x00000020,
    RKDataStreamingMaskRightMotorBackEMFFiltered    = 0x00000040,
    RKDataStreamingMaskMagnetometerZFiltered        = 0x00000080,
    RKDataStreamingMaskMagnetometerYFiltered        = 0x00000100,
    RKDataStreamingMaskMagnetometerXFiltered        = 0x00000200,
    RKDataStreamingMaskGyroZFiltered                = 0x00000400,
    RKDataStreamingMaskGyroYFiltered                = 0x00000800,
    RKDataStreamingMaskGyroXFiltered                = 0x00001000,
    RKDataStreamingMaskAccelerometerZFiltered       = 0x00002000,
    RKDataStreamingMaskAccelerometerYFiltered       = 0x00004000,
    RKDataStreamingMaskAccelerometerXFiltered       = 0x00008000,
    RKDataStreamingMaskIMUYawAngleFiltered          = 0x00010000,
    RKDataStreamingMaskIMURollAngleFiltered         = 0x00020000,
    RKDataStreamingMaskIMUPitchAngleFiltered        = 0x00040000,
    RKDataStreamingMaskLeftMotorBackEMFRaw          = 0x00200000,
    RKDataStreamingMaskRightMotorBackEMFRaw         = 0x00400000,
    RKDataStreamingMaskMagnetometerZRaw             = 0x00800000,
    RKDataStreamingMaskMagnetometerYRaw             = 0x01000000,
    RKDataStreamingMaskMagnetometerXRaw             = 0x02000000,
    RKDataStreamingMaskGyroZRaw                     = 0x04000000,
    RKDataStreamingMaskGyroYRaw                     = 0x08000000,
    RKDataStreamingMaskGyroXRaw                     = 0x10000000,
    RKDataStreamingMaskAccelerometerZRaw            = 0x20000000,
    RKDataStreamingMaskAccelerometerYRaw            = 0x40000000,
    RKDataStreamingMaskAccelerometerXRaw            = 0x80000000
};

/*! Type that is used for setting the data streaming mask 2 onlt for Firmware 1.17 or greater. */
typedef uint32_t RKDataStreamingMask2;
/*! Mask values that are used to enable the sensor data values that client
 * code is interested in. Only Firmware 1.17 or greater.
 */
enum {
    RKDataStreamingMask2Off                         = 0x00000000,
    RKDataStreamingMask2Quaternion0                 = 0x80000000,
    RKDataStreamingMask2Quaternion1                 = 0x40000000,
    RKDataStreamingMask2Quaternion2                 = 0x20000000,
    RKDataStreamingMask2Quaternion3                 = 0x10000000,
    RKDataStreamingMask2LocatorX                    = 0x08000000,
    RKDataStreamingMask2LocatorY                    = 0x04000000,
    RKDataStreamingMask2AccelOne                    = 0x02000000,
    RKDataStreamingMask2VelocityX                   = 0x01000000,
    RKDataStreamingMask2VelocityY                   = 0x00800000
};

/*!
 * @brief Class that encapsulates a set data streaming command.
 *
 *  Class that encapsulates a set data streaming command, which allows client code to
 * initiate data streaming of specific sensor data. A mask is used to enable the sensor 
 * data values of interest. The rate in which data can be set a divisor for a sample rate of
 * 400Hz, and a sample frame count can be set that limits packets being sent after this count
 * has been sampled.
 *
 *
 * @sa RKsetDataStreamingCommand
 */
@interface RKSetDataStreamingCommand : RKDeviceCommand {
    uint16_t                sampleRateDivisor;
    uint16_t                packetFrames;
    RKDataStreamingMask     requestMask;  
    RKDataStreamingMask2    requestMask2;
    uint8_t                 packetCount;
}

/*! Read only property to the sample rate divisor. */
@property (nonatomic, readonly) uint16_t                sampleRateDivisor;
/*! Read only property to the sample frame count. */
@property (nonatomic, readonly) uint16_t                packetFrames;
/*! Read only property to the request mask. */
@property (nonatomic, readonly) RKDataStreamingMask     requestMask;
/*! Read only property to the request mask 2. Only for Firmware 1.17 or greater */
@property (nonatomic, readonly) RKDataStreamingMask2    requestMask2;
/*! Read only property for the number of packets to send */
@property (nonatomic, readonly) uint8_t                 packetCount;

/*! 
 * Keeps track of the current mask being used for streamed data. 
 */
+ (RKDataStreamingMask)currentMask;

/*! 
 * Keeps track of the current mask 2 being used for streamed data.
 * Firmware 1.17 or greater.
 */
+ (RKDataStreamingMask)currentMask2;

/*!
 * Convenience method to send the message to the robotic device.
 * @param devisor A number to divide the maximum sample rate of 400Hz by. 
 * @param frames The number of sample frames to send in a single packet.
 * @param mask A bitwise OR value of the sensor values to include in data streaming. Set to
 * RKDataStreamingMaskOff or 0 to disable data streaming.
 * @param count Then number of packets that Sphero will send. Set to 0 for infinite data
 * streaming.
 */
+ (void)sendCommandWithSampleRateDivisor:(uint16_t)devisor 
                            packetFrames:(uint16_t)frames 
                              sensorMask:(uint32_t)mask 
                             packetCount:(uint8_t)count;

/*
 * Convenience method to send the message to the robotic device to stop data streaming
 * Sends the sensor mask of RKDataStreamingMaskOff and all other params 0
 */
+ (void)sendCommandStopStreaming;

/*!
 * Initializer to set up the command.
 */
- (id)initWithSampleRateDivisor:(uint16_t)devisor 
                   packetFrames:(uint16_t)frames 
                     sensorMask:(uint32_t)mask 
                    packetCount:(uint8_t)count;

/*!
 * Convenience method to send the message to the robotic device. For Firmware 1.17 or greater
 * @param devisor A number to divide the maximum sample rate of 400Hz by. 
 * @param frames The number of sample frames to send in a single packet.
 * @param mask A bitwise OR value of the sensor values to include in data streaming. Set to
 * RKDataStreamingMaskOff or 0 to disable data streaming.
 * @param count Then number of packets that Sphero will send. Set to 0 for infinite data
 * @param mask2 A bitwise OR value of the addition sensor values as of Firmware 1.17 or greater.
 * RKDataStreamingMask2Off or 0 to disable data streaming
 * streaming.
 */
+ (void)sendCommandWithSampleRateDivisor:(uint16_t)devisor 
                            packetFrames:(uint16_t)frames 
                              sensorMask:(uint32_t)mask 
                             packetCount:(uint8_t)count
                             sensorMask2:(uint32_t)mask2;

/*!
 * Initializer to set up the command with full mask for Firmware 1.17 or greater
 */
- (id)initWithSampleRateDivisor:(uint16_t)devisor 
                   packetFrames:(uint16_t)frames 
                     sensorMask:(uint32_t)mask 
                    packetCount:(uint8_t)count
                    sensorMask2:(uint32_t)mask2;

@end
