#include "pch.h"
#include "Iddk2000Apis.h"

class IddkScanDevicesTest : public ::testing::Test {
protected:
    const char** ppDeviceDescs;
    int nDeviceCnt;

    void SetUp() override {
        ppDeviceDescs = nullptr;
        nDeviceCnt = 0;
    }

    void TearDown() override {
    }
};

TEST_F(IddkScanDevicesTest, ValidScan) {
    IddkResult result = Iddk_ScanDevices(&ppDeviceDescs, &nDeviceCnt);

    EXPECT_EQ(result, IDDK_OK);
    EXPECT_GT(nDeviceCnt, 0); // Check that at least 1 device is detected

    // Print out the device name
    for (int i = 0; i < nDeviceCnt; i++) {
        printf("Device %d: %s\n", i + 1, ppDeviceDescs[i]);
    }
}

TEST_F(IddkScanDevicesTest, NullParameters) {
    IddkResult result = Iddk_ScanDevices(NULL, &nDeviceCnt);
    EXPECT_EQ(result, IDDK_INVALID_PARAMETER);

    result = Iddk_ScanDevices(&ppDeviceDescs, NULL);
    EXPECT_EQ(result, IDDK_INVALID_PARAMETER);
}

TEST_F(IddkScanDevicesTest, NoDevicesFound) {
    // Assume no devices are plugged in
    IddkResult result = Iddk_ScanDevices(&ppDeviceDescs, &nDeviceCnt);
    EXPECT_EQ(result, IDDK_DEVICE_NOT_FOUND);
}