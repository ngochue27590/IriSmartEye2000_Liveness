#include "pch.h"
#include <iostream>
#include "Iddk2000Apis.h"

TEST(IddkDeinitCameraTest, ValidDeinitialization) {
    printf("Test: UN_08_001.\n");

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
    IddkResult initCameraResult = Iddk_InitCamera(deviceHandle, &nImageWidth, &nImageHeight);
    EXPECT_EQ(initCameraResult, IDDK_OK);
    
    //deinit camera
    IddkResult deinitCameraResult = Iddk_DeinitCamera(deviceHandle);

    EXPECT_EQ(deinitCameraResult, IDDK_OK);
}

TEST(IddkDeinitCameraTest, NullHandle) {
    printf("Test: UN_08_002.\n");
    IddkResult result = Iddk_DeinitCamera(nullptr);
    EXPECT_EQ(result, IDDK_INVALID_PARAMETER);
}

TEST(IddkDeinitCameraTest, InvalidHandle) {
    printf("Test: UN_08_003.\n");
    HIRICAMM invalidHandle = (HIRICAMM)"InvalidDevice";
    IddkResult result = Iddk_DeinitCamera(invalidHandle);
    EXPECT_EQ(result, IDDK_INVALID_PARAMETER);
}

TEST(IddkDeinitCameraTest, NotInitializedDevice) {
    printf("Test: UN_08_004.\n");

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

    //deinit camera
    IddkResult result = Iddk_DeinitCamera(deviceHandle);
    EXPECT_EQ(result, IDDK_SE_NOT_INIT);
}