//
//  JMDevice.h
//  JMSmartBluetooth
//
//  Created by jimi01 on 2020/3/25.
//  Copyright © 2020 jimi01. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>
NS_ASSUME_NONNULL_BEGIN

@interface JMDevice : NSObject
@property(nonatomic) NSString  *name;
@property(nonatomic) NSString  *deviceId;
@property(nonatomic) NSString  *RSSI;
@property(nonatomic) NSString  *advertisData;
@property(nonatomic) NSArray<NSString *>  *advertisServiceUUIDs;
@property(nonatomic) NSString  *localName;
@property(nonatomic) NSData  *serviceData;
@property(nonatomic) CBPeripheral *peripheral;

@end

NS_ASSUME_NONNULL_END
