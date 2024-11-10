#include "pch.h"
#include <iostream>
#include "Iddk2000Apis.h"

#define DEFAULT_IMAGE_WIDTH	    640 
#define DEFAULT_IMAGE_HEIGHT	480 


TEST(IddkInitCameraTest, ValidInitialization) {
    printf("Test: UN_07_001.\n");

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

    //init camera
    int nImageWidth = 0, nImageHeight = 0;
    IddkResult result = Iddk_InitCamera(deviceHandle, &nImageWidth, &nImageHeight);

    EXPECT_EQ(result, IDDK_OK);
    EXPECT_EQ(nImageWidth, DEFAULT_IMAGE_WIDTH);
    EXPECT_EQ(nImageHeight, DEFAULT_IMAGE_HEIGHT);
}

TEST(IddkInitCameraTest, NullHandle) {
    printf("Test: UN_07_002.\n");

    int nImageWidth = 0, nImageHeight = 0;
    IddkResult result = Iddk_InitCamera(nullptr, &nImageWidth, &nImageHeight);

    EXPECT_EQ(result, IDDK_INVALID_PARAMETER);
}

TEST(IddkInitCameraTest, InvalidHandle) {
    printf("Test: UN_07_003.\n");

    HIRICAMM invalidHandle = (HIRICAMM)"InvalidDevice";
    int nImageWidth = 0, nImageHeight = 0;
    IddkResult result = Iddk_InitCamera(invalidHandle, &nImageWidth, &nImageHeight);

    EXPECT_EQ(result, IDDK_INVALID_PARAMETER);
}

TEST(IddkInitCameraTest, NullWidthPointer) {
    printf("Test: UN_07_004.\n");

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

    //init camera
    int nImageHeight = 0;
    IddkResult result = Iddk_InitCamera(deviceHandle, nullptr, &nImageHeight);

    EXPECT_EQ(result, IDDK_OK);
    EXPECT_EQ(nImageHeight, DEFAULT_IMAGE_HEIGHT);
}

TEST(IddkInitCameraTest, NullHeightPointer) {
    printf("Test: UN_07_005.\n");

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

    int nImageWidth = 0;
    IddkResult result = Iddk_InitCamera(deviceHandle, &nImageWidth, nullptr);

    EXPECT_EQ(result, IDDK_OK);
    EXPECT_EQ(nImageWidth, DEFAULT_IMAGE_WIDTH);
}

