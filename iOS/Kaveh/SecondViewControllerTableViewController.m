//
//  SecondViewControllerTableViewController.m
//  Kaveh
//
//  Created by Kaveh Khorram on 1/3/16.
//  Copyright © 2016 Dae Myung. All rights reserved.
//

#import "SecondViewControllerTableViewController.h"

@interface SecondViewControllerTableViewController ()

@property (nonatomic, strong) NSArray *array;

@end

@implementation SecondViewControllerTableViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    NSMutableURLRequest *request = [[NSMutableURLRequest alloc] initWithURL:[NSURL URLWithString:@"https://5c4fded9.ngrok.io/getItemsFromDB"]];
    [[[NSURLSession sharedSession] dataTaskWithRequest:request completionHandler:^(NSData * _Nullable data, NSURLResponse * _Nullable response, NSError * _Nullable error) {
        NSString *yourResponse = [[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding];
        NSLog(@"%@", yourResponse);

        self.array =  [NSJSONSerialization JSONObjectWithData:data options:NSJSONReadingAllowFragments error:nil];

    }] resume];
}

- (void)setArray:(NSArray *)array {
    _array = array;
    if (array != nil) {
        [self.tableView reloadData];
    }
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    if (self.array != nil) {
        return self.array.count;
    }
    return 0;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {

    NSDictionary *item = self.array[indexPath.row];
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:@"cell" forIndexPath:indexPath];
    cell.textLabel.text = item[@"product"];
    cell.detailTextLabel.text = [@"$ " stringByAppendingString:[item[@"price"] stringValue]];
    return cell;
}

@end
