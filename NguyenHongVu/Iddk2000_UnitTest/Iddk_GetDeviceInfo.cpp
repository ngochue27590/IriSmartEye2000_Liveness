#include "pch.h"
#include "Iddk2000Apis.h"

//class IddkGetDeviceInfoTest : public ::testing::Test {
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
//TEST_F(IddkGetDeviceInfoTest, ValidGetDeviceInfo) {
//    IddkDeviceInfo deviceInfo;
//    IddkResult result = Iddk_GetDeviceInfo(hDevice, &deviceInfo);
//
//    EXPECT_EQ(result, IDDK_OK);
//    EXPECT_GT(deviceInfo.productID, 0); // Check that productID is positive
//    EXPECT_STRNE(deviceInfo.productName, ""); // Check that productName is not empty
//}
//
//TEST_F(IddkGetDeviceInfoTest, InvalidHandle) {
//    HIRICAMM invalidHandle = NULL; // Invalid handle
//    IddkDeviceInfo deviceInfo;
//    IddkResult result = Iddk_GetDeviceInfo(invalidHandle, &deviceInfo);
//    EXPECT_EQ(result, IDDK_INVALID_PARAMETER);
//}
//
//TEST_F(IddkGetDeviceInfoTest, NullDeviceInfoPointer) {
//    IddkResult result = Iddk_GetDeviceInfo(hDevice, NULL);
//    EXPECT_EQ(result, IDDK_INVALID_PARAMETER);
//}
//
//TEST_F(IddkGetDeviceInfoTest, DeviceIOFailed) {
//}