//
//  IDOverlay.h
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

@class IDEngine;

typedef NS_ENUM(NSInteger, IDOverlayType) {
    IDOverlayTypeHTML,
    IDOverlayTypeVideo,
    IDOverlayTypeChroma,
    IDOverlayType3D
};

typedef NS_ENUM(NSInteger, IDOverlayState) {
    IDOverlayStateUnknown,              
    IDOverlayStateLoading,              
    IDOverlayStateHasError,             
    IDOverlayStateReady,                
    IDOverlayStateEndOfMediaReached,    
    IDOverlayStateDestroyed,            
    IDOverlayStateDownloading,
};

@interface IDOverlay : NSObject

@property (nonatomic, strong) NSURL *URL;
@property (nonatomic, strong) UIColor *transparent;
@property (nonatomic, readwrite) IDOverlayType type;
@property (nonatomic, readonly) IDOverlayState state;
@property (nonatomic, readwrite) BOOL billboard;
@property (nonatomic, readwrite) float threshold;

@end
