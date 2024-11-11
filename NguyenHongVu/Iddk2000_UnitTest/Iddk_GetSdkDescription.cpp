#include "pch.h"
#include "Iddk2000Apis.h"

class IddkDescriptionTest : public ::testing::Test {
protected:
    char buffer[256];
    int bufferSize;

    void SetUp() override {
        bufferSize = sizeof(buffer);
    }
};

TEST_F(IddkDescriptionTest, ValidBuffer) {
    IddkResult result = Iddk_GetSdkDescription(buffer, &bufferSize);

    EXPECT_EQ(result, IDDK_OK);
    EXPECT_GT(bufferSize, 0);
    EXPECT_LT(bufferSize, sizeof(buffer));
}

TEST_F(IddkDescriptionTest, NullBuffer) {
    IddkResult result = Iddk_GetSdkDescription(NULL, &bufferSize);

    EXPECT_EQ(result, IDDK_INVALID_PARAMETER);
}

TEST_F(IddkDescriptionTest, NullSize) {
    IddkResult result = Iddk_GetSdkDescription(buffer, NULL);

    EXPECT_EQ(result, IDDK_INVALID_PARAMETER);
}

TEST_F(IddkDescriptionTest, SmallBuffer) {
    char smallBuffer[10];
    int smallBufferSize = sizeof(smallBuffer);

    IddkResult result = Iddk_GetSdkDescription(smallBuffer, &smallBufferSize);

    EXPECT_EQ(result, IDDK_NOT_ENOUGH_BUFFER);
}