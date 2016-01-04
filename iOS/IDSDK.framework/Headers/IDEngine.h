//
//  IDEngine.h
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

typedef enum IDRecognizerType : NSInteger IDRecognizerType;
@class IDRecognizer, IDContinuousRecognizer, IDRecognitionSource;
@protocol IDRecognizerDelegate;

/** IDEngine is the core of the ID SDK. First create an IDEngine instance with your account credentials (key and secret). Then create an iDRecognizer to recognize things.

*/
@interface IDEngine : NSObject

/**
 *  Returns the IDSDK version
 */
+ (NSString *)SDKVersion;

/**
 * Creates an initialized IDEngine instance. Use this method before attempting to create an IDRecognizer.
 *
 *  @param key        iD Platform account key
 *  @param secret     iD Platform ccount secret
 *  @param completion block providing initialized IDEngine or nil if initialization failed and NSError if error occured or nil if successful.
 */
+ (void)engineInitializedWithKey:(NSString *)key andSecret:(NSString *)secret completion:(void (^)(IDEngine * engine, NSError * error))completion;

/**
 *  Create an IDRecognizer instance using IDRecognitionSource, to perform a single snapshot recognition, and optionally start the recognition process immediately.
 *
 *  @param recognizerType   IDRecognizerType
 *  @param source           IDRecognitionSource
 *  @param includeDetails   If YES, then include all metadata details in the recognition response. If NO, then additional metadata fetches will be needed to get these data.
 *  @param delegate         Receives recognition result and possible recognition error.
 *  @param startImmediately If YES, then start immediately after initialization, othewise a -[ ... start] will need to be called to start the recognition.
 *
 *  @return Instance of IDRecognizer
 */
- (IDRecognizer *)recognizerWithType:(IDRecognizerType)recognizerType
						  fromSource:(IDRecognitionSource *)source
			 includeDetailsInResults:(BOOL)includeDetails
							delegate:(id<IDRecognizerDelegate>)delegate
					startImmediately:(BOOL)startImmediately;

/**
 *  Create a IDContinuousRecognizer instance for continuous recognition from IDRecognitionSource and optionally start the recognition process immediately.
 *
 *  @param recognizerType   IDRecognizerType
 *  @param source           IDRecognitionSource
 *  @param includeDetails   If YES, then include all metadata details in the recognition response. If NO, then additional metadata fetches will be needed to get these data.
 *  @param delegate         Receives recognition results and possible recognition errors.
 *  @param startImmediately If YES, then start immediately after initialization, othewise a -[ ... start] will need to be called to start the recognition.
 *
 *  @return Instance of IDContinuousRecognizer
 */
- (IDContinuousRecognizer *)continuousRecognizerWithType:(IDRecognizerType)recognizerType
											  fromSource:(IDRecognitionSource *)source
								 includeDetailsInResults:(BOOL)includeDetails
												delegate:(id<IDRecognizerDelegate>)delegate
										startImmediately:(BOOL)startImmediately;
@end
