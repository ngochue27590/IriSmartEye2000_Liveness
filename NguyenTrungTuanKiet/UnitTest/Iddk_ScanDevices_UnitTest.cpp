#include "pch.h"
#include <iostream>
#include "Iddk2000Apis.h"

TEST(IddkScanDevicesTest, ValidScanNoDevices) {
    const char** ppDeviceDescs = nullptr;
    int nDeviceCnt = 0;

    IddkResult result = Iddk_ScanDevices(&ppDeviceDescs, &nDeviceCnt);

    printf("Test: UN_03_001.\n");
    EXPECT_EQ(result, IDDK_DEVICE_NOT_FOUND);
    EXPECT_EQ(nDeviceCnt, 0);
    EXPECT_EQ(ppDeviceDescs, nullptr);
}

TEST(IddkScanDevicesTest, NullDeviceDescPointer) {
    int nDeviceCnt = 0;

    IddkResult result = Iddk_ScanDevices(nullptr, &nDeviceCnt);

    printf("Test: UN_03_002.\n");
    EXPECT_EQ(result, IDDK_INVALID_PARAMETER);
    EXPECT_EQ(nDeviceCnt, 0);
}

TEST(IddkScanDevicesTest, NullDeviceCountPointer) {
    const char** ppDeviceDescs = nullptr;

    IddkResult result = Iddk_ScanDevices(&ppDeviceDescs, nullptr);

    printf("Test: UN_03_003.\n");
    EXPECT_EQ(result, IDDK_INVALID_PARAMETER);
}
