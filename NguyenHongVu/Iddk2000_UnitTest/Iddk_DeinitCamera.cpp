#include "pch.h"
#include "Iddk2000Apis.h"

//class IddkDeinitCameraTest : public ::testing::Test {
//protected:
//    HIRICAMM hDevice;
//
//    void SetUp() override {
//        hDevice = /* Assume this is a valid handle after opening and initializing */;
//        Iddk_InitCamera(hDevice, NULL, NULL);
//    }
//
//    void TearDown() override {
//        Iddk_DeinitCamera(hDevice);
//        Iddk_CloseDevice(hDevice); 
//    }
//};
//
//TEST_F(IddkDeinitCameraTest, ValidDeinit) {
//    IddkResult result = Iddk_DeinitCamera(hDevice);
//    EXPECT_EQ(result, IDDK_OK);
//}
//
//TEST_F(IddkDeinitCameraTest, InvalidHandle) {
//    HIRICAMM invalidHandle = NULL; // Invalid handle
//    IddkResult result = Iddk_DeinitCamera(invalidHandle);
//    EXPECT_EQ(result, IDDK_INVALID_PARAMETER);
//}
//
//TEST_F(IddkDeinitCameraTest, CameraNotInitialized) {
//    Iddk_DeinitCamera(hDevice); // First deinit
//    IddkResult result = Iddk_DeinitCamera(hDevice); // Try to deinit again
//    EXPECT_EQ(result, IDDK_SE_NOT_INIT);
//}