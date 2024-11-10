#include "pch.h"
#include <iostream>
#include "Iddk2000Apis.h"

#define DEVICE_INFO_PRODUCT_ID	        ""
#define DEVICE_INFO_PRODUCT_NAME	    ""
#define DEVICE_INFO_DEVICE_TYPE_ID	    ""
#define DEVICE_INFO_SERIAL_NUMBER	    ""
#define DEVICE_INFO_PROPERTY_FLAG	    ""
#define DEVICE_INFO_KERNEL_VERSION	    ""
#define DEVICE_INFO_KERNEL_REVISION	    ""
#define DEVICE_INFO_DEVICE_FEATURES	    ""


TEST(IddkGetDeviceInfoTest, ValidDeviceInfoRetrieval) {
    printf("Test: UN_06_001.\n");
    
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

    // get device infomation
    IddkDeviceInfo deviceInfo;
    IddkResult result = Iddk_GetDeviceInfo(deviceHandle, &deviceInfo);


    EXPECT_EQ(result, IDDK_OK);
    EXPECT_EQ(deviceInfo.productID, DEVICE_INFO_PRODUCT_ID);
    EXPECT_EQ(deviceInfo.productName, DEVICE_INFO_PRODUCT_NAME);
    //EXPECT_EQ(deviceInfo.deviceTypeID, DEVICE_INFO_DEVICE_TYPE_ID);
    EXPECT_EQ(deviceInfo.serialNumber, DEVICE_INFO_SERIAL_NUMBER);
    EXPECT_EQ(deviceInfo.propertyFlag, DEVICE_INFO_PROPERTY_FLAG);
    EXPECT_EQ(deviceInfo.kernelVersion, DEVICE_INFO_KERNEL_VERSION);
    EXPECT_EQ(deviceInfo.kernelRevision, DEVICE_INFO_KERNEL_REVISION);
    EXPECT_EQ(deviceInfo.deviceFeatures, DEVICE_INFO_DEVICE_FEATURES);
}

TEST(IddkGetDeviceInfoTest, NullHandle) {
    printf("Test: UN_06_002.\n");
    IddkDeviceInfo deviceInfo;
    IddkResult result = Iddk_GetDeviceInfo(nullptr, &deviceInfo);

    EXPECT_EQ(result, IDDK_INVALID_PARAMETER);
}

TEST(IddkGetDeviceInfoTest, NullDeviceInfoPointer) {
    printf("Test: UN_06_003.\n");

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

    //get device infomation
    IddkResult result = Iddk_GetDeviceInfo(deviceHandle, nullptr);

    EXPECT_EQ(result, IDDK_INVALID_PARAMETER);
}

TEST(IddkGetDeviceInfoTest, InvalidHandle) {
    printf("Test: UN_06_003.\n");

    HIRICAMM invalidHandle = (HIRICAMM)"InvalidDevice";
    IddkDeviceInfo deviceInfo;
    IddkResult result = Iddk_GetDeviceInfo(invalidHandle, &deviceInfo);

    EXPECT_EQ(result, IDDK_INVALID_HANDLE);
}