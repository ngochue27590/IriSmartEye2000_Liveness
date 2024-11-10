#include "pch.h"
#include <iostream>
#include "Iddk2000Apis.h"

TEST(IddkCloseDeviceTest, ValidCloseDevice) {
    printf("Test: UN_05_001.\n");

    //scan device
    int nDeviceCnt = 0;
    const char** ppDeviceDescs = nullptr;
    IddkResult scanDeviceResult = Iddk_ScanDevices(&ppDeviceDescs, &nDeviceCnt);
    EXPECT_EQ(scanDeviceResult, IDDK_OK);
    EXPECT_NE(nDeviceCnt, 0);
    EXPECT_NE(ppDeviceDescs, nullptr);

    //open device
    HIRICAMM deviceHandle;
    IddkResult openDeviceResult = Iddk_OpenDevice(ppDeviceDescs[0], &deviceHandle);
    EXPECT_EQ(openDeviceResult, IDDK_OK);
    EXPECT_NE(deviceHandle, nullptr);

    //close device
    IddkResult result = Iddk_CloseDevice(deviceHandle);
    EXPECT_EQ(result, IDDK_OK);
}

TEST(IddkCloseDeviceTest, NullHandle) {
    printf("Test: UN_05_002.\n");
    IddkResult result = Iddk_CloseDevice(nullptr);
    EXPECT_EQ(result, IDDK_INVALID_PARAMETER);
}

TEST(IddkCloseDeviceTest, InvalidHandle) {
    printf("Test: UN_05_003.\n");
    HIRICAMM invalidHandle = (HIRICAMM)"InvalidDevice";
    IddkResult result = Iddk_CloseDevice(invalidHandle);

    EXPECT_EQ(result, IDDK_INVALID_HANDLE);
}

TEST(IddkCloseDeviceTest, CloseAlreadyClosedDevice) {
    printf("Test: UN_05_004.\n");

    //scan device
    int nDeviceCnt = 0;
    const char** ppDeviceDescs = nullptr;
    IddkResult scanDeviceResult = Iddk_ScanDevices(&ppDeviceDescs, &nDeviceCnt);
    EXPECT_EQ(scanDeviceResult, IDDK_OK);
    EXPECT_NE(nDeviceCnt, 0);
    EXPECT_NE(ppDeviceDescs, nullptr);

    //open device
    HIRICAMM deviceHandle;
    IddkResult openDeviceResult = Iddk_OpenDevice(ppDeviceDescs[0], &deviceHandle);
    EXPECT_EQ(openDeviceResult, IDDK_OK);
    EXPECT_NE(deviceHandle, nullptr);

    //close device first time
    IddkResult closeDeviceResult1 = Iddk_CloseDevice(deviceHandle);
    EXPECT_EQ(closeDeviceResult1, IDDK_OK);

    // Attempt to close it again
    IddkResult closeDeviceResult2 = Iddk_CloseDevice(deviceHandle);

    EXPECT_EQ(closeDeviceResult2, IDDK_INVALID_HANDLE);
}
