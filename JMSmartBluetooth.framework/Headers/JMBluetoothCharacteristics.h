//
//  JMBluetoothCharacteristics.h
//  JMSmartBluetooth
//
//  Created by jimi01 on 2020/3/27.
//  Copyright © 2020 jimi01. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>
NS_ASSUME_NONNULL_BEGIN

@interface JMBluetoothCharacteristics : NSObject
@property(nonatomic) CBPeripheral *peripheral;
@property(nonatomic) CBService *service;
@property(nonatomic) CBCharacteristic *characteristic;
@property(nonatomic) NSString *uuid;
@property(nonatomic, assign) BOOL read;
@property(nonatomic, assign) BOOL write;
@property(nonatomic, assign) BOOL notify;
@property(nonatomic, assign) BOOL indicate;
@end

NS_ASSUME_NONNULL_END
