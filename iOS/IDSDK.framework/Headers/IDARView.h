//
//  IDARView.h
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

/** AR View is a subclass of UIView and is used for presenting augmented reality experiences.

*/
@class IDARPackage, IDEngine;
@protocol IDARViewDelegate;

@interface IDARView : UIView

/**
 *  Load an IDARPackage object. You can have multiple IDARPackages loaded at the same time.
 *
 *  @param package    IDARPackage
 *  @param completion Completion block. The error object is nil if successful.
 */
- (void)loadPackage:(IDARPackage *)package completion:(void (^)(NSError * error))completion;

/**
 *  Unload an IDARPackage object. Useful to reduce and clean up memory usage.
 *
 *  @param package    IDARPackage
 *  @param completion Completion block. The error object is nil if successful.
 */
- (void)unloadPackage:(IDARPackage *)package completion:(void (^)(NSError * error))completion;

/**
 *  Unload all IDARPackage objects. Useful to clean up memory.
 *
 *  @param completion Completion block. The error object is nil if successful.
 */
- (void)unloadAllPackages:(void (^)(NSError * error))completion;

/**
 *  Array of IDARPackage objects that are loaded and active.
 */
@property (nonatomic, readonly) NSArray *loadedPackages;

/**
 *  Property that determines whether the bounding box and visual features are displayed while the marker is being tracked.
 */
@property (nonatomic, getter=isVisualFeedbackEnabled) BOOL visualFeedbackEnabled;

@property (nonatomic, weak) id <IDARViewDelegate> delegate;

- (uint32_t)maxNumberOfMarkers;

- (BOOL)setMaxNumberOfMarkers:(uint32_t)maxNumberOfMarkers error:(NSError **)error;

@end
