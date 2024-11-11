#include "pch.h"
#include "Iddk2000Apis.h"
//
//class IddkInitCameraTest : public ::testing::Test {
//protected:
//    HIRICAMM hDevice;
//
//    void SetUp() override {
//        hDevice = /* Assume this is a valid handle after opening */;
//    }
//
//    void TearDown() override {
//        if (hDevice != NULL) {
//            Iddk_DeinitCamera(hDevice);
//            Iddk_CloseDevice(hDevice);
//        }
//    }
//};
//
//TEST_F(IddkInitCameraTest, ValidInit) {
//    int nImageWidth = 0, nImageHeight = 0;
//    IddkResult result = Iddk_InitCamera(hDevice, &nImageWidth, &nImageHeight);
//
//    EXPECT_EQ(result, IDDK_OK);
//    EXPECT_GT(nImageWidth, 0); // Check that the width is positive
//    EXPECT_GT(nImageHeight, 0); // Check that the height is positive
//}
//
//TEST_F(IddkInitCameraTest, InvalidHandle) {
//    HIRICAMM invalidHandle = NULL; // Invalid handle
//    int nImageWidth = 0, nImageHeight = 0;
//
//    IddkResult result = Iddk_InitCamera(invalidHandle, &nImageWidth, &nImageHeight);
//    EXPECT_EQ(result, IDDK_INVALID_PARAMETER);
//}
//
//TEST_F(IddkInitCameraTest, MemoryAllocationFailed) {
//}