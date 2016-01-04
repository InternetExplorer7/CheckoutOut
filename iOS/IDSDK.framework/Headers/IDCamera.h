//
//  IDCamera.h
//  IDSDK
//
//  Copyright 2015 Nantmobile, LLC. All rights reserved.
//
//  This software is provided "as is", without warranty of any kind, express
//  or implied, including but not limited to the warranties of
//  merchantability, fitness for a particular purpose and noninfringement. In
//  no event shall the authors be liable for any claim, damages or other
//  liability, whether in an action of contract, tort or otherwise, arising
//  from, out of or in connection with the software or the use or other
//  dealings in the software.
//

#import <UIKit/UIKit.h>

/**
 * This enum identifies the focus mode.
 */
typedef NS_ENUM(NSInteger, IDCameraFocus) {
/**
 * Camera focus mode: fixed.
 */
    IDCameraFocusFixed,
/**
 * Camera focus mode: perform a single autofocus operation.
 */
    IDCameraFocusTriggerAuto,
/**
 * Camera focus mode: continuous autofocusing.
 */
	IDCameraFocusContinuousAuto,
/**
 * Camera focus mode: fixed at infinity.
 */
    IDCameraFocusInfinity,
/**
 * Camera focus mode: macro / close-up.
 */
    IDCameraFocusMacro
};

/**
 * This enum identifies the camera.
 */
typedef NS_ENUM(NSInteger, IDCameraFacing) {

/**
 * Unknown camera.
 */
    IDCameraFacingUnknown,
/**
 * Back camera.
 */
    IDCameraFacingBack,
/**
 * Front camera.
 */
    IDCameraFacingFront
};

/** Represents the device camera; provides for camera selection and management.
*/
@class IDARView;

@interface IDCamera : NSObject

/** Indicates whether the camera is  open.
 */
@property (nonatomic, readonly, getter=isOpened) BOOL opened;

/** Gets the camera zoom value.
 */
@property (nonatomic, readonly) float zoom;

/**  Gets the camera facing direction.
 */
@property (nonatomic, readonly) IDCameraFacing facing;

/**  Gets the camera focus mode.
 */
@property (nonatomic, readonly) IDCameraFocus focus;

/** Indicates whether a torch (light) is available on this device.
 */
@property (nonatomic, readonly) BOOL hasTorch;

/**  Indicates whether the torch is  on.
 */
@property (nonatomic, readonly) BOOL isTorchOn;

/** Indicates whether the camera is started.
 */
@property (nonatomic, readonly, getter=isStarted) BOOL started;

/**  IDARView object must be set to this property in order for IDARView to function properly.
 */
@property (nonatomic, readonly) IDARView * arView;

/**  Returns the default IDCamera instance.
 *  @return IDCamera object
 */
+ (instancetype)defaultCamera;

/**
 *  Opens the back camera, if available. If the device has no back camera then the front camera is opened.
 *
 *	@param view IDARView
 *  @param error NSError
 *
 *  @return Instance of IDCamera
 */
- (BOOL)openForView:(IDARView *)view error:(NSError **)error;

/**
 *  Opens a specific camera.
 *
 *	@param view IDARView
 *  @param facing - value from IDCameraFacing enum
 *  @param error NSError
 *
 *  @return Instance of IDCamera.
 */
- (BOOL)openForView:(IDARView *)view withFacing:(IDCameraFacing)facing error:(NSError **)error;

/**
 *  Closes the camera.
 *
 *  @param error NSError
 *
 *  @return YES if successful, NO otherwise.
 */
- (BOOL)close:(NSError **)error;

/**
 *  Starts the camera.
 *
 *  @param error NSError
 *
 *  @return YES if successful, NO otherwise.
 */
- (BOOL)start:(NSError **)error;

/**
 *  Stops the camera.
 *
 *  @param error NSError
 *
 *  @return YES if successful, NO otherwise.
 */
- (BOOL)stop:(NSError **)error;

/**
 *  Sets camera zoom.
 *
 *  @param zoom Zoom value, 0.0 - 1.0, float
 *  @param error NSError
 *
 *  @return YES if successful, NO otherwise.
 */
- (BOOL)setZoom:(float)zoom error:(NSError **)error;

- (BOOL)zoomSupported;

- (float)zoom;

/**
 *  Sets the camera facing direction.
 *
 *  @param facing - value from IDCameraFacing enum
 *  @param error  NSError
 *
 *  @return YES if successful, NO otherwise.
 */
- (BOOL)setFacing:(IDCameraFacing)facing error:(NSError **)error;

- (BOOL)facingSupported:(IDCameraFacing)facing;

- (IDCameraFacing)facing;

/**
 *  Sets the camera focus mode
 *
 *  @param focus - Value from IDCameraFocus
 *  @param error NSError
 *
 *  @return YES if successful, NO otherwise.
 */
- (BOOL)setFocus:(IDCameraFocus)focus error:(NSError **)error;

/**
 *  Turns the torch on or off.
 *
 *  @param on - on or off
 *  @param error NSError
 *
 *  @return YES if successful, NO otherwise.
 */
- (BOOL)setTorch:(BOOL)on error:(NSError **)error;

/**
 *  Gets the latest captured video frame.
 *
 *  @param error NSError
 *
 *  @return UIImage containing captured frame. The return value is nil if an error occured.
 */
- (UIImage *)captureVideoFrame:(NSError **)error;

@end
