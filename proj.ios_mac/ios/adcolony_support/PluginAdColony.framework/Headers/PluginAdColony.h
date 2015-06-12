/****************************************************************************

 Copyright (c) 2014-2015 Chukong Technologies

 ****************************************************************************/

#ifndef _PLUGIN_ADCOLONY_H_
#define _PLUGIN_ADCOLONY_H_

#include <string>
#include <vector>
#include <map>

namespace sdkbox 
{
    struct AdColonyAdInfo
    {
        bool shown;
        std::string zoneID;
        bool iapEnabled;
        std::string iapProductID;
        int iapQuantity;
        int iapEngagementType;
    };

    class AdColonyListener
    {
    public:
        virtual void onAdColonyChange(const std::string& zoneID, bool available) = 0;
        virtual void onAdColonyReward(const std::string& zoneID, const std::string& currencyName, int amount, bool success) = 0;
        virtual void onAdColonyStarted(const std::string& zoneID) = 0;
        virtual void onAdColonyFinished(const AdColonyAdInfo& info) = 0;
    };

    class PluginAdColony
    {
    public:
        
        /*! \brief init
         *  init the instance.
         *
         *
         */
        static void init();
        
        /** @name Playing Video Ads */
        static void show(const std::string& name);
        static void setListener(AdColonyListener* listener);
        static AdColonyListener* getListener();
        static void removeListener();
        
        static int zoneStatusForZone(const std::string& zoneID);
        
        /** @name Device and User Identifiers */
        static void setCustomID(const std::string& customID);
        static std::string getCustomID();
        static std::string getUniqueDeviceID();
        static std::string getAdvertisingIdentifier();
        static std::string getVendorIdentifier();

        /** @name V4VC Multiple Videos per Reward Info */
        static int getVideosPerReward(const std::string& currencyName);
        static int getVideoCreditBalance(const std::string& currencyName);

        /** @name Options and Other Functionality */
        static void cancelAd();
        static bool videoAdCurrentlyRunning();
        static void turnAllAdsOff();

        /** @name Optional User Metadata */
        static void setUserMetadata(const std::string& metadataType, const std::string& value);
        static void userInterestedIn(const std::string& topic);

        static void notifyIAPComplete(const std::string& transactionID, const std::string& productID, int quantity, float price, const std::string& currencyCode);

        #ifdef OBFUSCATED
        _fde6d02d541f4f1ab57ec133f7e74434
        #endif
    };
}

#endif