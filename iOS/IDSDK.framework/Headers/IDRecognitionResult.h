//
//  IDResponse.h
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

@class IDARPackage, IDEntity;

/** IDEntityDelegate protocol must be used to receive creative content from IDEntity.
 * The IDEntity [ ... fetchCreative: ] method is called to start the process of fetching a creative. This class includes callback methods that fire in response to receiving different creative content types based on fetching a creative. You must supply your own code to handle each case.
 */
@protocol IDEntityDelegate <NSObject>
@optional
/** This method is called if fetchCreative returns an IDARPackage. Provide your code inside this method to handle the AR package.
* @param entity Reference to the IDEntity related to the received creative content.
* @param package Reference to the IDARPackage containing the AR content.
*/
- (void)entity:(IDEntity*)entity didReceiveARPackage:(IDARPackage *)package;

/** This method is called if fetchCreative returns an NSURL. Provide your code inside this method to handle the URL. 
* @param entity Reference to the IDEntity related to the received creative content.
* @param url Reference to the NSURL containing the URL.
 */
- (void)entity:(IDEntity*)entity didReceiveHTMLURL:(NSURL *)url;

/** This method is called if fetchCreative returns a UIImage. Provide your code inside this method to handle the image.
* @param entity Reference to the IDEntity related to the received creative content.
* @param image Reference to the UIImage containing the image.
 */
- (void)entity:(IDEntity*)entity didReceiveImage:(UIImage *)image;

/** This method is called if fetchCreative returns a video URL. Provide your code inside this method to handle the video URL.
* @param entity Reference to the IDEntity related to the received creative content. 
* @param url Reference to the NSURL containing the video URL.
 */
- (void)entity:(IDEntity*)entity didReceiveVideoURL:(NSURL *)url;

/** This method is called if fetchCreative returns an NSError. Provide your code inside this method to handle the error.
* @param entity Reference to the IDEntity related to the received creative content.
* @param error Reference to the NSError containing the error.
 */
- (void)entity:(IDEntity*)entity didFailWithError:(NSError *)error;

- (void)entity:(IDEntity*)entity didReceiveResponse:(NSURLResponse *)response completionHandler:(void (^)(NSURLSessionResponseDisposition disposition))completionHandler;

@end

/** The IDMeta class contains the number of items in an object.
*/
@interface IDMeta : NSObject

/** Number of items in retrieved a retreived object, e.g. recognitions or creatives.
*/
@property (nonatomic, readonly) NSNumber *totalResults;

@end

/** IDBaseModel is the core structure of data returned. This corresponds to the structure of JSON data returned from the API.
*/
@interface IDBaseModel : NSObject

@property (nonatomic, strong) IDMeta *meta;
@property (nonatomic, strong) NSString *identifier;
@property (nonatomic, strong) NSDictionary *links;
@property (nonatomic, strong) NSDictionary *relationships;
@property (nonatomic, strong) NSDictionary *attributes;

@end

/**
* IDEntity class. An Entity represents a real-world object that you want to recognize. Entities typically are things such as consumer products, images, music album covers, etc. Entities can be recognized via images and barcodes. An entity can have multiple images and barcodes associate with it.
*/
@interface IDEntity : IDBaseModel

/** Entity title.
*/
@property (nonatomic, strong) NSString *title;

/** Entity description.
*/
@property (nonatomic, strong) NSString *description;

/** Entity tags.
*/
@property (nonatomic, strong) NSArray *tags;

/** Entity images.
*/
@property (nonatomic, strong) NSArray *images;

/** Gets a creative from the server, given an entity as input.
* @param delegate Object that implements the IDEntityDelegate protocol and that will receive the creative.
* @param mimeType Creative mimeType(s) that you will accept. Acceptable values: text/html,
* application/vnd.nant.ar-package.draft (for Nant AR Packages), video / \*, image / \*, \* / \*
*/
- (void)fetchCreative:(id<IDEntityDelegate>)delegate mimeType:(NSString *)mimeType;

/** Gets a creative from the server, given an entity, and client location (latitude,longitude) as input. Location is used to filter creatives.
* @param delegate Object that implements the IDEntityDelegate protocol and that will receive the creative.
* @param mimeType Creative mimeType(s) that you will accept. Acceptable values: text/html,
* application/vnd.nant.ar-package.draft (for Nant AR Packages), video / \*, image / \*, \* / \*
* @param latitude Decimal degrees, -90.0 to +90.0, positive north of the equator.
* @param longitude Decimal degrees, -180.0 to +180.0, positive eastward from the Prime Meridian.
*/
- (void)fetchCreative:(id<IDEntityDelegate>)delegate mimeType:(NSString *)mimeType latitude:(double)latitude longitude:(double)longitude;

@end

/** Contains the recognition score.
*/
@interface IDRecognition : IDBaseModel

/** Recognition score. 0 - 1, float.
*/
@property (nonatomic, strong) NSNumber *score;

@end

/** Recognition result.
*/
@interface IDRecognitionResult : NSObject

/** Number of recognition results.
*/
@property (nonatomic, strong) IDMeta *meta;
@property (nonatomic, strong) NSDictionary *links;
@property (nonatomic, strong) NSArray *included;

- (id)data;

@end

/**
 *  IDEntitiesResponse contains an array of IDEntity objects.
 */
@interface IDEntitiesResponse : IDRecognitionResult

/**
 *  Array of IDEntity objects.
 */
@property (nonatomic, strong) NSArray *data;

@end

@interface IDEntityResponse : IDRecognitionResult

@property (nonatomic, strong) IDEntity *data;

@end



/**
 *  IDRecognitionResponse contains an array of IDRecognition objects.
 */
@interface IDRecognitionResponse : IDRecognitionResult

/**
 *  Array of IDRecognition objects.
 */
@property (nonatomic, strong) NSArray *data;

@end
