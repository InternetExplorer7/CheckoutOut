//
//  ViewController.m
//  atthackathon
//
//  Created by Kaveh Khorram on 1/2/16.
//  Copyright © 2016 Kaveh Khorram. All rights reserved.
//
#import <IDSDK/IDSDK.h>
#import "ViewController.h"

#define CLIENT_KEY       @"P_B1huYTpMXrtNei1NGmMA"
#define CLIENT_SECRECT   @"k2wsVIt8ss3DkidZywN6zg"

@interface ViewController () <IDRecognizerDelegate>

@property (strong, nonatomic) IDEngine *engine;
@property (strong, nonatomic) IBOutlet IDARView *arView;
@property (nonatomic, strong) IBOutlet UIButton *button;
@property (nonatomic, strong) IDContinuousRecognizer *recognizer;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];

    self.button.layer.cornerRadius = 44.0;

    // Initialize the iD engine
    [IDEngine engineInitializedWithKey: CLIENT_KEY
                             andSecret: CLIENT_SECRECT
                            completion: ^(IDEngine *engine, NSError *error)
     {
         self.engine = engine;
         [self startCamera];
     }];
}

- (void)startCamera {
    NSError *error = nil;

    if (![[IDCamera defaultCamera] openForView:self.arView error:&error]) {
        [[[UIAlertView alloc] initWithTitle:@"Error opening camera" message:[NSString stringWithFormat: @"%@", error] delegate:nil cancelButtonTitle:@"OK" otherButtonTitles:nil] show];
    }

    if (![[IDCamera defaultCamera] start:&error]) {
        [[[UIAlertView alloc] initWithTitle:@"Error starting camera" message:[NSString stringWithFormat: @"%@", error] delegate:nil cancelButtonTitle:@"OK" otherButtonTitles:nil] show];
    }
}

- (IBAction)startBarcode:(id)sender {

    if (self.button.selected) {
        self.button.selected = NO;
        [self.recognizer stop];
        self.button.backgroundColor = [UIColor greenColor];
    } else {
        self.button.selected = YES;
        self.button.backgroundColor = [UIColor redColor];
        IDRecognitionSource *source = [[IDRecognitionSource alloc] initWithCamera:[IDCamera defaultCamera]];
        self.recognizer = [self.engine continuousRecognizerWithType: IDRecognizerTypeBarcode
                                                         fromSource: source
                                            includeDetailsInResults: YES
                                                           delegate: self
                                                   startImmediately: YES];
    }
}

- (void)recognizer:(id)recognizer didRecognize:(IDRecognitionResult *)result {
    UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"New item" message:@"Added!" delegate:self cancelButtonTitle:@"Ok" otherButtonTitles:nil, nil];
    [alert show];
    NSLog(@"%@", [result.included.firstObject description]);
    NSString *description = [result.included.firstObject description];

    NSMutableURLRequest *request = [[NSMutableURLRequest alloc] initWithURL:[NSURL URLWithString:@"https://5c4fded9.ngrok.io/addItemToDB"]];
    [request setHTTPBody:[description dataUsingEncoding:NSUTF8StringEncoding]];
    [request setHTTPMethod:@"POST"];
    [[[NSURLSession sharedSession] dataTaskWithRequest:request completionHandler:^(NSData * _Nullable data, NSURLResponse * _Nullable response, NSError * _Nullable error) {
        NSString *yourResponse = [[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding];
        NSLog(@"%@", yourResponse);
    }] resume];
}


- (void)recognizer:(id)recognizer didFailWithError:(NSError *)error {
    NSLog(@"Fail recognition");
}

@end