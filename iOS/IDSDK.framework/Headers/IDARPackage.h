//
//  IDARPackage.h
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

@class IDOverlay, IDMarker;

/** The AR Package contains the items needed for the SDK to render an AR experience, specifically:

- Markers (2D or 3D)
- URIs pointing to the overlays for each marker
- A JSON file listing the markers, marker types, and overlay URIs

The AR Package is initialized using the above data, loaded from a Nant File Package. The Nant File Package is created via the Developer Portal or API. It has the .nfp file extension, is a zip file, and can be expanded by replacing the .nfp extension with .zip. 

*/

@interface IDARPackage : NSObject

/**
 *  Create an AR Package 
 *
 *  @param url URL of the Nant File Package (.nfp file). Currently only URLs for local paths, on the device, are supported.
 *
 *  @return Instance of IDARPackage.
 */
- (instancetype)initWithURL:(NSURL *)url;

- (void)addMarker:(IDMarker *)marker overlay:(IDOverlay *)overlay;

@end
