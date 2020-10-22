//
//  JMDFUManager.h
//  JMSmartBluetooth
//
//  Created by jimi01 on 2020/3/27.
//  Copyright © 2020 jimi01. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>

NS_ASSUME_NONNULL_BEGIN

typedef enum : NSUInteger {
    JMDFUStateConnecting,//连接中
    JMDFUStateStarting,//开始
    JMDFUStateEnablingDfuMode,//启用dfuMode
    JMDFUStateUploading,//上传中
    JMDFUStateValidating,//验证中
    JMDFUStateDisconnecting,//断开连接
    JMDFUStateCompleted,//完成
    JMDFUStateAborted,//失败
} JMDFUState;

@protocol JMDFUDelegate <NSObject>

/// 返回日志
- (void)jm_logMessage:(NSString * _Nonnull)message;


/// 返回进度
- (void)jm_progressWithPart:(NSInteger)part outOf:(NSInteger)totalParts to:(NSInteger)progress currentSpeedBytesPerSecond:(double)currentSpeedBytesPerSecond avgSpeedBytesPerSecond:(double)avgSpeedBytesPerSecond;

/// 返回DFU升级状态
- (void)jm_dfuStateDidChangeTo:(JMDFUState)state;

/// 返回z错误日志
- (void)jm_DFUErrorMessage:(NSString * _Nonnull)message;

@end
@interface JMDFUManager : NSObject

/// DFU升级
/// @param url 文件地址
/// @param peripheral 蓝牙设备
/// @param delegate 代理对象
- (void)performDFUWithURL:(NSURL *)url peripheral:(CBPeripheral *)peripheral delegate:(nonnull id<JMDFUDelegate> )delegate;

/// 暂停上传
- (void)pause;

/// 恢复上传
- (void)resume;

/// 终止上传
- (BOOL)abort;

/// 再次启动上传
- (void)restart;

@end

NS_ASSUME_NONNULL_END
