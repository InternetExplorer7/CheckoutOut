//
//  IDRecognitionSource.h
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

@class IDCamera;

/** IDRecognitionSource is the sensor data source used for recognition.
*/
@interface IDRecognitionSource : NSObject

/** Recognition data source = text.
@param text Barcode text string to use as search query.
*/
- (instancetype)initWithText:(NSString *)text;

/** Recognition data source = camera; visual image/object recognition.
@param camera The IDCamera object to use for visual recognition.
*/
- (instancetype)initWithCamera:(IDCamera *)camera;

/** Use data from a URL as the recognition data source.
@param URL The SDK will retrieve the content from the NSURL and use that as the recognition query data.
*/
- (instancetype)initWithURL:(NSURL *)URL;

/** Recognition data source
@param stream The SDK will retrieve data from the specified NSStream and use that as the recognition query data.
*/
- (instancetype)initWithStream:(NSStream *)stream;

/** Recognition data source = image; image recognition based on a single query image.
@param image Reference to a UIImage to use as the recognition source.
*/
- (instancetype)initWithImage:(UIImage*)image;

@end