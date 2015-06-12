/****************************************************************************
 
 Copyright (c) 2014-2015 Chukong Technologies
 
 ****************************************************************************/

#pragma once

#import "InterfaceAds.h"
#import "AdsAdColony.h"
#import <Foundation/Foundation.h>

#define APP_ID @"app_id"
#define ZONE_IDS @"zone_ids"
#define AD_ID @"zone_id"
#define IS_REWARD @"is_reward"
#define SHOW_PRE_POPUP @"show_pre_popup"
#define SHOW_POST_POPUP @"show_post_popup"

@interface AdsAdColony : NSObject <InterfaceAds, AdColonyDelegate, AdColonyAdDelegate>
{

}

- (void) init: (NSDictionary*) config;
- (void) showAds: (NSDictionary*) config;
- (void) hideAds: (NSDictionary*) config;
- (void) setDebug: (BOOL) debug;
- (NSString*) getSDKVersion;
- (NSString*) getPluginVersion;

@end
