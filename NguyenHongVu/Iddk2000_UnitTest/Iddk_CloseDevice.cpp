#include "pch.h"
#include "Iddk2000Apis.h"

//class IddkCloseDeviceTest : public ::testing::Test {
//protected:
//    HIRICAMM hDevice;
//
//    void SetUp() override {
//        hDevice = /* Assume this is a valid handle after opening */;
//    }
//
//    void TearDown() override {
//        if (hDevice != NULL) {
//            Iddk_CloseDevice(hDevice);
//        }
//    }
//};
//
//TEST_F(IddkCloseDeviceTest, ValidClose) {
//    IddkResult result = Iddk_CloseDevice(hDevice);
//    EXPECT_EQ(result, IDDK_OK);
//
//    hDevice = NULL; // Reset handle to NULL
//}
//
//TEST_F(IddkCloseDeviceTest, InvalidHandle) {
//    HIRICAMM invalidHandle = NULL; // Invalid handle
//    IddkResult result = Iddk_CloseDevice(invalidHandle);
//    EXPECT_EQ(result, IDDK_INVALID_PARAMETER);
//}
//
//TEST_F(IddkCloseDeviceTest, AlreadyClosed) {
//    Iddk_CloseDevice(hDevice); // lose the device for the first time
//    IddkResult result = Iddk_CloseDevice(hDevice); // Try to close again
//    EXPECT_EQ(result, IDDK_INVALID_HANDLE); 
//}