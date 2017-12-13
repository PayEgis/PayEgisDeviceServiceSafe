//
//  PayegisDID.h
//  PayegisDID
//
//  Created by ivan on 16/4/22.
//  Copyright © 2016年 PG. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "WebKit/WebKit.h"
#import "PayegisConstant.h"
typedef void (^PayegisSecurityInitCompletionBlock)(NSError *error);
typedef void (^PayegisSecurityUninitCompletionBlock)(NSError *error);


@interface PayegisDID : NSObject

/**
 SDK本地服务初始化方法
 @param appid APPID
 @param appKey APPKEY
 @param hostUrl 本地服务地址
 @param completionBlock 服务器响应的回调
 */
+(void)initWithAppId:(NSString *)appId AppKey:(NSString *)appKey HostUrl:(NSString *)hostUrl completionBlock:(PayegisSecurityInitCompletionBlock)completionBlock;

/**
 SDK云服务初始化方法
 @param appid APPID
 @param appKey APPKEY
 @param completionBlock 服务器响应的回调
 */
+(void)initWithAppId:(NSString *)appId AppKey:(NSString *)appKey completionBlock:(PayegisSecurityInitCompletionBlock)completionBlock;

/**
 SDK设备指纹业务埋点方法
 @param sessionId 关联ID，由用户构造
 @param scence 业务场景
 */
+(void)serviceWithSessionId:(NSString *)sessionId Scence:(PayEgisScence)scence completionBlock:(PayegisSecurityInitCompletionBlock)completionBlock;

/**
 设置SDK上下文环境
 */
+ (void)setContext:(NSDictionary *)context;

/**
 获取SDK上下文
 */
+ (NSDictionary *)context;

/**
 SDK初始化
 @param context:SDK上下文，包括EGISSecurityContextHostURL，EGISSecurityContextLisenceKey，EGISSecurityContextPartnerCodeKey，EGISSecurityContextSDKTestMode
 completionBlock:初始化完成后的异步回调
 contenxt为nil时，不改变原有的值
 */
+ (void)init:(NSDictionary *)context completionBlock:(PayegisSecurityInitCompletionBlock)completionBlock;
/**
 webview关联SDK
 @param context:SDK上下文，设置appid\appkey即可
 webview需要设置的wbview实例
 */
+ (void)setWebView:(NSDictionary *)context view:(UIView*)webview;

/**
 SDK去初始化
 不再需要使用SDK时调用
 */
+ (void)uninit:(PayegisSecurityUninitCompletionBlock)completionBlock;

+ (void)setIsBgTry:(BOOL)bgTry;
+ (BOOL)getBgTry;

@end