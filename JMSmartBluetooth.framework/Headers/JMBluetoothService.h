//
//  JMBluetoothService.h
//  JMSmartBluetooth
//
//  Created by jimi01 on 2020/3/26.
//  Copyright © 2020 jimi01. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>
NS_ASSUME_NONNULL_BEGIN

@interface JMBluetoothService : NSObject
@property(nonatomic) CBPeripheral *peripheral;
@property(nonatomic) CBService *service;
@property(nonatomic) NSString  *uuid;
@property(nonatomic, assign) BOOL  isPrimary;

@end

NS_ASSUME_NONNULL_END
