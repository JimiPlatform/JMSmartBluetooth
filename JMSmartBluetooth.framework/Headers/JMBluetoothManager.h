//
//  JMBluetoothManager.h
//  JMSmartBluetooth
//
//  Created by jimi01 on 2020/3/25.
//  Copyright © 2020 jimi01. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import "JMDevice.h"
#import "JMBluetoothService.h"
#import "JMBluetoothCharacteristics.h"
NS_ASSUME_NONNULL_BEGIN

//服务回调
typedef void(^JMGetServiceCallback)(BOOL isSuccess,NSArray<JMBluetoothService *> * _Nullable services);

//特征值回调
typedef void(^JMGetCharacteristicsCallback)(BOOL isSuccess,NSArray<JMBluetoothCharacteristics *> * _Nullable characteristics);

//写入数据回调
typedef void(^JMWriteBLEValueCallback)(BOOL isSuccess);

typedef enum : NSUInteger {
    
    JMBluetoothStateUnknown = 0,//未知的,
    
    JMBluetoothStateResetting,//重置中,
    
    JMBluetoothStateUnsupported,//不支持蓝牙,
    
    JMBluetoothStateUnauthorized,//未验证
    
    JMBluetoothStatePoweredOff,//未打开蓝牙
    
    JMBluetoothStatePoweredOn,//蓝牙当前可用
    
} JMBluetoothState;

@protocol JMBluetoothDelegate <NSObject>

/// 当前蓝牙状态
/// @param state 状态枚举
- (void)jm_bluetoothWithState:(JMBluetoothState)state;

/// 周边搜索的设备
/// @param device 已搜索到的设备
- (void)jm_scanDevice:(JMDevice *)device;

/// 连接成功
- (void)jm_didConnectPeripheral:(CBPeripheral *)peripheral;

//连接失败
- (void)jm_didFailToConnectDeviceWithError:(NSError *)error;

//断开连接
- (void)jm_didDisConnectDeviceWithError:(NSError *)error;


/// 蓝牙设备返回数据
/// @param value 返回二进制数据
/// @param characteristic 读取的特征值
- (void)jm_readCharacteristicValue:(NSData *)value characteristic:(JMBluetoothCharacteristics *)characteristic;

@end

@interface JMBluetoothManager : NSObject

+ (instancetype)shared;

/// 初始化相应蓝牙组件
/// @param delegate JMBluetoothDelegate代理
- (void)initializeBluetoothWithDelegate:(nonnull id<JMBluetoothDelegate> )delegate;

/// 搜索周边蓝牙设备
/// @param services 搜索指定service的蓝牙设备
- (void)scanPeripheralsWithServices:(nullable NSArray<NSString *>  *)services;

/// 停止搜索周边蓝牙设备
- (void)stopScanPeripherals;

/// 连接蓝牙设备
/// @param device 设备
- (void)connectPeripheralsWithDeviceId:(nonnull JMDevice *)device;

/// 断开连接
/// @param device 设备
- (void)cancelPeripheralConnection:(nonnull JMDevice *)device;

/// 获取当前已连接的设备
/// @param serviceIds 服务id
- (nullable NSArray<CBPeripheral *> *)getConnectedDevicesWithServiceIds:(nullable NSArray<NSString *> *)serviceIds;

/// 发现设备服务
/// @param device 设备
/// @param serviceIds 服务id
/// @param completionHandler 完成回调
- (void)getBLEDeviceServicesWithDevice:(nonnull JMDevice *)device
                            serviceIds:(nullable NSArray<NSString *> *)serviceIds
                     completionHandler:(nullable JMGetServiceCallback)completionHandler;

/// 获取特征值
/// @param service 服务模型
/// @param completionHandler 完成回调
- (void)getBLEDeviceCharacteristicsWithService:(nonnull JMBluetoothService *)service
                             completionHandler:(nullable JMGetCharacteristicsCallback)completionHandler;

/// 蓝牙设备写入数据
/// @param data 带写入的二进制数据
/// @param characteristic 写入指定特征值
/// @param completionHandler 完成回调
- (void)writeBLECharacteristicValue:(NSData *)data
                     characteristic:(nonnull JMBluetoothCharacteristics *)characteristic
                  completionHandler:(nullable JMWriteBLEValueCallback)completionHandler;

/// 订阅与取消订阅蓝牙设备特征值
/// @param characteristic 指定特征值
/// @param isNotify 是否订阅
- (void)notifyBLECharacteristic:(nonnull JMBluetoothCharacteristics *)characteristic isNotify:(BOOL)isNotify;


/// 读取指定特征值
/// @param characteristic 指定特征值
- (void)readBLECharacteristic:(nonnull JMBluetoothCharacteristics *)characteristic;

/// 清理蓝牙
- (void)clearBluetooth;
@end

NS_ASSUME_NONNULL_END
