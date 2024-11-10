#include "pch.h"
#include <iostream>
#include "Iddk2000Apis.h"

TEST(IddkOpenDeviceTest, ValidDeviceOpen) {
    printf("Test: UN_04_001.\n");

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
}

TEST(IddkOpenDeviceTest, InvalidParameter_NullDesc) {
    HIRICAMM deviceHandle;
    IddkResult result = Iddk_OpenDevice(nullptr, &deviceHandle);

    printf("Test: UN_04_002.\n");
    EXPECT_EQ(result, IDDK_INVALID_PARAMETER);
    EXPECT_EQ(deviceHandle, nullptr);
}

TEST(IddkOpenDeviceTest, InvalidParameter_EmptyDesc) {
    HIRICAMM deviceHandle;
    IddkResult result = Iddk_OpenDevice("", &deviceHandle);

    printf("Test: UN_04_003.\n");
    EXPECT_EQ(result, IDDK_INVALID_PARAMETER);
    EXPECT_EQ(deviceHandle, nullptr);
}

TEST(IddkOpenDeviceTest, NullHandle) {
    printf("Test: UN_04_004.\n");
    //scan device
    int nDeviceCnt = 0;
    const char** ppDeviceDescs = nullptr;
    IddkResult scanDeviceResult = Iddk_ScanDevices(&ppDeviceDescs, &nDeviceCnt);
    EXPECT_EQ(scanDeviceResult, IDDK_OK);
    EXPECT_NE(nDeviceCnt, 0);
    EXPECT_NE(ppDeviceDescs, nullptr);

    //open device
    IddkResult openDeviceResult = Iddk_OpenDevice(ppDeviceDescs[0], nullptr);
    EXPECT_EQ(openDeviceResult, IDDK_INVALID_PARAMETER);
}

TEST(IddkOpenDeviceTest, DeviceAlreadyOpen) {
    printf("Test: UN_04_005.\n");

    //scan device
    int nDeviceCnt = 0;
    const char** ppDeviceDescs = nullptr;
    IddkResult scanDeviceResult = Iddk_ScanDevices(&ppDeviceDescs, &nDeviceCnt);
    EXPECT_EQ(scanDeviceResult, IDDK_OK);
    EXPECT_NE(nDeviceCnt, 0);
    EXPECT_NE(ppDeviceDescs, nullptr);

    //first open device
    HIRICAMM deviceHandle1, deviceHandle2;
    IddkResult firstOpenDeviceResult = Iddk_OpenDevice(ppDeviceDescs[0], &deviceHandle1);
    EXPECT_EQ(firstOpenDeviceResult, IDDK_OK);
    EXPECT_NE(deviceHandle1, nullptr);

    //second open device
    IddkResult secondOpenDeviceResult = Iddk_OpenDevice(ppDeviceDescs[0], &deviceHandle2);
    EXPECT_EQ(secondOpenDeviceResult, IDDK_DEVICE_ALREADY_OPEN);
    EXPECT_NE(deviceHandle2, nullptr);
    EXPECT_EQ(secondOpenDeviceResult, IDDK_DEVICE_ALREADY_OPEN);
    EXPECT_EQ(deviceHandle1, deviceHandle2);
}


TEST(IddkOpenDeviceTest, DeviceNotFound) {
    HIRICAMM deviceHandle;
    IddkResult result = Iddk_OpenDevice("NonExistentDevice", &deviceHandle);

    printf("Test: UN_04_006.\n");
    EXPECT_EQ(result, IDDK_DEVICE_NOT_FOUND);
    EXPECT_EQ(deviceHandle, nullptr);
}