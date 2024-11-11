#include "pch.h"
#include "Iddk2000Apis.h"

class IddkOpenDeviceTest : public ::testing::Test {
protected:
    HIRICAMM hDevice;

    void SetUp() override {
        hDevice = NULL;
    }

    void TearDown() override {
        if (hDevice != NULL) {
            Iddk_CloseDevice(hDevice);
        }
    }
};

TEST_F(IddkOpenDeviceTest, ValidOpen) {
    const char* deviceName = "USB_DEVICE_NAME";
    IddkResult result = Iddk_OpenDevice(deviceName, &hDevice);

    EXPECT_EQ(result, IDDK_OK);
    EXPECT_NE(hDevice, nullptr); // Check that the handle is not NULL
}

TEST_F(IddkOpenDeviceTest, NullParameters) {
    IddkResult result = Iddk_OpenDevice(NULL, &hDevice);
    EXPECT_EQ(result, IDDK_INVALID_PARAMETER);

    result = Iddk_OpenDevice("COM1", NULL);
    EXPECT_EQ(result, IDDK_INVALID_PARAMETER);
}

TEST_F(IddkOpenDeviceTest, DeviceNotFound) {
    const char* invalidDeviceName = "INVALID_DEVICE_NAME";
    IddkResult result = Iddk_OpenDevice(invalidDeviceName, &hDevice);

    EXPECT_EQ(result, IDDK_DEVICE_NOT_FOUND);
}

TEST_F(IddkOpenDeviceTest, DeviceAlreadyOpen) {
    const char* deviceName = "USB_DEVICE_NAME"; 
    Iddk_OpenDevice(deviceName, &hDevice); // Open the device for the first time
    IddkResult result = Iddk_OpenDevice(deviceName, &hDevice); // Try to turn on the device again
    EXPECT_EQ(result, IDDK_DEVICE_ALREADY_OPEN);
}