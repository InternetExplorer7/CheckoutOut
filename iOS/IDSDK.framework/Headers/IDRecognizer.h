//
//  IDRecognizer.h
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

#import <Foundation/Foundation.h>

@class IDRecognitionResult;

/**
 *  IDRecognizerType enum.
 */
typedef NS_ENUM(NSInteger, IDRecognizerType){
	/**
	 *  Image recognizer. Source for recogniton can be either IDCamera or UIImage.
	 */
	IDRecognizerTypeImage,
	
	/**
	 *  Barcode recognizer. Source for recogniton can be either IDCamera or text (UPC code).
	 */
	IDRecognizerTypeBarcode
};

/**
 *  The IDRecognizerDelegate protocol defines methods that can be optionally implemented to be nofitied about recognition or error events.
 */
@protocol IDRecognizerDelegate <NSObject>

/**
 *  Recognizer produced result.
 *
 *  @param recognizer	The recognizer object that produced result.
 *  @param result		The result produced.
 */

- (void)recognizer:(id)recognizer didRecognize:(IDRecognitionResult*)result;

/**
 *  Sent if an error occured when starting the process of recognition or during recognition.
 *
 *  @param recognizer The recognition process where error occured.
 *  @param error       Error that occured.
 */

- (void)recognizer:(id)recognizer didFailWithError:(NSError*)error;

@end

/**
 *  Provides control over the process of recognition.
 *  Set the delegate property to be notified about recognition events.
 */
@interface IDRecognizer : NSObject

/**
 *  Recognizer type.
 */
@property (nonatomic, readonly) IDRecognizerType type;

/**
 *  Set the delegate property to be notified about progress of recognition.
 */
@property (nonatomic, weak) id<IDRecognizerDelegate> delegate;

/**
 *  Start the recognition.
 */
- (void)start;

/**
 *  Cancel the recognition.
 */
- (void)cancel;

@end

/**
 *  Provides control over the process of recognition.
 *  Set the delegate property to be notified about progress of recognition.
 */

@interface IDContinuousRecognizer : NSObject

/**
 *  Recognizer type.
 */
@property (nonatomic, readonly) IDRecognizerType type;

/**
 *  Set the delegate property to be notified about progress of recognition.
 */
@property (nonatomic, weak) id<IDRecognizerDelegate>delegate;

/**
 *  Start the recognition process.
 */
- (void)start;

/**
 *  Stop the recognition process.
 */
- (void)stop;

@end
