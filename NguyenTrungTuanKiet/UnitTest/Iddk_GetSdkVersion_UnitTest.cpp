#include "pch.h"
#include <iostream>
#include "Iddk2000Apis.h"

#define SDK_VERSION_MAJOR	3
#define SDK_VERSION_MINOR	6
#define SDK_VERSION_BUILD	9


TEST(IddkGetSdkVersionTest, VersionFormat) {
    unsigned int sdkVersion;
    sdkVersion = Iddk_GetSdkVersion();
    unsigned char majorVersion = (sdkVersion & 0xFF000000) >> 24;
    unsigned char minorVersion = (sdkVersion & 0x00FF0000) >> 16;
    unsigned char buildNumber = (sdkVersion & 0x000000FF);

    printf("Test: UN_01_001.\n");
    EXPECT_EQ(SDK_VERSION_MAJOR, majorVersion);
    EXPECT_EQ(SDK_VERSION_MINOR, minorVersion);
    EXPECT_EQ(SDK_VERSION_BUILD, buildNumber);
    EXPECT_EQ(Iddk_GetSdkVersion(), 50724873);
}