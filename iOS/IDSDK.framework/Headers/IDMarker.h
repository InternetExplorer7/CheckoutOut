//
//  IDMarker.h
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

@interface IDMarker : NSObject

@property (nonatomic, strong) NSURL *URL;
@property (nonatomic, readonly) NSString *identifier;

@end
